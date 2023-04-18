#include "Graphics.h"
#include "SDLCommon.h"

//add a guard that prevents multiple instances of the Window. (there should only be one!)

void Graphics::CreateWindow(const char* window_title, int window_width, int window_height, Vector4D window_color)
{
	_windowColor = window_color;
	
	_window = SDL_CreateWindow(window_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_width, window_height, SDL_WINDOW_SHOWN);
	if (_window == nullptr)
	{
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (_renderer == nullptr)
	{
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
	}

	SDL_SetRenderDrawColor(_renderer, window_color.h, window_color.i, window_color.j, window_color.k);
	std::cout << "SDL" << ": Successfully created window and renderer" << std::endl;
}

void Graphics::DestroyWindow()
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	std::cout << "SDL" << ": Destroyed window and renderer" << std::endl;
}

SDL_Texture* Graphics::LoadTexture(const char* filename)
{
	SDL_Surface* image = IMG_Load(filename);
	if (image == nullptr)
	{
		std::cout << "SDL IMG_Load Error: " << SDL_GetError() << std::endl;
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(_renderer, image);
	if (texture == nullptr)
	{
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
	}

	return texture;
}

void Graphics::DrawTexture(Box dstRect, SDL_Texture* texture)
{
	SDL_RenderCopy(Graphics::_renderer, texture, NULL, &SDLCommon::ConvertToSDLRect(dstRect));
}

void Graphics::DrawBox(Box dstRect, Vector4D color)
{
	SDL_SetRenderDrawColor(Graphics::_renderer, color.h, color.i, color.j, color.k);
	SDL_RenderDrawRect(Graphics::_renderer, &SDLCommon::ConvertToSDLRect(dstRect));
	SDL_SetRenderDrawColor(Graphics::_renderer, Graphics::_windowColor.h, Graphics::_windowColor.i, Graphics::_windowColor.j, Graphics::_windowColor.k);
}

void Graphics::DrawCircle(Circle dstCircle, Vector4D color)
{
	//midpoint circle algorithm
	//used by Microsoft for Windows
    
    SDL_Point points[(dstCircle.r * 8 * 35 / 49) + (8 - 1) & -8];
    int       drawCount = 0;

    const int32_t diameter = (dstCircle.r * 2);

    int32_t x = (dstCircle.r - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);

    while (x >= y)
    {
        // Each of the following renders an octant of the circle
        points[drawCount + 0] = { dstCircle.x + x, dstCircle.y - y };
        points[drawCount + 1] = { dstCircle.x + x, dstCircle.y + y };
        points[drawCount + 2] = { dstCircle.x - x, dstCircle.y - y };
        points[drawCount + 3] = { dstCircle.x - x, dstCircle.y + y };
        points[drawCount + 4] = { dstCircle.x + y, dstCircle.y - x };
        points[drawCount + 5] = { dstCircle.x + y, dstCircle.y + x };
        points[drawCount + 6] = { dstCircle.x - y, dstCircle.y - x };
        points[drawCount + 7] = { dstCircle.x - y, dstCircle.y + x };

        drawCount += 8;

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }

    SDL_RenderDrawPoints(Graphics::_renderer, points, drawCount);
}
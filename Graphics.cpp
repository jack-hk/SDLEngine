#include "Graphics.h"

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

void Graphics::DrawTexture(SDL_Rect dstRect, SDL_Texture* texture)
{
	SDL_RenderCopy(Graphics::_renderer, texture, NULL, &dstRect);
}

void Graphics::DrawBox(SDL_Rect dstRect, Vector4D color)
{
	SDL_SetRenderDrawColor(Graphics::_renderer, color.h, color.i, color.j, color.k);
	SDL_RenderDrawRect(Graphics::_renderer, &dstRect);
	SDL_SetRenderDrawColor(Graphics::_renderer, Graphics::_windowColor.h, Graphics::_windowColor.i, Graphics::_windowColor.j, Graphics::_windowColor.k);
}


void Graphics::DrawCircle(Circle dstCircle, Vector4D color)
{
	SDL_SetRenderDrawColor(Graphics::_renderer, color.h, color.i, color.j, color.k);

	// Midpoint circle algorithm.
	const int32_t diameter = (dstCircle.r * 2);

	int32_t x = (dstCircle.r - 1);
	int32_t y = 0;
	int32_t tx = 1;
	int32_t ty = 1;
	int32_t error = (tx - diameter);
	while (x >= y)
	{
		SDL_RenderDrawPoint(Graphics::_renderer, dstCircle.x + x, dstCircle.y - y);
		SDL_RenderDrawPoint(Graphics::_renderer, dstCircle.x + x, dstCircle.y + y);
		SDL_RenderDrawPoint(Graphics::_renderer, dstCircle.x - x, dstCircle.y - y);
		SDL_RenderDrawPoint(Graphics::_renderer, dstCircle.x - x, dstCircle.y + y);
		SDL_RenderDrawPoint(Graphics::_renderer, dstCircle.x + y, dstCircle.y - x);
		SDL_RenderDrawPoint(Graphics::_renderer, dstCircle.x + y, dstCircle.y + x);
		SDL_RenderDrawPoint(Graphics::_renderer, dstCircle.x - y, dstCircle.y - x);
		SDL_RenderDrawPoint(Graphics::_renderer, dstCircle.x - y, dstCircle.y + x);

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
	SDL_SetRenderDrawColor(Graphics::_renderer, Graphics::_windowColor.h, Graphics::_windowColor.i, Graphics::_windowColor.j, Graphics::_windowColor.k);
}
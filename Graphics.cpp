#include "Graphics.h"

void Graphics::UpdateGraphics(SDL_Renderer* renderer)
{
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

SDL_Texture* Graphics::LoadTexture(SDL_Renderer* renderer, const char* filename)
{
	//Load image
	SDL_Surface* image = IMG_Load(filename);
	if (image == nullptr)
	{
		std::cout << "SDL IMG_Load Error: " << SDL_GetError() << std::endl;
	}

	//Create texture
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
	if (texture == nullptr)
	{
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
	}

	return texture;
}
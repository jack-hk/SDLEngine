#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

class Graphics
{
public:
	void UpdateGraphics(SDL_Renderer* renderer);
	SDL_Texture* LoadTexture(SDL_Renderer* renderer, const char* filename);
};


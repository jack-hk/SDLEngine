#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

#include "VectorMath.h"

//Deals with visual updates
class Graphics
{
public:
	static inline SDL_Window* _window;
	static inline SDL_Renderer* _renderer;

	static void CreateWindow(const char* window_title, int window_width, int window_height, Vector4D window_color);
	static void DestroyWindow();
	static void UpdateGraphics(SDL_Renderer* renderer);
	SDL_Texture* LoadTexture(SDL_Renderer* renderer, const char* filename);
};


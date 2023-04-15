#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

#include "VectorMath.h"
#include "Shape.h"

//Deals with visual updates
class Graphics
{
public:
	static inline SDL_Window* _window;
	static inline SDL_Renderer* _renderer;
	static inline Vector4D _windowColor = Vector4D(30, 30, 30, SDL_ALPHA_OPAQUE);

	static void CreateWindow(const char* window_title, int window_width, int window_height, Vector4D window_color);
	static void DestroyWindow();
	static void UpdateGraphics();
	static SDL_Texture* LoadTexture(const char* filename);
	static void DrawTexture(Box dstRect, SDL_Texture* texture);
	static void DrawBox(Box dstRect, Vector4D color);
};
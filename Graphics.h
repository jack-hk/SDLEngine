#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

#include "Math.h"

// Deals with visual updates.
class Graphics
{
public:
	static inline SDL_Window* _window;
	static inline SDL_Renderer* _renderer;
	static inline Vector4D _windowColor = Vector4D(30, 30, 30, SDL_ALPHA_OPAQUE);

	static void CreateWindow(const char* window_title, int window_width, int window_height, Vector4D window_color);
	static void DestroyWindow();
	static SDL_Texture* LoadTexture(const char* filename);
	static void DrawTexture(SDL_Rect dstRect, SDL_Texture* texture);
	static void DrawBox(SDL_Rect dstRect, Vector4D color);
	static void DrawCircle(Circle dstCircle, Vector4D color);
};
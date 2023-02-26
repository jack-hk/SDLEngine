#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

#include "VectorMath.h"
#include "Graphics.h"

//Deals with gameloop and common game functions.
class Game
{
public:
	static inline SDL_Window* _window;
	static inline SDL_Renderer* _renderer;
	static inline Graphics _graphics;
	static inline bool _isRunning;

	static void Init();
	static void CreateWindow(const char *window_title, int window_width, int window_height, Vector4D window_color);
	static void DestroyWindow();
	static void Quit();
};


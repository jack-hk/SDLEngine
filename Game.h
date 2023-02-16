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
	bool _isRunning;
	Graphics _graphics;

	void Init();
	void CreateWindow(const char *window_title, int window_width, int window_height, Vector4D window_color);
	void DestroyWindow();
	void Quit();
	SDL_Window* GetWindow();
	SDL_Renderer* GetRenderer();
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

};


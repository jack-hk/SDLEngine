#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

struct Component
{
	bool _isEnabled = true;

	virtual void Update() = 0; //abstract 
};
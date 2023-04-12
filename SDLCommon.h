#pragma once
#include "Shape.h"

#include <SDL.h>
#include <SDL_image.h>

class SDLCommon
{
public:
	static Box ConvertToBox(SDL_Rect rect);
	static SDL_Rect ConvertToSDLRect(Box box);
};
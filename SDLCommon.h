#pragma once
#include "Shape.h"

#include <SDL.h>
#include <SDL_image.h>

//destroy class
class SDLCommon
{
public:
	static Box ConvertToBox(SDL_Rect rect);
	static SDL_Rect ConvertToSDLRect(Box box);
	static float DistanceSquared(int ax, int ay, int bx, int by);
};
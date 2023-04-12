#include "SDLCommon.h"

Box SDLCommon::ConvertToBox(SDL_Rect rect)
{
	Box box{};
	rect.x = box.x;
	rect.y = box.y;
	rect.w = box.w;
	rect.h = box.h;
	return box;
}

SDL_Rect SDLCommon::ConvertToSDLRect(Box box)
{
	SDL_Rect rect{};
	rect.x = box.x;
	rect.y = box.y;
	rect.w = box.w;
	rect.h = box.h;
	return rect;
}
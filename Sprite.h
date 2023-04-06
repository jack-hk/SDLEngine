#pragma once
#include "Component.h"

class Sprite : public Component
{
private:
	SDL_Texture* _texture = nullptr;
};
#pragma once
#include "Component.h"

class Sprite : public Component
{
	SDL_Texture* _texture = nullptr;
};


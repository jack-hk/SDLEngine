#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

#include "VectorMath.h"

class GameObject
{
	SDL_Texture* _texture = nullptr;
	Vector2D _position = Vector2D(0, 0);
	int _width = 32;
	int _height = 32;

	GameObject(Vector2D go_position, int go_width, int go_height, SDL_Texture* go_texture);
};


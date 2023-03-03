#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <vector>

#include "GameObject.h"

class Level 
{
	std::vector<GameObject*> _gameObjects;
};
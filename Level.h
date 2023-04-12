#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <vector>

#include "Game.h"
#include "GameObject.h"

class Level 
{
public:
	Level();
	void Update();
	void AddGameObject(GameObject* gameObject);

private:
	std::vector<GameObject*> _gameObjects;
};
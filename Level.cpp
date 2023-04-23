#include "Level.h"

Level::Level()
{
	Game::_levels.push_back(this);
}

void Level::Update()
{
	for (size_t i = 0; i < _gameObjects.size(); i++)
	{
		_gameObjects[i]->UpdateComponents();
	}
}

void Level::AddGameObject(GameObject* gameObjectToAdd)
{
	_gameObjects.push_back(gameObjectToAdd);
}

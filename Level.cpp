#include "Level.h"

Level::Level() 
{
	Game::_levels.push_back(this);
}

void Level::Update() 
{
	for (auto gameObject : _gameObjects) {
		gameObject->UpdateComponents();
	}
}

void Level::AddGameObject(GameObject* gameObjectToAdd)
{
	_gameObjects.push_back(gameObjectToAdd);
}

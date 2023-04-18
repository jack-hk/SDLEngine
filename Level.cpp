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
		if (_gameObjects[i]->GetComponent<BoxCollider>() != nullptr)
		{
			if (i + 1 < _gameObjects.size())
			if (Collision::AABB(_gameObjects[i]->GetComponent<BoxCollider>()->GetBodyBounds(), _gameObjects[i + 1]->GetComponent<BoxCollider>()->GetBodyBounds())) std::cout << "Collision" << std::endl;
		}
	}
}

void Level::AddGameObject(GameObject* gameObjectToAdd)
{
	_gameObjects.push_back(gameObjectToAdd);
}

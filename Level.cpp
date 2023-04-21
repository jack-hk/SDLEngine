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

		//checking collisions (move somewhere else later)
		if (_gameObjects[i]->GetComponent<BoxCollider>() != nullptr)
		{
			if (i + 1 < _gameObjects.size())
			if (Collision::AABB(_gameObjects[i]->GetComponent<BoxCollider>()->GetBodyBounds(), _gameObjects[i + 1]->GetComponent<BoxCollider>()->GetBodyBounds()))
				std::cout << "Collision" << std::endl;
			//std::functional
		}
		if (_gameObjects[i]->GetComponent<CircleCollider>() != nullptr)
		{
			if (i + 1 < _gameObjects.size())
				if (Collision::CircleToCircle(_gameObjects[i]->GetComponent<CircleCollider>()->GetBodyBounds(), _gameObjects[i + 1]->GetComponent<CircleCollider>()->GetBodyBounds())) std::cout << "Collision" << std::endl;
		}//_gameObjects[i]->GetComponent<CircleCollider>()->OnCollisionEntered
	}
}

void Level::AddGameObject(GameObject* gameObjectToAdd)
{
	_gameObjects.push_back(gameObjectToAdd);
}

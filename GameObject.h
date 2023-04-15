#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <vector>

#include "VectorMath.h"
#include "Shape.h"
#include "RectCollider.h"
#include "PhysicsBody.h"
#include "Sprite.h"

//Serves as a frame for components.
class GameObject
{
public:
	GameObject(Vector2D go_position, int go_size);

	//Destroys attached components.
	~GameObject();

	Vector2D GetPosition();
	int GetSize();
	void AddComponent(Component* componentToAdd);
	void UpdateComponents();

	template <typename T> T* GetComponent()
	{
		for (auto component : _components)
		{
			T* com = dynamic_cast<T*>(component);
			if (com != nullptr)
				return com;
		}
		return nullptr;
	}

private:
	Vector2D _position = Vector2D(0, 0);
	int _size = 32;

	std::vector<Component*> _components;
};
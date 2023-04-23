#pragma once
#include <SDL.h>
#include <vector>
#include <iostream>

#include "Component.h"
#include "Math.h"
#include "Sprite.h"

// Serves as a frame for components.
class GameObject
{
public:
	GameObject(Vector2D go_position, int go_size);
	~GameObject();

	inline Vector2D GetPosition() { return _position; }
	inline int GetSize() { return _size; }
	inline void Transform(Vector2D newPosition) { _position = newPosition; }
	
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
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <vector>

#include "VectorMath.h"
#include "RectCollider.h"
#include "PhysicsBody.h"
#include "Sprite.h"

class GameObject
{
public: //make private l8r
	Vector2D _position = Vector2D(0, 0);
	int _width = 32;
	int _height = 32;
	std::vector<Component*> _components;

	Sprite* _sprite = nullptr;
	RectCollider* _collider = nullptr;
	PhysicsBody* _physics = nullptr;

	GameObject(Vector2D go_position, int go_width, int go_height);

	void AddComponent(Component* componentToAdd);
	void UpdateComponents();
};


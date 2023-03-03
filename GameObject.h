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

//Serves as a frame for components.
struct GameObject
{
	Vector2D _position = Vector2D(0, 0);
	int _width = 32;
	int _height = 32;
	std::vector<Component*> _components;

	GameObject(Vector2D go_position, int go_width, int go_height);

	//Destroys attached components.
	~GameObject();

	void AddComponent(Component* componentToAdd);
	void UpdateComponents();
};


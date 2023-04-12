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
	GameObject(Vector2D go_position);

	//Destroys attached components.
	~GameObject();

	Vector2D GetPosition();

	Component* GetComponent(std::string name);
	void AddComponent(Component* componentToAdd);
	void UpdateComponents();

private:
	Vector2D _position = Vector2D(0, 0);

	std::vector<Component*> _components;
};
#include "GameObject.h"
#include "Sprite.h"

GameObject::GameObject(Vector2D go_position, int go_size)
{
	_position.x = go_position.x;
	_position.y = go_position.y;
	_size = go_size;
}

GameObject::~GameObject()
{
	for (auto component : _components)
	{
		delete component;
	}
}

Vector2D GameObject::GetPosition() { return _position; }

int GameObject::GetSize() { return _size; }

void GameObject::AddComponent(Component* componentToAdd)
{
	_components.push_back(componentToAdd);
}

void GameObject::UpdateComponents()
{
	for (auto component : _components)
	{
		component->Update();
	}
}


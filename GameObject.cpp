#include "GameObject.h"

GameObject::GameObject(Vector2D go_position, int go_width, int go_height)
{
	_position.x = go_position.x;
	_position.y = go_position.y;
	_width = go_width;
	_height = go_height;
}

void GameObject::AddComponent(Component* componentToAdd)
{
    _components.push_back(componentToAdd);
}

void GameObject::UpdateComponents()
{
	for (auto component : _components) {
		std::cout << component << std::endl;
		component->Update();
	}
}
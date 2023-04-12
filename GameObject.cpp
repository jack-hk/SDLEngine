#include "GameObject.h"

GameObject::GameObject(Vector2D go_position)
{
	_position.x = go_position.x;
	_position.y = go_position.y;
}

GameObject::~GameObject()
{
	for (auto component : _components) {
		delete component;
	}
}

Vector2D GameObject::GetPosition() { return _position; }

int GameObject::GetSize() { return _size; }

Component* GameObject::GetComponent(std::string name)
{
	//compares type, returns component with the matching name.
	for (size_t i = 0; i < _components.size(); i++)
	{
		if ("class " + name == typeid(*_components[i]).name()) return _components[i];
	}
	return nullptr;
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


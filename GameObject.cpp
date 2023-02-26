#include "GameObject.h"

GameObject::GameObject(Vector2D go_position, int go_width, int go_height)
{
	_position.x = go_position.x;
	_position.y = go_position.y;
	_width = go_width;
	_height = go_height;
}


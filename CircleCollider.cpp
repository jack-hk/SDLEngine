#include "CircleCollider.h"

CircleCollider::CircleCollider(GameObject* gameObject, Vector2D offset) : Component(gameObject)
{
	_body = Circle{
		(int)_gameObject->GetPosition().x + (int)offset.x,
		(int)_gameObject->GetPosition().y + (int)offset.y,
		(int)_gameObject->GetSize()
	};
	_colliderSize = _body.r;
	_colliderOffset = offset;
}

CircleCollider::CircleCollider(GameObject* gameObject, int newSize, Vector2D offset) : Component(gameObject)
{
	_body = Circle{
		(int)_gameObject->GetPosition().x + (int)offset.x,
		(int)_gameObject->GetPosition().y + (int)offset.y,
		(int)newSize,
	};
	_colliderSize = newSize;
	_colliderOffset = offset;
}

void CircleCollider::Update()
{
	_body = Circle{
		(int)_gameObject->GetPosition().x + (int)_colliderOffset.x,
		(int)_gameObject->GetPosition().y + (int)_colliderOffset.y,
		(int)_colliderSize,
	};
}
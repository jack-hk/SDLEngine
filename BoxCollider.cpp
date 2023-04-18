#include "BoxCollider.h"

BoxCollider::BoxCollider(GameObject* gameObject, Vector2D offset) : Component(gameObject)
{
	_body = Box{
		(int)_gameObject->GetPosition().x + (int)offset.x,
		(int)_gameObject->GetPosition().y + (int)offset.y,
		(int)_gameObject->GetSize(),
		(int)_gameObject->GetSize()
	};
	_colliderSize.x = _body.w;
	_colliderSize.y = _body.h;
	_colliderOffset = offset;
}

BoxCollider::BoxCollider(GameObject* gameObject, Vector2D newSize, Vector2D offset) : Component(gameObject)
{
	_body = Box{
		(int)_gameObject->GetPosition().x + (int)offset.x,
		(int)_gameObject->GetPosition().y + (int)offset.y,
		(int)newSize.x,
		(int)newSize.y
	};
	_colliderSize = newSize;
	_colliderOffset = offset;
}

void BoxCollider::Update()
{
	_body = Box{
	(int)_gameObject->GetPosition().x + (int)_colliderOffset.x,
	(int)_gameObject->GetPosition().y + (int)_colliderOffset.y,
	(int)_colliderSize.x,
	(int)_colliderSize.y
	};
}
#include "RectCollider.h"
#include "GameObject.h"

RectCollider::RectCollider(GameObject* gameObject) : Component(gameObject)
{
	_body = Box{
		(int)_gameObject->GetPosition().x + (int)_colliderOffset.x,
		(int)_gameObject->GetPosition().y + (int)_colliderOffset.y,
		(int)_gameObject->GetSize(),
		(int)_gameObject->GetSize()
	};
}

RectCollider::RectCollider(GameObject* gameObject, Vector2D newSize) : Component(gameObject)
{
	_body = Box{
		(int)_gameObject->GetPosition().x + (int)_colliderOffset.x,
		(int)_gameObject->GetPosition().y + (int)_colliderOffset.y,
		(int)newSize.x,
		(int)newSize.y
	};
}

void RectCollider::Update() 
{

}
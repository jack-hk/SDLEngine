#include "RectCollider.h"
#include "GameObject.h"

RectCollider::RectCollider(GameObject* gameObject) : Component(gameObject)
{
	_colliderPos = gameObject->GetPosition();
}

void RectCollider::Update() 
{

}
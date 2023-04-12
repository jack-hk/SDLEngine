#pragma once
#include "Component.h"
#include "Shape.h"
#include "VectorMath.h"

class RectCollider : public Component
{
public:
	RectCollider(GameObject* gameobject);
	void Update() override;

private:
	Vector2D _colliderPos = Vector2D(0, 0);
	Vector2D _size = Vector2D(32, 32);

	Box _body{ (int)_colliderPos.x, (int)_colliderPos.y, (int)_size.x, (int)_size.y };
};
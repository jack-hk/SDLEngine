#pragma once
#include "Component.h"
#include "Shape.h"
#include "VectorMath.h"

class RectCollider : public Component
{
public:
	RectCollider(GameObject* gameobject);
	RectCollider(GameObject* gameobject, Vector2D newSize);
	void Update() override;

private:
	Box _body;

	Vector2D _colliderOffset = Vector2D(0, 0);
	Vector2D _colliderSize = Vector2D(32, 32);
};
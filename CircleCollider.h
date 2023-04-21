#pragma once

#include "Component.h"
#include "Shape.h"
#include "VectorMath.h"

//Major dependinces
#include "GameObject.h"
#include "Collision.h"

class CircleCollider : public Component
{
public:
	CircleCollider(GameObject* gameobject, Vector2D offset = Vector2D(0, 0));
	CircleCollider(GameObject* gameobject, int newSize, Vector2D offset = Vector2D(0, 0));

	void Update() override;

	inline Circle GetBodyBounds() { return _body; }

private:
	Circle _body = Circle(0, 0, 0);

	int _colliderSize = 0;
	Vector2D _colliderOffset = Vector2D(0, 0);
};


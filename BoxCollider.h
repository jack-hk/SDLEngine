#pragma once

#include "Component.h"
#include "Shape.h"
#include "VectorMath.h"
#include "GameObject.h"
#include "SDLCommon.h"
#include "Collision.h"

class BoxCollider : public Component
{
public:
	BoxCollider(GameObject* gameobject, Vector2D offset = Vector2D(0, 0) );
	BoxCollider(GameObject* gameobject, Vector2D newSize, Vector2D offset = Vector2D(0, 0));
	
	void Update() override;

	inline Box GetBodyBounds() { return _body; }

private:
	Box _body = Box(0, 0, 0, 0);

	Vector2D _colliderSize = Vector2D(0, 0);
	Vector2D _colliderOffset = Vector2D(0, 0);
};
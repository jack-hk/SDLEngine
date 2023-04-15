#pragma once

#include "Component.h"
#include "Shape.h"
#include "VectorMath.h"
#include "Graphics.h"

class RectCollider : public Component
{
public:
	RectCollider(GameObject* gameobject, Vector2D offset = Vector2D(0, 0), bool isRenderedBounds = false, Vector4D renderedBoundsColor = Vector4D(255, 0, 0, 255) );
	RectCollider(GameObject* gameobject, Vector2D newSize, Vector2D offset = Vector2D(0, 0), bool isRenderedBounds = false, Vector4D renderedBoundsColor = Vector4D(255, 0, 0, 255));
	
	void Update() override;
private:
	Box _body;

	Vector2D _colliderSize = Vector2D(32, 32);
	
	Vector4D _renderedBoundsColor = Vector4D(255, 0, 0, 255);
	bool _isRenderedBounds = false;
};
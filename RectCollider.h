#pragma once

#include "Component.h"
#include "Shape.h"
#include "VectorMath.h"
#include "Graphics.h"
#include "GameObject.h"
#include "SDLCommon.h"
#include "Collision.h"

class RectCollider : public Component
{
public:
	RectCollider(GameObject* gameobject, Vector2D offset = Vector2D(0, 0) );
	RectCollider(GameObject* gameobject, Vector2D newSize, Vector2D offset = Vector2D(0, 0));
	
	void Update() override;

	inline Box GetBodyBounds() { return _body; }
	void SetRenderedBounds(bool isRenderedBounds, Vector4D renderedBoundsColor = Vector4D(255, 0, 0, SDL_ALPHA_OPAQUE));
private:
	Box _body = Box(0, 0, 0, 0);

	Vector2D _colliderSize = Vector2D(0, 0);
	Vector2D _colliderOffset = Vector2D(0, 0);
	
	Vector4D _renderedBoundsColor = Vector4D(255, 0, 0, SDL_ALPHA_OPAQUE);
	bool _isRenderedBounds = false;
};
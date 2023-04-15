#include "RectCollider.h"

RectCollider::RectCollider(GameObject* gameObject, Vector2D offset) : Component(gameObject)
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

RectCollider::RectCollider(GameObject* gameObject, Vector2D newSize, Vector2D offset) : Component(gameObject)
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

void RectCollider::Update() 
{
	_body = Box{
	(int)_gameObject->GetPosition().x + (int)_colliderOffset.x,
	(int)_gameObject->GetPosition().y + (int)_colliderOffset.y,
	(int)_colliderSize.x,
	(int)_colliderSize.y
	};
	if (_isRenderedBounds) Graphics::DrawBox(_body, _renderedBoundsColor);
}

void RectCollider::SetRenderedBounds(bool isRenderedBounds, Vector4D renderedBoundsColor)
{
	_isRenderedBounds = isRenderedBounds;
	_renderedBoundsColor = renderedBoundsColor;
}
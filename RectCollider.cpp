#include "RectCollider.h"
#include "GameObject.h"

RectCollider::RectCollider(GameObject* gameObject, bool isRenderedBounds, Vector4D renderedBoundsColor) : Component(gameObject)
{
	_body = Box{
		(int)_gameObject->GetPosition().x + (int)_colliderOffset.x,
		(int)_gameObject->GetPosition().y + (int)_colliderOffset.y,
		(int)_gameObject->GetSize(),
		(int)_gameObject->GetSize()
	};
	_isRenderedBounds = isRenderedBounds;
	_renderedBoundsColor = renderedBoundsColor;
}

RectCollider::RectCollider(GameObject* gameObject, Vector2D newSize, bool isRenderedBounds, Vector4D renderedBoundsColor) : Component(gameObject)
{
	_body = Box{
		(int)_gameObject->GetPosition().x + (int)_colliderOffset.x,
		(int)_gameObject->GetPosition().y + (int)_colliderOffset.y,
		(int)newSize.x,
		(int)newSize.y
	};
	_isRenderedBounds = isRenderedBounds;
	_renderedBoundsColor = renderedBoundsColor;
}

void RectCollider::Update() 
{
	if (_isRenderedBounds) Graphics::DrawBox(_body, _renderedBoundsColor);
}
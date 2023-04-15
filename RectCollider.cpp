#include "RectCollider.h"
#include "GameObject.h"

RectCollider::RectCollider(GameObject* gameObject, Vector2D offset, bool isRenderedBounds, Vector4D renderedBoundsColor) : Component(gameObject)
{
	_body = Box{
		(int)_gameObject->GetPosition().x + (int)offset.x,
		(int)_gameObject->GetPosition().y + (int)offset.y,
		(int)_gameObject->GetSize(),
		(int)_gameObject->GetSize()
	};
	_isRenderedBounds = isRenderedBounds;
	_renderedBoundsColor = renderedBoundsColor;
}

RectCollider::RectCollider(GameObject* gameObject, Vector2D newSize, Vector2D offset, bool isRenderedBounds, Vector4D renderedBoundsColor) : Component(gameObject)
{
	_body = Box{
		(int)_gameObject->GetPosition().x + (int)offset.x,
		(int)_gameObject->GetPosition().y + (int)offset.y,
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
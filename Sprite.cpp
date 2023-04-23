#include "Sprite.h"

Sprite::Sprite(GameObject* gameObject, SDL_Texture* texture) : Component(gameObject)
{
	_body = SDL_Rect{
			(int)_gameObject->GetPosition().x,
			(int)_gameObject->GetPosition().y,
			(int)_gameObject->GetSize(),
			(int)_gameObject->GetSize()
	};
	_texture = texture;
	_spriteSize.x = _body.w;
	_spriteSize.y = _body.h;
}

Sprite::Sprite(GameObject* gameObject, SDL_Texture* texture, Vector2D newSize, Vector2D offset) : Component(gameObject)
{
	_body = SDL_Rect{
			(int)_gameObject->GetPosition().x + (int)offset.x,
			(int)_gameObject->GetPosition().y + (int)offset.y,
			(int)newSize.x,
			(int)newSize.y
	};
	_texture = texture;
	_spriteSize = newSize;
	_spriteOffset = offset;
}

void Sprite::Update()
{
	_body = SDL_Rect{
			(int)_gameObject->GetPosition().x + (int)_spriteOffset.x,
			(int)_gameObject->GetPosition().y + (int)_spriteOffset.y,
			(int)_spriteSize.x,
			(int)_spriteSize.y
	};
	if (_isRendered) Graphics::DrawTexture(_body, _texture);
}

#include "Sprite.h"
#include "GameObject.h"
#include "Graphics.h"
#include "SDLCommon.h"

Sprite::Sprite(GameObject* gameObject, SDL_Texture* texture) : Component(gameObject)
{
	_body = Box {
			(int)_gameObject->GetPosition().x + (int)_textureOffset.x,
			(int)_gameObject->GetPosition().y + (int)_textureOffset.y,
			(int)_gameObject->GetSize(),
			(int)_gameObject->GetSize()
	};
	_texture = texture;
}

Sprite::Sprite(GameObject* gameObject, SDL_Texture* texture, Vector2D newSize) : Component(gameObject)
{
	_body = Box {
			(int)_gameObject->GetPosition().x + (int)_textureOffset.x,
			(int)_gameObject->GetPosition().y + (int)_textureOffset.y,
			(int)newSize.x,
			(int)newSize.y
	};
	_texture = texture;
}

void Sprite::Update()
{
	if (_isRendered) Graphics::DrawTexture(_body, _texture);
}

//think about moving this out, into Graphics, for further decoupling.

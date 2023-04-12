#include "Sprite.h"
#include "GameObject.h"
#include "Graphics.h"
#include "SDLCommon.h"

Sprite::Sprite(GameObject* gameObject, SDL_Texture* texture) : Component(gameObject)
{
	if (!_isRendered) return;
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
	if (!_isRendered) return;
	_body = Box {
			(int)_gameObject->GetPosition().x + (int)_textureOffset.x,
			(int)_gameObject->GetPosition().y + (int)_textureOffset.y,
			(int)newSize.x,
			(int)newSize.y
	};
	_texture = texture;
}

//change to inline
void Sprite::SetRendered(bool isRendered) { _isRendered = isRendered; }

void Sprite::Update()
{
	Draw(_body, _texture);
}

//think about moving this out, into Graphics, for further decoupling.
void Sprite::Draw(Box dstRect, SDL_Texture* texture)
{
	/*if (HasAnimation)
	{
		int currentFrameIndex = (int)(timeInAnimationState * animationSpeed) % animFrames;
		srcRect = { currentFrameIndex * animWidth, animState * animHeight, animWidth, animHeight };
	}*/

	SDL_RenderCopy(Graphics::_renderer, _texture, NULL, &SDLCommon::ConvertToSDLRect(dstRect));
}
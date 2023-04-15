#pragma once

#include "Component.h"
#include "Shape.h"
#include "VectorMath.h"
#include "Graphics.h"
#include "GameObject.h"
#include "SDLCommon.h"

class Sprite : public Component
{
public:
	Sprite(GameObject* gameObject, SDL_Texture* texture);
	Sprite(GameObject* gameObject, SDL_Texture* texture, Vector2D newSize, Vector2D offset = Vector2D(0, 0));

	void Update() override;

	inline void SetRendered(bool isRendered) { _isRendered = isRendered; }
private:
	SDL_Texture* _texture = nullptr;
	Box _body = Box(0, 0, 0, 0);

	Vector2D _spriteSize = Vector2D(0, 0);
	Vector2D _spriteOffset = Vector2D(0, 0);

	bool _isRendered = true;
	bool _isAnimated = false;

};
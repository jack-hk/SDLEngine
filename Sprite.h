#pragma once

#include "Component.h"
#include "GameObject.h"
#include "Graphics.h"
#include "Math.h"

class Sprite : public Component
{
public:
	Sprite(GameObject* gameObject, SDL_Texture* texture);
	Sprite(GameObject* gameObject, SDL_Texture* texture, Vector2D newSize, Vector2D offset = Vector2D(0, 0));

	void Update() override;

	inline void SetRendered(bool isRendered) { _isRendered = isRendered; }
private:
	bool _isRendered = true;
	
	SDL_Texture* _texture = nullptr;
	SDL_Rect _body = SDL_Rect(0, 0, 0, 0);

	Vector2D _spriteSize = Vector2D(0, 0);
	Vector2D _spriteOffset = Vector2D(0, 0);
};
#pragma once

//shame... wish these dependenices didn't exist
#include <SDL.h>
#include <SDL_image.h>

#include "Component.h"
#include "Shape.h"
#include "VectorMath.h"
#include "GameObject.h"

class Sprite : public Component
{
public:
	Sprite(GameObject* gameObject, SDL_Texture* texture);
	Sprite(GameObject* gameObject, SDL_Texture* texture, Vector2D newSize, Vector2D offset = Vector2D(0, 0));

	void Update() override;

	inline void SetRendered(bool isRendered) { _isRendered = isRendered; }
private:
	SDL_Texture* _texture = nullptr;
	Box _body;

	bool _isRendered = true;
	bool _isAnimated = false;

};
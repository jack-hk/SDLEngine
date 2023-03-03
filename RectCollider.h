#pragma once
#include "Component.h"

class RectCollider : public Component
{
public:
	RectCollider();
	virtual void Update();
private:
	SDL_Rect* _collider;
};


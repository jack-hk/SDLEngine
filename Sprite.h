#pragma once
#include "Component.h"
#include "Shape.h"
#include "VectorMath.h"

class Sprite : public Component
{
public:
	Sprite(GameObject* gameobject);
	void Update() override;

private:
	bool _isAnimated = false;
};
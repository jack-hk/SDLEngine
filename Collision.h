#pragma once

#include "Shape.h"
#include "SDLCommon.h"

//Contains collision logic only
class Collision
{
public:
	static bool AABB(const Box& rectA, const Box& rectB);
	static bool CircleToPoint(Circle a, Vector2D b);
	static bool CircleToCircle(Circle a, Circle b);
};
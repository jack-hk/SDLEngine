#pragma once

#include "Shape.h"

class Collision
{
public:
	static bool AABB(const Box& rectA, const Box& rectB);
	static bool CircleToPointCheck(Circle a, Circle b);
};
#pragma once

#include "Shape.h"

class Collision
{
public:
	static bool AABB(const Box& rectA, const Box& rectB);
	static bool CircleCheck(float xa, float ya, float xc, float yc, float r);
};
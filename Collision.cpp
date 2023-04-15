#include "Collision.h"

bool Collision::AABB(const Box& rectA, const Box& rectB)
{
	if (rectA.x + rectA.w >= rectB.x &&
		rectB.x + rectB.w >= rectA.x &&
		rectA.y + rectA.h >= rectB.y &&
		rectB.y + rectB.h >= rectA.y)
	{
		return true;
	}

	return false;
}
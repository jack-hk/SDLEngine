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

bool Collision::CircleCheck(float xa, float ya, float xc, float yc, float r)
{
	return ((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc)) < r * r;
}
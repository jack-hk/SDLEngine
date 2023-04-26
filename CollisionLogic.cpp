#include "CollisionLogic.h"

namespace ColSys
{
	bool CollisionLogic::AABB(Box a, Box b)
	{
		if (a.x < b.x + b.w &&
			a.x + a.w > b.x &&
			a.y < b.y + b.h &&
			a.y + a.h > b.y)
		{
			return true;
		}
		return false;
	}

	bool CollisionLogic::CircleToPoint(Circle a, Point b)
	{
		return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) < a.r * a.r;
	}

	bool CollisionLogic::CircleToCircle(Circle a, Circle b)
	{
		int totalRadiusSquared = a.r + b.r;
		totalRadiusSquared = totalRadiusSquared * totalRadiusSquared;

		if (DistanceSquared(a.x, a.y, b.x, b.y) < (totalRadiusSquared))
		{
			return true;
		}
		return false;
	}
}

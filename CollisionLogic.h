#pragma once
#include <algorithm>
#include <iostream>

#include "Collider.h"

namespace ColSys
{
	// Contains collision logic only.
	class CollisionLogic
	{
	public:
		bool AABB(Box a, Box b);
		bool CircleToPoint(Circle circleA, Point pointB);
		bool CircleToCircle(Circle a, Circle b);

		inline bool DistanceSquared(int ax, int ay, int bx, int by)
		{
			int deltaX = bx - ax;
			int deltaY = by - ay;
			return deltaX * deltaX + deltaY * deltaY;
		}
	};
}
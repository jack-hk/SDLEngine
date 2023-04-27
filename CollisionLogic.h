#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

#include "Shape.h"

// Contains collision logic only.
namespace ColSys
{
	class CollisionLogic
	{
	public:
		static bool AABB(Box a, Box b);
		static bool CircleToPoint(Circle circleA, Point pointB);
		static bool CircleToCircle(Circle a, Circle b);

		inline static bool DistanceSquared(int ax, int ay, int bx, int by)
		{
			int deltaX = bx - ax;
			int deltaY = by - ay;
			return deltaX * deltaX + deltaY * deltaY;
		}
	};
}
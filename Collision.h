#pragma once

// Contains collision logic only.
namespace ColSys
{
	struct Box
	{
		int x;
		int y;
		int w;
		int h;
	};
	
	struct Circle
	{
		int x;
		int y;
		int r;
	};

	struct Point
	{
		int x;
		int y;
	};

	class CollisionLogic
	{
	public:
		static bool AABB(Box boxA, Box boxB);
		static bool CircleToPoint(Circle circleA, Point pointB);
		static bool CircleToCircle(Circle circleA, Circle circleB);
		
		inline static bool DistanceSquared(int ax, int ay, int bx, int by)
		{
			int deltaX = bx - ax;
			int deltaY = by - ay;
			return deltaX * deltaX + deltaY * deltaY;
		}
	};
}

#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

#include "Shape.h"

namespace ColSys
{
	// Contains collision logic only.
	class CollisionLogic
	{
	public:
		/// <summary>
		/// Axis-Aligned Bounding Box collision detection check.
		/// </summary>
		/// <param name = 'a:'> Box A to be compared</param> 
		/// <param name = 'b:'> Box B to be compared</param> 
		static bool AABB(Box a, Box b);
		
		/// <summary>
		/// Circle to Point collision detection check.
		/// </summary>
		/// <param name = 'a:'> Circle A to be compared</param> 
		/// <param name = 'b:'> Point B to be compared</param> 
		static bool CircleToPoint(Circle a, Point b);
		
		/// <summary>
		/// Circle to Circle collision detection check.
		/// </summary>
		/// <param name = 'a:'> Circle A to be compared</param> 
		/// <param name = 'b:'> Circle B to be compared</param> 
		static bool CircleToCircle(Circle a, Circle b);

		/// <summary> 
		/// Mathematic function for checking the distance sqaured between two provided points.
		/// </summary>
        /// <param name = 'ax:'> Point A x position in the worldspace</param> 
		/// <param name = 'ay:'> Point A y position in the worldspace</param>
		/// <param name = 'bx:'> Point B x position in the worldspace</param>
		/// <param name = 'by:'> Point B y position in the worldspace</param>
		/// <returns> (bx - ax) * (bx - ax) + (by - ay) * (by - ay) </returns>
		inline static int DistanceSquared(int ax, int ay, int bx, int by)
		{
			int deltaX = bx - ax;
			int deltaY = by - ay;
			return (deltaX * deltaX) + (deltaY * deltaY);
		}
	};
}
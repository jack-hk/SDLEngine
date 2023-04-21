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

bool Collision::CircleToPointCheck(Circle a, Vector2D b)
{
	return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) < a.r * a.r;
}

bool Collision::CircleToCircle(Circle a, Circle b)
{
    //Calculate total radius squared
    int totalRadiusSquared = a.r + b.r;
    totalRadiusSquared = totalRadiusSquared * totalRadiusSquared;

    //If the distance between the centers of the circles is less than the sum of their radii
    if (SDLCommon::DistanceSquared(a.x, a.y, b.x, b.y) < (totalRadiusSquared))
    {
        //The circles have collided
        return true;
    }

    //If not
    return false;
}
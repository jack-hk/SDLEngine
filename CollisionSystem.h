#pragma once

#include "CollisionLogic.h"
#include "Collider.h"

namespace ColSys
{
	class CollisionSystem
	{
	public:
		static void Update()
		{
			// 2D For Loop which does not repeat.
			for (size_t y = 0; y < _boxColliders.size(); y++)
			{
				for (size_t x = y; x < _boxColliders.size(); x++)
				{
					if (x == y) continue;
					if (CollisionLogic::AABB(_boxColliders[x]->GetBody(), _boxColliders[y]->GetBody()))
					{
						std::cout << "Collided!" << std::endl;
					};
				}
			}
			for (size_t y = 0; y < _circleColliders.size(); y++)
			{
				for (size_t x = y; x < _circleColliders.size(); x++)
				{
					if (x == y) continue;
					if (CollisionLogic::CircleToCircle(_circleColliders[x]->GetBody(), _circleColliders[y]->GetBody()))
					{
						std::cout << "Collided!" << std::endl;
					};
				}
			}
		}
	};
}
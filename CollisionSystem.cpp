#include "CollisionSystem.h"

namespace ColSys
{
	void CollisionSystem::Update()
	{
		// 2D For Loop which does not repeat.
		for (size_t y = 0; y < ColSys::ColliderManager::_boxColliders.size(); y++)
		{
			for (size_t x = y; x < ColSys::ColliderManager::_boxColliders.size(); x++)
			{
				if (x == y) continue;
				if (CollisionLogic::AABB(ColSys::ColliderManager::_boxColliders[x]->GetBody(), ColSys::ColliderManager::_boxColliders[y]->GetBody()))
				{
					ColSys::ColliderManager::_boxColliders[x]->SetCollidingStatus(true);
					ColSys::ColliderManager::_boxColliders[y]->SetCollidingStatus(true);
					std::cout << "[ColSys]: Box Collision Detected!" << std::endl;
				}
				else
				{
					ColSys::ColliderManager::_boxColliders[x]->SetCollidingStatus(false);
					ColSys::ColliderManager::_boxColliders[y]->SetCollidingStatus(false);
				}
			}
		}
		for (size_t y = 0; y < ColSys::ColliderManager::_circleColliders.size(); y++)
		{
			for (size_t x = y; x < ColSys::ColliderManager::_circleColliders.size(); x++)
			{
				if (x == y) continue;
				if (CollisionLogic::CircleToCircle(ColSys::ColliderManager::_circleColliders[x]->GetBody(), ColSys::ColliderManager::_circleColliders[y]->GetBody()))
				{
					ColSys::ColliderManager::_circleColliders[x]->SetCollidingStatus(true);
					ColSys::ColliderManager::_circleColliders[y]->SetCollidingStatus(true);
					std::cout << "[ColSys]: Circle Collision Detected!" << std::endl;
				}
				else
				{
					ColSys::ColliderManager::_circleColliders[x]->SetCollidingStatus(false);
					ColSys::ColliderManager::_circleColliders[y]->SetCollidingStatus(false);
				}
			}
		}
	}
}


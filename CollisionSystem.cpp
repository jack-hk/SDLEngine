#include "CollisionSystem.h"

namespace ColSys
{
	void CollisionSystem::CreateBox(const char* name, int x, int y, int w, int h)
	{
		BoxCollider boxInstance{ name, x,y,w,h };
		ColSys::CollisionSystem::_boxColliders.push_back(&boxInstance);
		for (size_t i = 0; i < ColSys::CollisionSystem::_boxColliders.size(); i++)
		{
			std::cout << ColSys::CollisionSystem::_boxColliders[i]->GetName() << std::endl;
		}
	}

	void CollisionSystem::CreateCircle(const char* name, int x, int y, int r)
	{
		CircleCollider circleInstance{ name, x,y,r };
		ColSys::CollisionSystem::_circleColliders.push_back(&circleInstance);
	}

	BoxCollider* CollisionSystem::GetBox(const char* name)
	{
		for (size_t i = 0; i < ColSys::CollisionSystem::_boxColliders.size(); i++)
		{
			//std::cout << ColSys::CollisionSystem::_boxColliders[i]->GetName() << std::endl;
			if (ColSys::CollisionSystem::_boxColliders[i]->GetName() == name) return ColSys::CollisionSystem::_boxColliders[i];
		}
		return nullptr;
	}

	CircleCollider* CollisionSystem::GetCircle(const char* name)
	{
		for (size_t i = 0; i < ColSys::CollisionSystem::_circleColliders.size(); i++)
		{
			if (ColSys::CollisionSystem::_circleColliders[i]->GetName() == name) return ColSys::CollisionSystem::_circleColliders[i];
		}
		return nullptr;
	}

void CollisionSystem::Update()
{
		// 2D For Loop which does not repeat.
		for (size_t y = 0; y < ColSys::CollisionSystem::_boxColliders.size(); y++)
		{
			for (size_t x = y; x < ColSys::CollisionSystem::_boxColliders.size(); x++)
			{
				if (x == y) continue;
				if (CollisionSystem::_collisionLogic.AABB(ColSys::CollisionSystem::_boxColliders[x]->GetBody(), ColSys::CollisionSystem::_boxColliders[y]->GetBody()))
				{
					std::cout << "Collided!" << std::endl;
				}
			}
		}
		for (size_t y = 0; y < ColSys::CollisionSystem::_circleColliders.size(); y++)
		{
			for (size_t x = y; x < ColSys::CollisionSystem::_circleColliders.size(); x++)
			{
				if (x == y) continue;
				if (ColSys::CollisionSystem::_collisionLogic.CircleToCircle(ColSys::CollisionSystem::_circleColliders[x]->GetBody(), ColSys::CollisionSystem::_circleColliders[y]->GetBody()))
				{
					std::cout << "Collided!" << std::endl;
				};
			}
		}
	}
}
#pragma once
#include <vector>

#include "CollisionLogic.h"
#include "Collider.h"

namespace ColSys
{
	class CollisionSystem
	{
	public:
		CollisionLogic _collisionLogic;

		static inline std::vector<BoxCollider*> _boxColliders;
		static inline std::vector<CircleCollider*> _circleColliders;

		void CreateBox(const char* name, int x, int y, int w, int h);
		void CreateCircle(const char* name, int x, int y, int r);

		BoxCollider* GetBox(const char* name);
		CircleCollider* GetCircle(const char* name);
		
		// Call this in game loop.
		void Update();
	};
}
#pragma once
#include <vector>
#include <iostream>

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

	class Collider;
	static std::vector<Collider*> _colliders;

	class Collider
	{
	public:
		Collider()
		{
			_colliders.push_back(this);
		}

		virtual void Update() = 0;
		virtual void UpdatePosition(int x, int y) = 0;
		template <typename T> T GetBoundingBody();
	};

	class CollisionSystem
	{
	public:

		static void UpdateSystem()
		{
			for (auto collider : _colliders)
			{
				collider->Update();
			}
		}
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

	class BoxCollider : Collider
	{
	public:
		BoxCollider(int w, int h, int x = 0, int y = 0)
		{
			_boundingBody.w = w;
			_boundingBody.h = h;
			_boundingBody.x = x;
			_boundingBody.y = y;
		}

		void UpdatePosition(int x, int y)
		{
			_boundingBody.x = x;
			_boundingBody.y = y;
		}

		void Update()
		{
			for (size_t i = 0; i < _colliders.size(); i++)
			{
				if (i + 1 < _colliders.size())
				{
					if (CollisionLogic::AABB(_colliders[i]->GetBoundingBody<Box>(), _colliders[i + 1]->GetBoundingBody<Box>()))
					{
						std::cout << "Collided" << std::endl;
					}
				}
			}
		}

		template <typename T> T GetBoundingBody()
		{
			return _boundingBody;
		}

	private:
		Box _boundingBody = Box{ 0,0,32,32 };
	};

	class CircleCollider : Collider
	{
	public:
		CircleCollider(int r, int x = 0, int y = 0)
		{
			_boundingBody.x = x;
			_boundingBody.y = y;
			_boundingBody.r = r;
		}

		void UpdatePosition(int x, int y)
		{
			_boundingBody.x = x;
			_boundingBody.y = y;
		}

		void Update()
		{
			for (size_t i = 0; i < _colliders.size(); i++)
			{
				if (i + 1 < _colliders.size())
				{
					if (CollisionLogic::CircleToCircle(_colliders[i]->GetBoundingBody<Circle>(), _colliders[i + 1]->GetBoundingBody<Circle>()))
					{
						std::cout << "Collided" << std::endl;
					}
				}
			}
		}

		template <typename T> T GetBoundingBody()
		{
			return _boundingBody;
		}

	private:
		Circle _boundingBody = Circle{ 0,0,32 };
	};

}

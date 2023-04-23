#pragma once
#include <vector>
#include <algorithm>
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
		template <typename T> T GetBoundingBody(T x) { return x; }
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

	class BoxCollider : Collider
	{
	private:
		Box _boundingBody = Box{ 0,0,32,32 };
	public:
		BoxCollider(int x, int y, int w, int h)
		{
			_boundingBody.x = x;
			_boundingBody.y = y;
			_boundingBody.w = w;
			_boundingBody.h = h;
		}

		void UpdatePosition(int x, int y)
		{
			_boundingBody.x = x;
			_boundingBody.y = y;
		}

		void Update() override
		{
			for (size_t i = 0; i < _colliders.size(); i++)
			{
				// basically this is always turning 'collided...' maybe cus it's comparing it's self twice in the AABB check?? idk
				if (_colliders[i] == this) continue;
				if (CollisionLogic::AABB(_boundingBody, _colliders[i]->GetBoundingBody<Box>(_boundingBody)))
				{
					std::cout << "Collided:  " << _colliders[i] << std::endl;
				}
			}
		}
	};

	class CircleCollider : Collider
	{
	private:
		Circle _boundingBody = Circle{ 0,0,32 };
	public:
		CircleCollider( int x, int y, int r)
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

		void Update() override
		{
			for (size_t i = 0; i < _colliders.size(); i++)
			{
				if (_colliders[i] == this) continue;
				if (CollisionLogic::CircleToCircle(_boundingBody, _colliders[i]->GetBoundingBody<Circle>(_boundingBody)))
				{
					std::cout << "Collided:  " << _colliders[i] << std::endl;
				}
			}
		}
	};

}
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

	class BoxCollider;
	class CircleCollider;
	static std::vector<BoxCollider*> _boxColliders;
	static std::vector<CircleCollider*> _circleColliders;

	enum ColliderType { BOX, CIRCLE };

	class Collider
	{
	protected:
		ColliderType _type = BOX;
	public:
		virtual ColliderType GetType() = 0;
		virtual void UpdatePosition(int x, int y) = 0;
	};


	class BoxCollider : Collider
	{
	private:
		Box _boundingBody = Box{ 0,0,32,32 };
	public:
		BoxCollider(int x, int y, int w, int h) : Collider()
		{
			_boundingBody.x = x;
			_boundingBody.y = y;
			_boundingBody.w = w;
			_boundingBody.h = h;
			_type = BOX;
			_boxColliders.push_back(this);
		}

		inline ColliderType GetType() { return BOX; }
		inline Box GetBody() { return _boundingBody; }

		void UpdatePosition(int x, int y) override
		{
			_boundingBody.x = x;
			_boundingBody.y = y;
		}
	};

	class CircleCollider : Collider
	{
	private:
		Circle _boundingBody = Circle{ 0,0,32 };
	public:
		CircleCollider(int x, int y, int r) : Collider()
		{
			_boundingBody.x = x;
			_boundingBody.y = y;
			_boundingBody.r = r;
			_type = CIRCLE;
			_circleColliders.push_back(this);
		}

		inline ColliderType GetType() { return CIRCLE; }
		inline Circle GetBody() { return _boundingBody; }

		void UpdatePosition(int x, int y) override
		{
			_boundingBody.x = x;
			_boundingBody.y = y;
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
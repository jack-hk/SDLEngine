#pragma once
#include <vector>

#include "Shape.h"

namespace ColSys
{
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
}
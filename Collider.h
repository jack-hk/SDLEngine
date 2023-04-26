#pragma once

#include "Shape.h"

namespace ColSys
{
	enum ColliderType { BOX, CIRCLE };

	class Collider
	{
	protected:
		const char* _name = "New Collider";
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
		BoxCollider(const char* name, int x, int y, int w, int h) : Collider()
		{
			_name = name;
			_boundingBody.x = x;
			_boundingBody.y = y;
			_boundingBody.w = w;
			_boundingBody.h = h;
			_type = BOX;
		}
		inline const char* GetName() { return _name; }
		inline ColliderType GetType() { return BOX; }
		inline Box GetBody() { return _boundingBody; }

		inline void UpdatePosition(int x, int y) override
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
		CircleCollider(const char* name, int x, int y, int r) : Collider()
		{
			_name = name;
			_boundingBody.x = x;
			_boundingBody.y = y;
			_boundingBody.r = r;
			_type = CIRCLE;
		}
		inline const char* GetName() { return _name; }
		inline ColliderType GetType() { return CIRCLE; }
		inline Circle GetBody() { return _boundingBody; }

		inline void UpdatePosition(int x, int y) override
		{
			_boundingBody.x = x;
			_boundingBody.y = y;
		}
	};
}
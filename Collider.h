#pragma once
#include <vector>

#include "Shape.h"

namespace ColSys
{
	class BoxCollider;
	class CircleCollider;

	// Manages global colliders.
	class ColliderManager
	{
	public:
		/// <summary>
		/// Stores active box colliders.
		/// </summary>
		static inline std::vector<BoxCollider*> _boxColliders;

		/// <summary>
		/// Stores active circle colliders.
		/// </summary>
		static inline std::vector<CircleCollider*> _circleColliders;
	};

	/// <summary>
	/// The type of collider; later defined inside the corresponding constructors.
	/// </summary>
	enum ColliderType { BOX, CIRCLE };

	/// <summary>
	/// An abstract base class for collider objects. Use BoxCollider or CircleCollider.
	/// </summary>
	class Collider
	{
	protected:
		/// <summary>
		/// The type of the collider.
		/// </summary>
		ColliderType _type = BOX;

		/// <summary>
		/// Is the collider currently colliding with another object?
		/// </summary
		bool _isColliding = false;
	public:
		virtual ColliderType GetType() = 0;
		virtual void UpdatePosition(int x, int y) = 0;

		/// <summary>
		/// Returns if true, when the collider is actively colliding with another collider.
		/// </summary>
		/// <returns>_isColliding</returns>
		inline bool GetCollidingStatus() { return _isColliding; }

		/// <summary>
		/// Set the status of isColliding.
		/// </summary>
		/// <param name = 'status:'> Is the collider currenty colliding with another collider object?</param>
		inline void SetCollidingStatus(bool status) { _isColliding = status; }
	};

	// Box shaped bounding body.
	class BoxCollider : public Collider
	{
	private:
		/// <summary>
		/// The defined bounding body of the object.
		/// </summary>
		Box _boundingBody = Box{ 0,0,32,32 };
	public:
		/// <param name = 'x:'> Position in the worldspace</param> 
		/// <param name = 'y:'> Position in the worldspace</param> 
		/// <param name = 'w:'> Width of the box</param> 
		/// <param name = 'h:'> Height of the box</param> 
		inline BoxCollider(int x, int y, int w, int h) : Collider()
		{
			_boundingBody.x = x;
			_boundingBody.y = y;
			_boundingBody.w = w;
			_boundingBody.h = h;
			_type = BOX;
			ColSys::ColliderManager::_boxColliders.push_back(this);
		}

		/// <summary>
		/// Returns the type of collider.
		/// </summary>
		/// <returns>BOX</returns>
		inline ColliderType GetType() { return BOX; }

		/// <summary>
		/// Returns the bounding body of the collider.
		/// </summary>
		/// <returns>_boundingBody{x,y,w,h}</returns>
		inline Box GetBody() { return _boundingBody; }

		/// <param name = 'x:'> Position in the worldspace</param> 
		/// <param name = 'y:'> Position in the worldspace</param> 
		inline void UpdatePosition(int x, int y) override
		{
			_boundingBody.x = x;
			_boundingBody.y = y;
		}
	};

	// Circle shaped bounding body.
	class CircleCollider : public Collider
	{
	private:
		/// <summary>
		/// The defined bounding body of the object.
		/// </summary>
		Circle _boundingBody = Circle{ 0,0,32 };
	public:
		/// <param name = 'x:'> Position in the worldspace</param> 
		/// <param name = 'y:'> Position in the worldspace</param> 
		/// <param name = 'r:'> Radius of the circle</param> 
		inline CircleCollider(int x, int y, int r) : Collider()
		{
			_boundingBody.x = x;
			_boundingBody.y = y;
			_boundingBody.r = r;
			_type = CIRCLE;
			ColSys::ColliderManager::_circleColliders.push_back(this);
		}

		/// <summary>
		/// Returns the type of collider.
		/// </summary>
		/// <returns>CIRCLE</returns>
		inline ColliderType GetType() { return CIRCLE; }

		/// <summary>
		/// Returns the bounding body of the collider.
		/// </summary>
		/// <returns>_boundingBody{x,y,r}</returns>
		inline Circle GetBody() { return _boundingBody; }

		/// <summary>
		/// Updates the position of the collider in the worldspace.
		/// </summary>
		/// <param name = 'x:'> Position in the worldspace</param> 
		/// <param name = 'y:'> Position in the worldspace</param> 
		inline void UpdatePosition(int x, int y) override
		{
			_boundingBody.x = x;
			_boundingBody.y = y;
		}
	};
}
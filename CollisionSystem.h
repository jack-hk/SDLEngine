#pragma once

#include "CollisionLogic.h"
#include "Collider.h"

namespace ColSys
{
	// Contains main functions of CollisionSystem. Include and use this in your project.
	class CollisionSystem
	{
	public:
		
		/// <summary>
		/// Checks collision between colldiers. The main function of the CollisionSystem. 
		/// </summary>
		/// <example> This sample shows how to call the Update method.
		/// <code>
		/// #include "CollisionSystem.h"
		/// void YourGameloop()
		/// {
		///    ColSys::CollisionSystem::Update();
		/// }
		/// </code>
		/// </example>
		static void Update();
	};
}
#pragma once

namespace ColSys
{
	/// <param name = 'x:'> Position in the worldspace</param> 
	/// <param name = 'y:'> Position in the worldspace</param> 
	/// <param name = 'w:'> Width of the box</param> 
	/// <param name = 'h:'> Height of the box</param> 
	struct Box
	{
		int x;
		int y;
		int w;
		int h;
	};

	/// <param name = 'x:'> Position in the worldspace</param> 
	/// <param name = 'y:'> Position in the worldspace</param> 
	/// <param name = 'r:'> Radius of the circle</param> 
	struct Circle
	{
		int x;
		int y;
		int r;
	};

	/// <param name = 'x:'> Position in the worldspace</param> 
	/// <param name = 'y:'> Position in the worldspace</param> 
	struct Point
	{
		int x;
		int y;
	};
}
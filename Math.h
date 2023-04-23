#pragma once

struct Circle
{
	int x;
	int y;
	int r;
};

struct Vector2D
{
	int x;
	int y;

	Vector2D(int x, int y);

	Vector2D operator+(const Vector2D& v2)
	{
		return Vector2D(x + v2.x, y + v2.y);
	}
};

struct Vector4D
{
	int h;
	int i;
	int j;
	int k;

	Vector4D(int h, int i, int j, int k);
};
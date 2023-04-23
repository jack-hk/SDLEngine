#pragma once

struct Circle
{
	int x;
	int y;
	int r;
};

struct Vector2D
{
	float x;
	float y;

	Vector2D(float x, float y);

	Vector2D operator+(const Vector2D& v2)
	{
		return Vector2D(x + v2.x, y + v2.y);
	}
};

struct Vector4D
{
	float h;
	float i;
	float j;
	float k;

	Vector4D(float h, float i, float j, float k);
};
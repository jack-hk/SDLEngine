#pragma once

struct Vector2D
{
	float x;
	float y;

	Vector2D(float x, float y);

	Vector2D operator+(const Vector2D& v2)
	{
		return Vector2D(x + v2.x, y + v2.y);
	}

	Vector2D operator*(float scalar)
	{
		return Vector2D(x * scalar, y * scalar);
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
#include "VecOperations.h"
#include <cmath>

Vec3 cross(const Vec3& vec_0, const Vec3& vec_1)
{
	return Vec3
	(
		vec_0.y * vec_1.z - vec_1.y * vec_0.z,
		vec_0.z * vec_1.x - vec_1.z * vec_0.x,
		vec_0.x * vec_1.y - vec_1.x * vec_0.y
	);
}

Vec3 dot(const Vec3& vec_0, const Vec3& vec_1)
{
	return Vec3
	(
		vec_0.x * vec_1.x,
		vec_0.y * vec_1.y,
		vec_0.z * vec_1.z
	);
}

float cross(const Vec2& vec_0, const Vec2& vec_1)
{
	return vec_0.x * vec_1.y - vec_1.x * vec_0.y;
}

Vec2 dot(const Vec2& vec_0, const Vec2& vec_1)
{
	return Vec2
	(
		vec_0.x * vec_1.x,
		vec_0.y * vec_1.y
	);
}

Vec3 normalise(const Vec3& vec)
{
	float len = length(vec);
	if (len == 0)
		return Vec3();
	return Vec3(vec / len);
}

Vec2 normalise(const Vec2& vec)
{
	float len = length(vec);
	if (len == 0)
		return Vec2();
	return Vec2(vec / len);
}

float length(const Vec3& vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

float length(const Vec2& vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}
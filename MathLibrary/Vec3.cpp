#include "Vec3.h"
#include <cmath>

Vec3::Vec3(float x, float y, float z)
{
	setValues(x, y, z);
}

Vec3::Vec3(const Vec3& vec)
{
	setValues(vec.x, vec.y, vec.z);
}

Vec3::Vec3(Vec2 vec2, float z)
{
	setValues(vec2.x, vec2.y, z);
}

Vec3::Vec3(Vec2 vec2)
{
	setValues(vec2.x, vec2.y, 0);
}

Vec3::Vec3(float xyz)
{
	setValues(xyz, xyz, xyz);
}

Vec3::Vec3()
{
	setValues(0, 0, 0);
}

void Vec3::setValues(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vec3 operator+(const Vec3& vec_0, const Vec3& vec_1)
{
	return Vec3(vec_0.x + vec_1.x, vec_0.y + vec_1.y, vec_0.z + vec_1.z);
}

Vec3 operator+(const float& num, const Vec3& vec)
{
	return Vec3(num) + vec;
}

Vec3 operator+(const Vec3& vec, const float& num)
{
	return vec + Vec3(num);
}

Vec3 operator-(const Vec3& vec_0, const Vec3& vec_1)
{
	return vec_0 + -vec_1;
}

Vec3 operator-(const float& num, const Vec3& vec)
{
	return Vec3(num) - vec;
}

Vec3 operator-(const Vec3& vec, const float& num)
{
	return vec - Vec3(num);
}

Vec3 operator-(const Vec3& vec)
{
	return -1 * vec;
}

Vec3 operator*(const float& num, const Vec3& vec)
{
	return Vec3(vec.x * num, vec.y * num, vec.z * num);
}

Vec3 operator*(const Vec3& vec, const float& num)
{
	return num * vec;
}

Vec3 operator/(const Vec3& vec, const float& num)
{
	return Vec3(vec.x / num, vec.y / num, vec.z / num);
}

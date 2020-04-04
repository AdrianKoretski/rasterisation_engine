#include "Vec2.h"
#include "Vec3.h"
#include <cmath>

Vec2::Vec2(float x, float y)
{
	setValues(x, y);
}

Vec2::Vec2(const Vec2& vec)
{
	setValues(vec.x, vec.y);
}

Vec2::Vec2(const Vec3& vec)
{
	setValues(vec.x, vec.y);
}

Vec2::Vec2(float xy)
{
	setValues(xy, xy);
}

Vec2::Vec2()
{
	setValues(0, 0);
}

void Vec2::setValues(float x, float y)
{
	this->x = x;
	this->y = y;
}

Vec2 operator+(const Vec2& vec_0, const Vec2& vec_1)
{
	return Vec2(vec_0.x + vec_1.x, vec_0.y + vec_1.y);
}

Vec2 operator+(const float& num, const Vec2& vec)
{
	return Vec2(num) + vec;
}

Vec2 operator+(const Vec2& vec, const float& num)
{
	return vec + Vec2(num);
}

Vec2 operator-(const Vec2& vec_0, const Vec2& vec_1)
{
	return vec_0 + -vec_1;
}

Vec2 operator-(const float& num, const Vec2& vec)
{
	return Vec2(num) - vec;
}

Vec2 operator-(const Vec2& vec, const float& num)
{
	return vec - Vec2(num);
}

Vec2 operator-(const Vec2& vec)
{
	return -1 * vec;
}

Vec2 operator*(const float& num, const Vec2& vec)
{
	return Vec2(vec.x * num, vec.y * num);
}

Vec2 operator*(const Vec2& vec, const float& num)
{
	return num * vec;
}

Vec2 operator/(const Vec2& vec, const float& num)
{
	return Vec2(vec.x / num, vec.y / num);
}

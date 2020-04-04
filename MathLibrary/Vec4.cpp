#include "Vec4.h"
#include "Vec3.h"

Vec4::Vec4(float x, float y, float z, float w)
{
	setValues(x, y, z, w);
}

Vec4::Vec4(const Vec4& vec)
{
	setValues(vec.x, vec.y, vec.z, vec.w);
}

Vec4::Vec4(Vec3 vec3, float w)
{
	setValues(vec3.x, vec3.y, vec3.z, w);
}

Vec4::Vec4(Vec3 vec3)
{
	setValues(vec3.x, vec3.y, vec3.z, 0);
}

Vec4::Vec4(float xyzw)
{
	setValues(xyzw, xyzw, xyzw, xyzw);
}

Vec4::Vec4()
{
	setValues(0, 0, 0, 0);
}

void Vec4::setValues(float x, float y, float z, float w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vec4 operator+(const Vec4& vec_0, const Vec4& vec_1)
{
	return Vec4(vec_0.x + vec_1.x, vec_0.y + vec_1.y, vec_0.z + vec_1.z, vec_0.w + vec_1.w);
}

Vec4 operator+(const float& num, const Vec4& vec)
{
	return Vec4(num) + vec;
}

Vec4 operator+(const Vec4& vec, const float& num)
{
	return vec + Vec4(num);
}

Vec4 operator-(const Vec4& vec_0, const Vec4& vec_1)
{
	return vec_0 + -vec_1;
}

Vec4 operator-(const float& num, const Vec4& vec)
{
	return Vec4(num) - vec;
}

Vec4 operator-(const Vec4& vec, const float& num)
{
	return vec - Vec4(num);
}

Vec4 operator-(const Vec4& vec)
{
	return -1 * vec;
}

Vec4 operator*(const float& num, const Vec4& vec)
{
	return Vec4(vec.x * num, vec.y * num, vec.z * num, vec.w * num);
}

Vec4 operator*(const Vec4& vec, const float& num)
{
	return num * vec;
}

Vec4 operator/(const Vec4& vec, const float& num)
{
	return Vec4(vec.x / num, vec.y / num, vec.z / num, vec.w / num);
}

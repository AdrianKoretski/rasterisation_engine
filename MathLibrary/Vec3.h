#pragma once

#include "Vec2.h"

class Vec3
{
public:
	Vec3(float x, float y, float z);
	Vec3(const Vec3& vec);
	Vec3(Vec2 vec2, float z);
	Vec3(Vec2 vec2);
	Vec3(float xyz);
	Vec3();

	float x = 0;
	float y = 0;
	float z = 0;
private:
	void setValues(float x, float y, float z);
};

Vec3 operator+(const Vec3& vec_0, const Vec3& vec_1);
Vec3 operator+(const float& num, const Vec3& vec);
Vec3 operator+(const Vec3& vec, const float& num);
Vec3 operator-(const Vec3& vec_0, const Vec3& vec_1);
Vec3 operator-(const float& num, const Vec3& vec);
Vec3 operator-(const Vec3& vec, const float& num);
Vec3 operator-(const Vec3& vec);
Vec3 operator*(const float& num, const Vec3& vec);
Vec3 operator*(const Vec3& vec, const float& num);
Vec3 operator/(const Vec3& vec, const float& num);
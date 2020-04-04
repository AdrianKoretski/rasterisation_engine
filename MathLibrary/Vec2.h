#pragma once

class Vec3;
class Vec2
{
public:
	Vec2(float x, float y);
	Vec2(const Vec2& vec);
	Vec2(const Vec3& vec);
	Vec2(float xy);
	Vec2();

	float x = 0;
	float y = 0;
private:
	void setValues(float x, float y);
};

Vec2 operator+(const Vec2& vec_0, const Vec2& vec_1);
Vec2 operator+(const float& num, const Vec2& vec);
Vec2 operator+(const Vec2& vec, const float& num);
Vec2 operator-(const Vec2& vec_0, const Vec2& vec_1);
Vec2 operator-(const float& num, const Vec2& vec);
Vec2 operator-(const Vec2& vec, const float& num);
Vec2 operator-(const Vec2& vec);
Vec2 operator*(const float& num, const Vec2& vec);
Vec2 operator*(const Vec2& vec, const float& num);
Vec2 operator/(const Vec2& vec, const float& num);
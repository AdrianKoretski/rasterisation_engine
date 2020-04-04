#pragma once

class Vec3;
class Vec4
{
public:
	Vec4(float x, float y, float z, float w);
	Vec4(const Vec4& vec);
	Vec4(Vec3 vec3, float w);
	Vec4(Vec3 vec3);
	Vec4(float xyzw);
	Vec4();

	float x = 0;
	float y = 0;
	float z = 0;
	float w = 0;

private:
	void setValues(float x, float y, float z, float w);
};

Vec4 operator+(const Vec4& vec_0, const Vec4& vec_1);
Vec4 operator+(const float& num, const Vec4& vec);
Vec4 operator+(const Vec4& vec, const float& num);
Vec4 operator-(const Vec4& vec_0, const Vec4& vec_1);
Vec4 operator-(const float& num, const Vec4& vec);
Vec4 operator-(const Vec4& vec, const float& num);
Vec4 operator-(const Vec4& vec);
Vec4 operator*(const float& num, const Vec4& vec);
Vec4 operator*(const Vec4& vec, const float& num);
Vec4 operator/(const Vec4& vec, const float& num);
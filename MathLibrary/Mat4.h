#pragma once
#include <stdlib.h>

class Vec4;
class Mat4
{
public:
	Mat4(
		float a11, float a12, float a13, float a14,
		float a21, float a22, float a23, float a24,
		float a31, float a32, float a33, float a34,
		float a41, float a42, float a43, float a44
	);
	Mat4(float* value);
	Mat4(const Mat4& mat);
	Mat4();

	float value[16];
};

Mat4 operator+(const Mat4& mat_0, const Mat4& mat_1);
Mat4 operator+(const float& num, const Mat4& mat);
Mat4 operator+(const Mat4& mat, const float& num);
Mat4 operator-(const Mat4& mat_0, const Mat4& mat_1);
Mat4 operator-(const float& num, const Mat4& mat);
Mat4 operator-(const Mat4& mat, const float& num);
Mat4 operator-(const Mat4& mat);
Mat4 operator*(const Mat4& mat_0, const Mat4& mat_1);
Mat4 operator*(const float& num, const Mat4& mat);
Vec4 operator*(const Mat4& mat, const Vec4& vec);
Mat4 operator*(const Mat4& mat, const float& num);
Mat4 operator/(const Mat4& mat, const float& num);

Mat4 transpose(const Mat4& mat);
Mat4 inverse(const Mat4& mat);

float determinant3
(
	float a11, float a12, float a13,
	float a21, float a22, float a23,
	float a31, float a32, float a33
);
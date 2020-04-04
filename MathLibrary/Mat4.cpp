#include <cstring>
#include "Mat4.h"
#include "Vec4.h"

Mat4::Mat4(
	float a11, float a12, float a13, float a14,
	float a21, float a22, float a23, float a24,
	float a31, float a32, float a33, float a34,
	float a41, float a42, float a43, float a44
)
{
	value[0] = a11;
	value[1] = a12;
	value[2] = a13;
	value[3] = a14;
	value[4] = a21;
	value[5] = a22;
	value[6] = a23;
	value[7] = a24;
	value[8] = a31;
	value[9] = a32;
	value[10] = a33;
	value[11] = a34;
	value[12] = a41;
	value[13] = a42;
	value[14] = a43;
	value[15] = a44;
}

Mat4::Mat4(float* data)
{
	std::memcpy(value, data, 16 * sizeof(float));
}

Mat4::Mat4(const Mat4& mat)
{
	for (int i = 0; i < 16; i++)
		value[i] = mat.value[i];
}

Mat4::Mat4()
{
	for (int i = 0; i < 16; i++)
		value[i] = 0;
}

Mat4 operator*(const Mat4& mat_0, const Mat4& mat_1)
{
	Vec4 v0(mat_1.value[0], mat_1.value[4], mat_1.value[8], mat_1.value[12]);
	Vec4 v1(mat_1.value[1], mat_1.value[5], mat_1.value[9], mat_1.value[13]);
	Vec4 v2(mat_1.value[2], mat_1.value[6], mat_1.value[10], mat_1.value[14]);
	Vec4 v3(mat_1.value[3], mat_1.value[7], mat_1.value[11], mat_1.value[15]);

	Vec4 v_0 = mat_0 * v0;
	Vec4 v_4 = mat_0 * v1;
	Vec4 v_8 = mat_0 * v2;
	Vec4 v_12 = mat_0 * v3;

	return Mat4
	(
		v_0.x, v_4.x, v_8.x, v_12.x,
		v_0.y, v_4.y, v_8.y, v_12.y,
		v_0.z, v_4.z, v_8.z, v_12.z,
		v_0.w, v_4.w, v_8.w, v_12.w
	);
}

Vec4 operator*(const Mat4& mat, const Vec4& vec)
{
	return Vec4
	(
		mat.value[0] * vec.x + mat.value[1] * vec.y + mat.value[2] * vec.z + mat.value[3] * vec.w,
		mat.value[4] * vec.x + mat.value[5] * vec.y + mat.value[6] * vec.z + mat.value[7] * vec.w,
		mat.value[8] * vec.x + mat.value[9] * vec.y + mat.value[10] * vec.z + mat.value[11] * vec.w,
		mat.value[12] * vec.x + mat.value[13] * vec.y + mat.value[14] * vec.z + mat.value[15] * vec.w
	);
}

Mat4 operator*(const Mat4& mat, const float& num)
{
	Mat4 result(mat);
	for (int i = 0; i < 16; i++)
		result.value[i] *= num;
	return result;
}

Mat4 transpose(const Mat4& mat)
{
	return Mat4
	(
		mat.value[0], mat.value[4], mat.value[8], mat.value[12],
		mat.value[1], mat.value[5], mat.value[9], mat.value[13],
		mat.value[2], mat.value[6], mat.value[10], mat.value[14],
		mat.value[3], mat.value[7], mat.value[11], mat.value[15]
	);
}

Mat4 inverse(const Mat4& mat)
{
	float det = 1 / 
		(mat.value[0] * determinant3( mat.value[5], mat.value[6], mat.value[7], mat.value[9], mat.value[10], mat.value[11], mat.value[13], mat.value[14], mat.value[15]) - 
		mat.value[4] * determinant3( mat.value[1], mat.value[2], mat.value[3], mat.value[9], mat.value[10], mat.value[11], mat.value[13], mat.value[14], mat.value[15]) + 
		mat.value[8] * determinant3( mat.value[1], mat.value[2], mat.value[3], mat.value[5], mat.value[6], mat.value[7], mat.value[13], mat.value[14], mat.value[15]) - 
		mat.value[12] * determinant3( mat.value[1], mat.value[2], mat.value[3], mat.value[5], mat.value[6], mat.value[7], mat.value[9], mat.value[10], mat.value[11]));

	float value[16];

	value[0] = determinant3(mat.value[5], mat.value[6], mat.value[7], mat.value[9], mat.value[10], mat.value[11], mat.value[13], mat.value[14], mat.value[15]);
	value[1] = -determinant3(mat.value[4], mat.value[6], mat.value[7], mat.value[8], mat.value[10], mat.value[11], mat.value[12], mat.value[14], mat.value[15]);
	value[2] = determinant3(mat.value[4], mat.value[5], mat.value[7], mat.value[8], mat.value[9], mat.value[11], mat.value[12], mat.value[13], mat.value[15]);
	value[3] = -determinant3(mat.value[4], mat.value[5], mat.value[6], mat.value[8], mat.value[9], mat.value[10], mat.value[12], mat.value[13], mat.value[14]);

	value[4] = -determinant3(mat.value[1], mat.value[2], mat.value[3], mat.value[9], mat.value[10], mat.value[11], mat.value[13], mat.value[14], mat.value[15]);
	value[5] = determinant3(mat.value[0], mat.value[2], mat.value[3], mat.value[8], mat.value[10], mat.value[11], mat.value[12], mat.value[14], mat.value[15]);
	value[6] = -determinant3(mat.value[0], mat.value[1], mat.value[3], mat.value[8], mat.value[9], mat.value[11], mat.value[12], mat.value[13], mat.value[15]);
	value[7] = determinant3(mat.value[0], mat.value[1], mat.value[2], mat.value[8], mat.value[9], mat.value[10], mat.value[12], mat.value[13], mat.value[14]);

	value[8] = determinant3(mat.value[1], mat.value[2], mat.value[3], mat.value[5], mat.value[6], mat.value[7], mat.value[13], mat.value[14], mat.value[15]);
	value[9] = -determinant3(mat.value[0], mat.value[2], mat.value[3], mat.value[4], mat.value[6], mat.value[7], mat.value[12], mat.value[14], mat.value[15]);
	value[10] = determinant3(mat.value[0], mat.value[1], mat.value[3], mat.value[4], mat.value[5], mat.value[7], mat.value[12], mat.value[13], mat.value[15]);
	value[11] = -determinant3(mat.value[0], mat.value[1], mat.value[2], mat.value[4], mat.value[5], mat.value[6], mat.value[12], mat.value[13], mat.value[14]);

	value[12] = -determinant3(mat.value[1], mat.value[2], mat.value[3], mat.value[5], mat.value[6], mat.value[7], mat.value[9], mat.value[10], mat.value[11]);
	value[13] = determinant3(mat.value[0], mat.value[2], mat.value[3], mat.value[4], mat.value[6], mat.value[7], mat.value[8], mat.value[10], mat.value[11]);
	value[14] = -determinant3(mat.value[0], mat.value[1], mat.value[3], mat.value[4], mat.value[5], mat.value[7], mat.value[8], mat.value[9], mat.value[11]);
	value[15] = determinant3(mat.value[0], mat.value[1], mat.value[2], mat.value[4], mat.value[5], mat.value[6], mat.value[8], mat.value[9], mat.value[10]);

	Mat4 result(value);
	return transpose(result) * det;
}

float determinant3
(
	float a11, float a12, float a13,
	float a21, float a22, float a23,
	float a31, float a32, float a33
)
{
	return a11*a22*a33 + a12*a23*a31 + a13*a21*a32
		- a13*a22*a31 - a12*a21*a33 - a11*a23*a32;
}
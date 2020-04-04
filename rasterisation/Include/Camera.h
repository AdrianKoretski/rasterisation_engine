#pragma once

#include "Definitions.h"

class Camera
{
public:
	Camera();

	void setCamera(Vec3 position, Vec3 forward, Vec3 up);
	void setPerspective(float field_of_view, float aspect_ratio);
	void setFrustum(float left, float right, float top, float bottom);
	void setNearFarPlanes(float near, float far);

	Mat4 getViewPerspectiveMatrix();
private:
	void setPerspectiveMatrix();

	Vec3 m_position = Vec3(0, 0, 0);
	Vec3 m_side = Vec3(1, 0, 0);
	Vec3 m_up = Vec3(0, 1, 0);
	Vec3 m_forward = Vec3(0, 0, -1);

	float m_near_plane = -1;
	float m_far_plane = -3;
	float m_left = -1;
	float m_right = 1;
	float m_top = 1;
	float m_bottom = -1;

	Mat4 m_view_matrix;
	Mat4 m_perspective_matrix;
};


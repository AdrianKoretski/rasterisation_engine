#pragma once

#include "..///Definitions.h"

class Camera
{
public:
	Camera();

	void setCamera(v3f position, v3f forward, v3f up);
	void setAspectRatio(float aspect_ratio);
	void setFieldOfView(float field_of_view);
	void setNearFarPlanes(float near, float far);

	m4f getViewPerspectiveMatrix();
private:
	void setPerspectiveMatrix();

	v3f m_position = v3f(0, 0, 1);
	v3f m_forward = v3f(0, 0, -1);
	v3f m_up = v3f(0, 1, 0);

	float m_near_plane = -1;
	float m_far_plane = -2;

	float m_aspect_ratio = 16.f/9;

	float m_field_of_view = 130.0f;

	m4f m_view_matrix;
	m4f m_perspective_matrix;
};


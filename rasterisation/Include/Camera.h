#pragma once

#include "Definitions.h"

class Camera
{
public:
	Camera();

	void setCamera(v3f position, v3f forward, v3f up);
	void setPerspective(float field_of_view, float aspect_ratio);
	void setFrustum(float left, float right, float top, float bottom);
	void setNearFarPlanes(float near, float far);

	m4f getViewPerspectiveMatrix();
private:
	void setPerspectiveMatrix();

	v3f m_position = v3f(0, 0, 0);
	v3f m_side = v3f(1, 0, 0);
	v3f m_up = v3f(0, 1, 0);
	v3f m_forward = v3f(0, 0, -1);

	float m_near_plane = -1;
	float m_far_plane = -3;
	float m_left = -1;
	float m_right = 1;
	float m_top = 1;
	float m_bottom = -1;

	m4f m_view_matrix;
	m4f m_perspective_matrix;
};


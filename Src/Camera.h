#pragma once

#include "Definitions.h"

class Camera
{
public:
	Camera();

	void setCamera(v3f position, v3f forward, v3f up);
	void setAspectRatio(float aspect_ratio);
	void setFieldOfView(float field_of_view);
	void setOrthogonal();
	void setPerspective();
	void setNearFarPlanes(float near, float far);

	m4f getViewPerspectiveMatrix();
private:
	v3f m_position = v3f(0, 0, 1);
	v3f m_forward = v3f(0, 0, -1);
	v3f m_up = v3f(0, 1, 0);

	float m_near_plane = 0.01f;
	float m_far_plane = 100.0f;

	float m_aspect_ratio = 1.0f;
	bool m_is_orthogonal = false;

	float m_field_of_view = 90.0f;

	m4f m_view_matrix;
	m4f m_perspective_matrix;
};


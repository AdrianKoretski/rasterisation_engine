#include "Camera.h"
#include <iostream>

Camera::Camera()
{
	m_view_matrix = m4f(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, -1, 0,
		0, 0, 0, 1
	);

	m_perspective_matrix = glm::transpose(m4f(
		-1, 0, 0, 0,
		0, -1, 0, 0,
		0, 0, -3, -4,
		0, 0, 1, 0
	));
	setPerspectiveMatrix();
}

void Camera::setCamera(v3f position, v3f forward, v3f up)
{
	v3f z = -glm::normalize(forward);
	v3f x = glm::normalize(glm::cross(up, z));
	v3f y = glm::normalize(glm::cross(z, x));
	v3f p = position;

	m_view_matrix = m4f(
		x[0], y[0], z[0], p[0],
		x[1], y[1], z[1], p[1],
		x[2], y[2], z[2], p[2],
		0, 0, 0, 1
	);

	m_view_matrix = glm::inverse(glm::transpose(m_view_matrix));
}

void Camera::setAspectRatio(float aspect_ratio)
{
	m_aspect_ratio = aspect_ratio;
}

void Camera::setFieldOfView(float field_of_view)
{
	m_field_of_view = field_of_view;
}

void Camera::setNearFarPlanes(float near, float far)
{
	m_near_plane = near;
	m_far_plane = far;
}


m4f Camera::getViewPerspectiveMatrix()
{
	return m_perspective_matrix * m_view_matrix;
}

void Camera::setPerspectiveMatrix()
{
	float left_right = m_near_plane * tan(m_field_of_view * PI / 360);
	float top_bottom = left_right / m_aspect_ratio;
	m_perspective_matrix = glm::transpose(m4f(
		m_near_plane / left_right, 0, 0, 0,
		0, m_near_plane / top_bottom, 0, 0,
		0, 0, (m_far_plane + m_near_plane) / (m_near_plane - m_far_plane), 2 * m_far_plane * m_near_plane / (m_far_plane - m_near_plane),
		0, 0, 1, 0
	));
}
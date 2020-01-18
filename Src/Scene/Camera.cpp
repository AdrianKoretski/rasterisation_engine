#include "Camera.h"
#include <iostream>

Camera::Camera()
{
	setCamera(v3f(0), v3f(0, 0, -1), v3f(0, 1, 0));
	setPerspectiveMatrix();
}

void Camera::setFrustum(float left, float right, float top, float bottom)
{
	m_left = left;
	m_right = right;
	m_bottom = bottom;
	m_top = top;
	setPerspectiveMatrix();
}

void Camera::setCamera(v3f position, v3f forward, v3f up)
{
	m_forward = -glm::normalize(forward);
	m_side = glm::normalize(glm::cross(up, m_forward));
	m_up = glm::normalize(glm::cross(m_forward, m_side));
	m_position = position;

	m_view_matrix = m4f(
		m_side[0], m_up[0], m_forward[0], m_position[0],
		m_side[1], m_up[1], m_forward[1], m_position[1],
		m_side[2], m_up[2], m_forward[2], m_position[2],
		0, 0, 0, 1
	);

	m_view_matrix = glm::inverse(glm::transpose(m_view_matrix));
}

void Camera::setPerspective(float field_of_view, float aspect_ratio)
{
	m_left = m_near_plane * tan(field_of_view * PI / 360);
	m_right = -m_left;
	m_top = m_right / aspect_ratio;
	m_bottom = -m_top;
	setPerspectiveMatrix();
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
	m_perspective_matrix = glm::transpose(m4f(
		2 * m_near_plane / (m_right - m_left), 0, (m_left + m_right)/(m_left - m_right), 0,
		0, 2 * m_near_plane / (m_top - m_bottom), (m_bottom + m_top)/(m_bottom - m_top), 0,
		0, 0, (m_far_plane + m_near_plane)/(m_near_plane - m_far_plane), 2 * m_far_plane * m_near_plane / (m_far_plane - m_near_plane),
		0, 0, 1, 0
	));
}
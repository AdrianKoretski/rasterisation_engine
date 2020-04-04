#include "Camera.h"
#include <iostream>

Camera::Camera()
{
	setCamera(Vec3(0), Vec3(0, 0, -1), Vec3(0, 1, 0));
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

void Camera::setCamera(Vec3 position, Vec3 forward, Vec3 up)
{
	m_forward = -normalise(forward);
	m_side = normalise(cross(up, m_forward));
	m_up = normalise(cross(m_forward, m_side));
	m_position = position;

	m_view_matrix = Mat4(
		m_side.x, m_up.x, m_forward.x, m_position.x,
		m_side.y, m_up.y, m_forward.y, m_position.y,
		m_side.z, m_up.z, m_forward.z, m_position.z,
		0, 0, 0, 1
	);

	m_view_matrix = inverse((m_view_matrix));
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


Mat4 Camera::getViewPerspectiveMatrix()
{
	return m_perspective_matrix * m_view_matrix;
}

void Camera::setPerspectiveMatrix()
{
	m_perspective_matrix = (Mat4(
		2 * m_near_plane / (m_right - m_left), 0, (m_left + m_right)/(m_left - m_right), 0,
		0, 2 * m_near_plane / (m_top - m_bottom), (m_bottom + m_top)/(m_bottom - m_top), 0,
		0, 0, (m_far_plane + m_near_plane)/(m_near_plane - m_far_plane), 2 * m_far_plane * m_near_plane / (m_far_plane - m_near_plane),
		0, 0, 1, 0
	));
}
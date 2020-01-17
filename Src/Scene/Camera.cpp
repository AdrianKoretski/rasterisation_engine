#include "Camera.h"

Camera::Camera()
{
	m_view_matrix = m4f(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	);

	m_perspective_matrix = m4f(
		-9.f/16, 0, 0, 0,
		0, -1, 0, 0,
		0, 0, 0, 1,
		0, 0, 1, 0
	);
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

}

void Camera::setFieldOfView(float field_of_view)
{

}

void Camera::setOrthogonal()
{

}

void Camera::setPerspective()
{

}

void Camera::setNearFarPlanes(float near, float far)
{

}


m4f Camera::getViewPerspectiveMatrix()
{
	return m_perspective_matrix * m_view_matrix;
}
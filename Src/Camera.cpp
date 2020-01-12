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
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
		);
}

void Camera::setCamera(v3f position, v3f forward, v3f up)
{

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
	return m_view_matrix * m_perspective_matrix;
}
#include "Triangle.h"

Triangle::Triangle(float* v0, float* v1, float* v2)
{
	m_vertex[0] = v0;
	m_vertex[1] = v1;
	m_vertex[2] = v2;

	for (int i = 0; i < 3; i++)
	{
		m_lines[i].x = getNext(m_vertex[i])[0] - m_vertex[i][0];
		m_lines[i].y = getNext(m_vertex[i])[1] - m_vertex[i][1];

		if (m_lines[i].y < 0 || (m_lines[i].y == 0 && m_lines[i].x > 0))
			m_is_equal[i] = true;
		else
			m_is_equal[i] = false;
	}

}
float* Triangle::getVertex(uint index)
{
	return m_vertex[index];
}
float* Triangle::getNext(float* current)
{
	for (int i = 0; i < 3; i++)
		if (m_vertex[i] == current)
			return m_vertex[(i + 1) % 3];
	return NULL;
}
bool Triangle::isContained(float x, float y)
{
	for (int i = 0; i < 3; i++)
		if (!isOnCorrectSide(x, y, i))
			return false;
	return true;
}
bool Triangle::isOnCorrectSide(float x, float y, uint index)
{
	v2f vect(x - m_vertex[index][0], y - m_vertex[index][1]);
	float cross_product = cross(m_lines[index], vect);

	return cross_product > 0 || (cross_product == 0 && m_is_equal[index]);
}

float Triangle::interpolate(float x, float y, uint index)
{
	v2f* lines = new v2f[3];
	float* weights = new float[3];
	for (int i = 0; i < 3; i++)
		weights[(i + 2) % 3] = cross(v2f(m_vertex[i][0] - x, m_vertex[i][1] - y), m_lines[i]);
	float triangle_area = cross(m_lines[0], m_lines[1]);
	return (weights[0] * m_vertex[0][index] + weights[1] * m_vertex[1][index] + weights[2] * m_vertex[2][index]) / triangle_area;
}

v2f Triangle::getLine(uint index)
{
	return m_lines[index];
}

float Triangle::cross(v2f a, v2f b)
{
	return a.x * b.y - a.y * b.x;
}
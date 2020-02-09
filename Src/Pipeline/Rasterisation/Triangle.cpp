#include "Triangle.h"

Triangle::Triangle(float* v0, float* v1, float* v2)
{
	m_vertex[0] = v0;
	m_vertex[1] = v1;
	m_vertex[2] = v2;

	for (int i = 0; i < 3; i++)
	{
		m_clip_position[i] = v2f(m_vertex[i][0], m_vertex[i][1]);
		m_world_position[i] = v3f(m_clip_position[i], 1) / m_vertex[i][3];
	}

	for (int i = 0; i < 3; i++)
	{
		m_clip_vector[i] = m_clip_position[nxt(i)] - m_clip_position[i];
		m_world_vector[i] = m_world_position[nxt(i)] - m_world_position[i];

		if (m_clip_vector[i].y < 0 || (m_clip_vector[i].y == 0 && m_clip_vector[i].x > 0))
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
uint Triangle::nxt(uint current)
{
	return (current + 1) % 3;
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
	float cross_product = cross(m_clip_vector[index], vect);

	return cross_product > 0 || (cross_product == 0 && m_is_equal[index]);
}

float Triangle::interpolate(float x, float y, uint index)
{
	float* weights = new float[3];
	for (int i = 0; i < 3; i++)
		weights[(i + 2) % 3] = cross(v2f(m_vertex[i][0] - x, m_vertex[i][1] - y), m_clip_vector[i]);
	float triangle_area = cross(m_clip_vector[0], m_clip_vector[1]);
	float value = (weights[0] * m_vertex[0][index] + weights[1] * m_vertex[1][index] + weights[2] * m_vertex[2][index]) / triangle_area;
	delete[] weights;
	return value;
}

float Triangle::depth_correct_interpolate(float x, float y, uint index)
{
	float* weights = new float[3];
	for (int i = 0; i < 3; i++)
		weights[(i + 2) % 3] = cross(v2f(m_vertex[i][0] - x, m_vertex[i][1] - y), m_clip_vector[i]);
	float triangle_area = cross(m_clip_vector[0], m_clip_vector[1]);
	float value = (weights[0] * m_vertex[0][3] + weights[1] * m_vertex[1][3] + weights[2] * m_vertex[2][3]) / triangle_area;

	v3f p = v3f(x, y, 1) / value;
	triangle_area = glm::length(glm::cross(m_world_vector[0], m_world_vector[1]));
	for (int i = 0; i < 3; i++)
		weights[(i + 2) % 3] = glm::length(glm::cross(m_world_vector[i], p - m_world_position[i]));
	value = (weights[0] * m_vertex[0][index] + weights[1] * m_vertex[1][index] + weights[2] * m_vertex[2][index]) / triangle_area;
	delete[] weights;
	return value;
}

v2f Triangle::getVector(uint index)
{
	return m_clip_vector[index];
}

float Triangle::cross(v2f a, v2f b)
{
	return a.x * b.y - a.y * b.x;
}
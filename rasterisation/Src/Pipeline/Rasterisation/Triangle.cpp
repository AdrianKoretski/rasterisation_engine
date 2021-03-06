#include "Triangle.h"

Triangle::Triangle(float* v0, float* v1, float* v2)
{
	m_vertex[0] = v0;
	m_vertex[1] = v1;
	m_vertex[2] = v2;

	setupVectors();
	setupTieBreakers();
	setupPreCompute();
}

Vec2 Triangle::getCSPosition(uint index)
{
	return m_CS_position[index];
}

uint Triangle::next(uint current)
{
	return (current + 1) % 3;
}

void Triangle::setupTieBreakers()
{
	for (int i = 0; i < 3; i++)
	{
		if (m_CS_vector[i].y < 0 || (m_CS_vector[i].y == 0 && m_CS_vector[i].x > 0))
			m_tie_breaker[i] = true;
		else
			m_tie_breaker[i] = false;
	}
}

void Triangle::setupPreCompute()
{
	float triangle_area = cross(m_CS_vector[0], m_CS_vector[1]);
	for (int i = 0; i < 3; i++)
		m_CS_pre_weight[i] = m_CS_vector[i] / triangle_area;
	triangle_area = cross(m_WS_vector[0], m_WS_vector[1]);
	for (int i = 0; i < 3; i++)
		m_WS_pre_weight[i] = m_WS_vector[i] / triangle_area;
}

void Triangle::setupVectors()
{
	for (int i = 0; i < 3; i++)
	{
		m_CS_position[i] = Vec2(m_vertex[i][0], m_vertex[i][1]);
		m_WS_position[i] = Vec3(m_CS_position[i], 1) / m_vertex[i][3];
	}

	for (int i = 0; i < 3; i++)
	{
		m_CS_vector[i] = m_CS_position[next(i)] - m_CS_position[i];
		m_WS_vector[i] = m_WS_position[next(i)] - m_WS_position[i];
	}
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
	Vec2 vect(x - m_CS_position[index].x, y - m_CS_position[index].y);
	float cross_product = cross(m_CS_vector[index], vect);

	return cross_product > 0 || (cross_product == 0 && m_tie_breaker[index]);
}

float Triangle::interpolate(float x, float y, uint index)
{
	Vec2 CS_p = Vec2(x, y);
	float value = 0;

	for (int i = 0; i < 3; i++)
		value += m_vertex[i][index] * cross(m_CS_position[next(i)] - CS_p, m_CS_pre_weight[next(i)]);

	return value;
}

void Triangle::depth_correct_interpolate(float* data, uint size)
{
	Vec2 CS_p = Vec2(data[0], data[1]);
	Vec3 WS_p = Vec3(CS_p, 1);
	float weights[3];
	float value = 0;

	data[2] = interpolate(CS_p.x, CS_p.y, 2);
	data[3] = interpolate(CS_p.x, CS_p.y, 3);

	WS_p = WS_p / data[3];


	for (int i = 0; i < 3; i++)
		weights[i] = (cross(m_WS_pre_weight[next(i)], WS_p - m_WS_position[next(i)]));
	for (int i = 4; i < size; i++)
		data[i] = m_vertex[0][i] * weights[0] + m_vertex[1][i] * weights[1] + m_vertex[2][i] * weights[2];
}

Vec2 Triangle::getVector(uint index)
{
	return m_CS_vector[index];
}

float Triangle::cross(Vec2 a, Vec2 b)
{
	return a.x * b.y - a.y * b.x;
}
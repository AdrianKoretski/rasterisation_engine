#pragma once

#include "..//..//Definitions.h"

class Triangle
{
public:
	Triangle(float* v0, float* v1, float* v2);
	v2f getCSPosition(uint index);
	v2f getVector(uint index);
	bool isContained(float x, float y);
	bool isOnCorrectSide(float x, float y, uint index);
	float interpolate(float x, float y, uint index);
	void depth_correct_interpolate(float* data, uint size);
	uint next(uint current);
private:
	void setupTieBreakers();
	void setupPreCompute();
	void setupVectors();

	float* m_vertex[3];

	v2f m_CS_position[3];
	v2f m_CS_vector[3];
	v3f m_WS_position[3];
	v3f m_WS_vector[3];

	v2f m_CS_pre_weight[3];
	v3f m_WS_pre_weight[3];

	bool m_tie_breaker[3];

	float cross(v2f a, v2f b);
};


#pragma once

#include "Definitions.h"

class Triangle
{
public:
	Triangle(float* v0, float* v1, float* v2);
	Vec2 getCSPosition(uint index);
	Vec2 getVector(uint index);
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

	Vec2 m_CS_position[3];
	Vec2 m_CS_vector[3];
	Vec3 m_WS_position[3];
	Vec3 m_WS_vector[3];

	Vec2 m_CS_pre_weight[3];
	Vec3 m_WS_pre_weight[3];

	bool m_tie_breaker[3];

	float cross(Vec2 a, Vec2 b);
};


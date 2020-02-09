#pragma once

#include "..//..//Definitions.h"

class Triangle
{
public:
	Triangle(float* v0, float* v1, float* v2);
	float* getVertex(uint index);
	v2f getVector(uint index);
	float* getNext(float* current);
	uint nxt(uint current);
	bool isContained(float x, float y);
	bool isOnCorrectSide(float x, float y, uint index);
	float interpolate(float x, float y, uint index);
	float depth_correct_interpolate(float x, float y, uint index);
private:
	float** m_vertex = new float* [3];

	v2f* m_clip_position = new v2f[3];
	v2f* m_clip_vector = new v2f[3];
	v3f* m_world_position = new v3f[3];
	v3f* m_world_vector = new v3f[3];

	v2f* m_lines = new v2f[3];
	bool* m_is_equal = new bool[3];

	float cross(v2f a, v2f b);
};


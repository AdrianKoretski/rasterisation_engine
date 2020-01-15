#pragma once

#include "..//..//Definitions.h"

class Triangle
{
public:
	Triangle(float* v0, float* v1, float* v2);
	float* getVertex(uint index);
	v2f getLine(uint index);
	float* getNext(float* current);
	bool isContained(float x, float y);
	bool isOnCorrectSide(float x, float y, uint index);
	float interpolate(float x, float y, uint index);
private:
	float** m_vertex = new float* [3];
	v2f* m_lines = new v2f[3];
	bool* m_is_equal = new bool[3];

	float cross(v2f a, v2f b);
};


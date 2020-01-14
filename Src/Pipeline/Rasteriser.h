#pragma once

#include "..//Definitions.h"
#include <iostream>

struct Triangle
{
	float** vertex = new float*[3];
	v2f* lines = new v2f[3];
	bool* isEqual = new bool[3];
	Triangle(float* v0, float* v1, float* v2)
	{
		vertex[0] = v0;
		vertex[1] = v1;
		vertex[2] = v2;

		for (int i = 0; i < 3; i++)
		{
			lines[i].x = getNext(vertex[i])[0] - vertex[i][0];
			lines[i].y = getNext(vertex[i])[1] - vertex[i][1];
			if (lines[i].y < 0 || (lines[i].y == 0 && lines[i].x > 0))
				isEqual[i] = true;
			else
				isEqual[i] = false;
		}
	}
	float* getNext(float* current)
	{
		for (int i = 0; i < 3; i++)
			if (vertex[i] == current)
				return vertex[(i + 1) % 3];
		return NULL;
	}
	bool isContained(float x, float y)
	{
		for (int i = 0; i < 3; i++)
			if (!isOnCorrectSide(x, y, i))
				return false;
		return true;
	}
	bool isOnCorrectSide(float x, float y, unsigned int index)
	{
		v2f vect(x - vertex[index][0], y - vertex[index][1]);

		return lines[index].x * vect.y - lines[index].y * vect.x > 0 || (lines[index].x * vect.y - lines[index].y * vect.x == 0 && isEqual[index]);
	}
};

class Rasteriser
{
public:
	Rasteriser(unsigned int width_resolution, unsigned int height_resolution);
	void rasterise(buffer<float>& output_fragments, float* vertex_0, float* vertex_1, float* vertex_2);
private:
	unsigned int m_fragment_size = 7;
	bool isCCW(float* vertex_0, float* vertex_1, float* vertex_2);
	float* getBottomRightVertex(Triangle triangle);

	void fillTriangle(buffer<float>& output_fragments, buffer<float>& rightmost_fragments, Triangle triangle);

	unsigned int m_width_resolution;
	unsigned int m_height_resolution;
};


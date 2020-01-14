#include "Rasteriser.h"
#include <iostream>
#include <random>

Rasteriser::Rasteriser(unsigned int width_resolution, unsigned int height_resolution)
{
	m_width_resolution = width_resolution;
	m_height_resolution = height_resolution;
}

void Rasteriser::rasterise(buffer<float>& output_fragments, float* vertex_0, float* vertex_1, float* vertex_2)
{
	if (!isCCW(vertex_0, vertex_1, vertex_2))
		return;
	Triangle triangle(vertex_0, vertex_1, vertex_2);

	buffer<float> storage_fragments;

	for (int i = 0; i < 3; i++)
	{
		float* current_vertex = triangle.vertex[i];
		v2f position(ceil(current_vertex[0]) + 0.5f, floor(current_vertex[1]) + 0.5f);

		while (position.y <= triangle.getNext(current_vertex)[1])
		{
			while (!triangle.isOnCorrectSide(position.x, position.y, i))
				position.x -= 1;
			while (triangle.isOnCorrectSide(position.x + 1, position.y, i))
				position.x += 1;

			storage_fragments.push_back(position.x);
			storage_fragments.push_back(position.y);
			position.y += 1;
		}
	}
	fillTriangle(output_fragments, storage_fragments, triangle);
}

bool Rasteriser::isCCW(float* vertex_0, float* vertex_1, float* vertex_2)
{
	v3f p0(vertex_0[0], vertex_0[1], 0);
	v3f v1 = v3f(vertex_1[0], vertex_1[1], 0) - p0;
	v3f v2 = v3f(vertex_2[0], vertex_2[1], 0) - p0;
	if (glm::cross(v1, v2).z <= 0)
		return false;
	return true;
}

float* Rasteriser::getBottomRightVertex(Triangle triangle)
{
	float* bottom_right = triangle.vertex[0];
	if (bottom_right[1] > triangle.vertex[1][1]
		|| (bottom_right[1] == triangle.vertex[1][1] && bottom_right[0] < triangle.vertex[1][0]))
		bottom_right = triangle.vertex[1];
	if (bottom_right[1] > triangle.vertex[2][1]
		|| (bottom_right[1] == triangle.vertex[2][1] && bottom_right[0] < triangle.vertex[2][0]))
		bottom_right = triangle.vertex[2];
	return bottom_right;
}

void Rasteriser::fillTriangle(buffer<float>& output_fragments, buffer<float>& rightmost_fragments, Triangle triangle)
{
	for (int i = 0; i < rightmost_fragments.size(); i += 2)
	{
		float x = rightmost_fragments[i + 0];
		float y = rightmost_fragments[i + 1];
		while (triangle.isContained(x, y))
		{
			int index = rand() % 3;
			output_fragments.push_back(x);
			output_fragments.push_back(y);
			for (int j = 2; j < m_fragment_size; j++)
				output_fragments.push_back((triangle.vertex[0][j]+ triangle.vertex[1][j]+ triangle.vertex[2][j])/3);
			x -= 1;
		}
	}
}

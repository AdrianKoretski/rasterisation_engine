#include "Rasteriser.h"
#include <iostream>
#include <random>

Rasteriser::Rasteriser()
{
	setIODataSize();
	setupUniforms();
}

void Rasteriser::setup() {
}

void Rasteriser::reset() {
}

void Rasteriser::rasterise(buffer<float>& output_fragments, float* vertex_0, float* vertex_1, float* vertex_2)
{
	if (!isCCW(vertex_0, vertex_1, vertex_2))
		return;
	Triangle triangle(vertex_0, vertex_1, vertex_2);

	buffer<float> storage_fragments;

	for (int i = 0; i < 3; i++)
	{
		Vec2 curr_position = triangle.getCSPosition(i);
		if (triangle.getVector(i).y <= 0)
			continue;
		Vec2 position(ceil(curr_position.x) + 0.5f, floor(curr_position.y) + 0.5f);

		while (position.y <= triangle.getCSPosition(triangle.next(i)).y)
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
	Vec3 p0(vertex_0[0], vertex_0[1], 0);
	Vec3 v1 = Vec3(vertex_1[0], vertex_1[1], 0) - p0;
	Vec3 v2 = Vec3(vertex_2[0], vertex_2[1], 0) - p0;
	if (cross(v1, v2).z <= 0)
		return false;
	return true;
}

void Rasteriser::setIODataSize()
{
	m_input_data_size = 12;
	m_output_data_size = 12;
}

void Rasteriser::setupUniforms()
{
}

void Rasteriser::fillTriangle(buffer<float>& output_fragments, buffer<float>& rightmost_fragments, Triangle triangle)
{
	uint index;
	float x;
	float y;
	for (uint i = 0; i < rightmost_fragments.size(); i += 2)
	{
		x = rightmost_fragments[i + 0];
		y = rightmost_fragments[i + 1];
		while (triangle.isContained(x, y))
		{
			index = output_fragments.size();
			output_fragments.resize(output_fragments.size() + m_output_data_size);
			output_fragments[index + 0] = x;
			output_fragments[index + 1] = y;
			triangle.depth_correct_interpolate(&output_fragments[index], m_output_data_size);
			x -= 1;
		}
	}
}

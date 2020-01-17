#pragma once

#include "..//..//Definitions.h"
#include "Triangle.h"

#include <iostream>


class Rasteriser
{
public:
	Rasteriser(uint width_resolution, uint height_resolution);
	void rasterise(buffer<float>& output_fragments, float* vertex_0, float* vertex_1, float* vertex_2);
private:
	uint m_fragment_size = 7;
	bool isCCW(float* vertex_0, float* vertex_1, float* vertex_2);

	void fillTriangle(buffer<float>& output_fragments, buffer<float>& rightmost_fragments, Triangle triangle);

	uint m_width_resolution;
	uint m_height_resolution;
};


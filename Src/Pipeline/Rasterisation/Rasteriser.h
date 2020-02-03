#pragma once

#include "..//..//Definitions.h"
#include "..//Uniform.h"
#include "Triangle.h"

#include <iostream>


class Rasteriser : public Uniform
{
public:
	Rasteriser();
	void rasterise(buffer<float>& output_fragments, float* vertex_0, float* vertex_1, float* vertex_2);
private:
	uint m_fragment_size = 7;
	bool isCCW(float* vertex_0, float* vertex_1, float* vertex_2);
	void setIOFragmentSizes();
	void setupUniforms();

	void fillTriangle(buffer<float>& output_fragments, buffer<float>& rightmost_fragments, Triangle triangle);
};
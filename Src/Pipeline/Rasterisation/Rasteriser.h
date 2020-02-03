#pragma once

#include "..//..//Definitions.h"
#include "..//PipelineElement.h"
#include "Triangle.h"

#include <iostream>


class Rasteriser : public PipelineElement
{
public:
	Rasteriser();
	void rasterise(buffer<float>& output_fragments, float* vertex_0, float* vertex_1, float* vertex_2);
private:
	bool isCCW(float* vertex_0, float* vertex_1, float* vertex_2);
	void setIODataSize();
	void setupUniforms();

	void fillTriangle(buffer<float>& output_fragments, buffer<float>& rightmost_fragments, Triangle triangle);
};
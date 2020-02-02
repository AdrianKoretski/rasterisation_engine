#pragma once

#include "..//..//Definitions.h"

class VertexPostProcessor
{
public:
	VertexPostProcessor(uint width_resolution, uint height_resolution);
	void postProcessVertices(
		buffer<float>& output_VBO, buffer<uint>& output_VAO, 
		buffer<float>& input_VBO, buffer<uint>& input_VAO);
	uint getOutputVertexSize();
private:
	uint m_width_resolution;
	uint m_height_resolution;
	uint m_output_vertex_size = 7;
	uint m_input_vertex_size = 7;
};


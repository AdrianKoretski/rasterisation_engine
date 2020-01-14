#pragma once

#include "..//Definitions.h"

class VertexPostProcessor
{
public:
	VertexPostProcessor(unsigned int width_resolution, unsigned int height_resolution);
	void postProcessVertices(
		buffer<float>& output_VBO, buffer<unsigned int>& output_VAO, 
		buffer<float>& input_VBO, buffer<unsigned int>& input_VAO);
	unsigned int getOutputVertexSize();
private:
	unsigned int m_width_resolution;
	unsigned int m_height_resolution;
	unsigned int m_output_vertex_size = 7;
	unsigned int m_input_vertex_size = 7;
};


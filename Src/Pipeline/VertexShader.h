#pragma once

#include "..//Definitions.h"

class VertexShader
{
public:
	VertexShader();
	void processVertices(buffer<float>& output_VBO, buffer<float>& input_VBO);
private:
	void shadeVertex(float* output, float* input);

	unsigned int m_input_vertex_size = 7;
	unsigned int m_output_vertex_size = 7;
	float* m_output_vertex;
};


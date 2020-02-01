#include "VertexShader.h"
#include "..//glm/gtc/type_ptr.hpp"
#include <iostream>
VertexShader::VertexShader()
{
}

void VertexShader::processVertices(buffer<float>& output_VBO, buffer<float>& input_VBO)
{
	buffer<float> output_data;
	output_data.resize(m_output_vertex_size);
	for (uint i = 0; i < input_VBO.size(); i += m_input_vertex_size)
	{
		shadeVertex(&output_data[0], &input_VBO[i]);
		for (uint i = 0; i < m_output_vertex_size; i++)
			output_VBO.push_back(output_data[i]);
	}
}

void VertexShader::shadeVertex(float* output, float* input)
{
	for (uint i = 0; i < m_output_vertex_size; i++)
		output[i] = input[1];
}

void VertexShader::setUniform(void* uniform, uint index)
{
	memcpy(m_uniform[index], uniform, m_uniform_size[index]);
}
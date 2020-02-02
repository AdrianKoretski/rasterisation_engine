#include "VertexShader.h"

VertexShader::VertexShader()
{
}

void VertexShader::processVertices(buffer<float>& output_VBO, buffer<float>& input_VBO)
{
	output_VBO.resize(m_output_vertex_size * input_VBO.size() / m_input_vertex_size);
	for (uint i = 0; i < input_VBO.size(); i += m_input_vertex_size)
		shadeVertex(&output_VBO[i], &input_VBO[i]);
}

void VertexShader::shadeVertex(float* output, float* input)
{
	for (uint i = 0; i < m_output_vertex_size; i++)
		output[i] = input[1];
}
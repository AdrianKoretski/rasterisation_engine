#include "VertexShader.h"

VertexShader::VertexShader()
{
	m_output_vertex = new float[m_output_vertex_size];
}

void VertexShader::processVertices(buffer<float>& output_VBO, buffer<float>& input_VBO)
{
	float* output_data = new float[m_output_vertex_size];
	for (int i = 0; i < input_VBO.size(); i += m_input_vertex_size)
	{
		shadeVertex(output_data, &input_VBO[i]);
		for (int i = 0; i < m_output_vertex_size; i++)
			output_VBO.push_back(output_data[i]);
	}
}

void VertexShader::shadeVertex(float* output, float* input)
{
	for (int i = 0; i < m_output_vertex_size; i++)
		output[i] = input[i];
}

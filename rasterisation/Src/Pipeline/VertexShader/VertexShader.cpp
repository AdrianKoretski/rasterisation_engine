#include "VertexShader.h"
#include <iostream>

VertexShader::VertexShader()
{
}

void VertexShader::processVertices(buffer<float>& output_VBO, buffer<float>& input_VBO)
{
	output_VBO.resize(m_output_data_size * input_VBO.size() / m_input_data_size);
	for (uint i = 0; i < input_VBO.size() / m_input_data_size; i++)
		shadeVertex(&output_VBO[i * m_output_data_size], &input_VBO[i * m_input_data_size]);
}
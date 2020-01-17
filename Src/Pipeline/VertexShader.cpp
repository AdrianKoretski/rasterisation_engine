#include "VertexShader.h"
#include "..//glm/gtc/type_ptr.hpp"
#include <iostream>
VertexShader::VertexShader()
{
	m_output_vertex = new float[m_output_vertex_size];
}

void VertexShader::processVertices(buffer<float>& output_VBO, buffer<float>& input_VBO)
{

	float* output_data = new float[m_output_vertex_size];
	for (uint i = 0; i < input_VBO.size(); i += m_input_vertex_size)
	{
		shadeVertex(output_data, &input_VBO[i]);
		for (uint i = 0; i < m_output_vertex_size; i++)
			output_VBO.push_back(output_data[i]);
	}
}

void VertexShader::addUniform(float* uniform, uint uniform_size)
{
	float* uni = new float[uniform_size];
	memcpy(uni, uniform, sizeof(float) * uniform_size);
	m_uniform.push_back(uni);
	m_uniform_size.push_back(uniform_size);
}

void VertexShader::shadeVertex(float* output, float* input)
{
	v4f in(input[0], input[1], input[2], input[3]);
	m4f persp = glm::make_mat4(m_uniform[0]);

	v4f out = persp * in;

	out.x /= out.w;
	out.y /= out.w;
	out.z /= out.w;
	out.w = 1/out.w;

	std::cout << out.x << " " << out.y << " " << out.z << " " << out.w << std::endl;

	for (int i = 0; i < 4; i++)
		output[i] = out[i];
	for (uint i = 4; i < m_output_vertex_size; i++)
		output[i] = input[i];
}

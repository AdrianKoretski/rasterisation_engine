#include "DefaultVPP.h"
#include <iostream>

DefaultVPP::DefaultVPP()
{
	setIOVertexSizes();
	setupUniforms();
}

void DefaultVPP::postProcessVertices(buffer<float>& output_VBO, buffer<uint>& output_VAO, buffer<float>& input_VBO, buffer<uint>& input_VAO)
{
	for (uint i = 0; i < input_VBO.size(); i += m_output_vertex_size)
	{
		output_VBO.push_back((input_VBO[i + 0] + 1) * *m_width_resolution / 2);
		output_VBO.push_back((input_VBO[i + 1] + 1) * *m_height_resolution / 2);
		for (uint j = 2; j < m_output_vertex_size; j++)
			output_VBO.push_back(input_VBO[i + j]);
	}
	for (uint i = 0; i < input_VAO.size(); i++)
		output_VAO.push_back(input_VAO[i]);
}

void DefaultVPP::setIOVertexSizes()
{
	m_output_vertex_size = 7;
	m_input_vertex_size = 7;
}

void DefaultVPP::setupUniforms()
{
	m_uniform.resize(2);
	m_uniform_size.push_back(sizeof(uint));
	m_uniform_size.push_back(sizeof(uint));
	for (uint i = 0; i < m_uniform.size(); i++)
		m_uniform[i] = malloc(m_uniform_size[i]);
	m_width_resolution = (uint*)m_uniform[0];
	m_height_resolution = (uint*)m_uniform[1];
}

#include "DefaultVPP.h"
#include <iostream>

DefaultVPP::DefaultVPP()
{
	setIODataSize();
	setupUniforms();
}

void DefaultVPP::setup() {
}

void DefaultVPP::reset() {
}

void DefaultVPP::postProcessVertices(buffer<float>& output_VBO, buffer<uint>& output_VAO, buffer<float>& input_VBO, buffer<uint>& input_VAO)
{
	for (uint i = 0; i < input_VBO.size(); i += m_input_data_size)
	{
		output_VBO.push_back((input_VBO[i + 0] + 1) * *m_width_resolution / 2);
		output_VBO.push_back((input_VBO[i + 1] + 1) * *m_height_resolution / 2);
		for (uint j = 2; j < m_input_data_size; j++)
			output_VBO.push_back(input_VBO[i + j]);
	}
	for (uint i = 0; i < input_VAO.size(); i++)
		output_VAO.push_back(input_VAO[i]);
}

void DefaultVPP::setIODataSize()
{
	m_input_data_size = 9;
	m_output_data_size = 9;
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

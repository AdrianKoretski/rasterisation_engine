#include "DefaultPSP.h"

DefaultPSP::DefaultPSP()
{
	setIOFragmentSizes();
	setupUniforms();
}

void DefaultPSP::postProcessFragment(buffer<float>& output_fragment, float* input_fragment)
{
	uint x = uint(floor(input_fragment[0]));
	uint y = uint(floor(input_fragment[1]));
	if (x >= *m_depth_buffer_width || x < 0 || y >= *m_depth_buffer_height || y < 0)
		return;
	if (input_fragment[2] <= m_depth_buffer[x + y * *m_depth_buffer_width])
		return;
	m_depth_buffer[x + y * *m_depth_buffer_width] = input_fragment[2];
	for (uint i = 0; i < m_input_fragment_size; i++)
		if (i != 2 && i != 3)
			output_fragment.push_back(input_fragment[i]);
}

void DefaultPSP::setIOFragmentSizes()
{
	m_input_fragment_size = 7;
}

void DefaultPSP::setupUniforms()
{
	m_uniform.resize(2);
	m_uniform_size.push_back(sizeof(uint));
	m_uniform_size.push_back(sizeof(uint));
	for (uint i = 0; i < m_uniform.size(); i++)
		m_uniform[i] = malloc(m_uniform_size[i]);
	m_depth_buffer_width = (uint*)m_uniform[0];
	m_depth_buffer_height = (uint*)m_uniform[1];
}

void DefaultPSP::clearBuffer()
{
	for (uint i = 0; i < *m_depth_buffer_width * *m_depth_buffer_height; i++)
		m_depth_buffer[i] = -std::numeric_limits<float>::infinity();
}

void DefaultPSP::setupBuffer()
{
	m_depth_buffer = new float[*m_depth_buffer_width * *m_depth_buffer_height];
	for (uint i = 0; i < *m_depth_buffer_width * *m_depth_buffer_height; i++)
		m_depth_buffer[i] = -std::numeric_limits<float>::infinity();
}
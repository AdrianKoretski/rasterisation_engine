#include "PerSampleProcessor.h"
#include <iostream>

PerSampleProcessor::PerSampleProcessor(unsigned int depth_buffer_width, unsigned int depth_buffer_height)
{
	m_depth_buffer_width = depth_buffer_width;
	m_depth_buffer_height = depth_buffer_height;
	m_depth_buffer = new float[m_depth_buffer_width * m_depth_buffer_height];
	for (int i = 0; i < m_depth_buffer_width * m_depth_buffer_height; i++)
		m_depth_buffer[i] = std::numeric_limits<float>::infinity();
}

void PerSampleProcessor::postProcessFragments(buffer<float>& output_fragment, buffer<float>& input_fragment)
{
	for (int i = 0; i < input_fragment.size(); i += m_input_fragment_size)
		postProcessFragment(output_fragment, &input_fragment[i]);
}

void PerSampleProcessor::postProcessFragment(buffer<float>& output_fragment, float* input_fragment)
{
	int x = floor(input_fragment[0]);
	int y = floor(input_fragment[1]);
	if (input_fragment[2] > m_depth_buffer[x + y * m_depth_buffer_width])
		return;
	m_depth_buffer[x + y * m_depth_buffer_width] = input_fragment[2];
	for (int i = 0; i < m_input_fragment_size; i++)
		if (i != 2 && i != 3)
			output_fragment.push_back(input_fragment[i]);
}
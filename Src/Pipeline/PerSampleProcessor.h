#pragma once

#include "..//Definitions.h"

class PerSampleProcessor
{
public:
	PerSampleProcessor(unsigned int depth_buffer_width, unsigned int depth_buffer_height);
	void postProcessFragments(buffer<float>& output_fragment, buffer<float>& input_fragment);
private:
	void postProcessFragment(buffer<float>& output_fragment, float* input_fragment);
	unsigned int m_input_fragment_size = 7;

	float* m_depth_buffer;
	unsigned int m_depth_buffer_width;
	unsigned int m_depth_buffer_height;
};


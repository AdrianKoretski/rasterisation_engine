#pragma once

#include "..//Definitions.h"

class PerSampleProcessor
{
public:
	PerSampleProcessor(uint depth_buffer_width, uint depth_buffer_height);
	void postProcessFragments(buffer<float>& output_fragment, buffer<float>& input_fragment);
private:
	void postProcessFragment(buffer<float>& output_fragment, float* input_fragment);
	uint m_input_fragment_size = 7;

	float* m_depth_buffer;
	uint m_depth_buffer_width;
	uint m_depth_buffer_height;
};


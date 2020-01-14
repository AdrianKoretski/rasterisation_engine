#pragma once

#include "..//Definitions.h"

class PerSampleProcessor
{
public:
	void postProcessFragments(buffer<float>& output_fragment, buffer<float>& input_fragment);
private:
	void postProcessFragment(buffer<float>& output_fragment, float* input_fragment);
	unsigned int m_input_fragment_size = 7;
};


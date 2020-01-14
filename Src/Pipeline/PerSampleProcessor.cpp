#include "PerSampleProcessor.h"
#include <iostream>

void PerSampleProcessor::postProcessFragments(buffer<float>& output_fragment, buffer<float>& input_fragment)
{
	for (int i = 0; i < input_fragment.size(); i += m_input_fragment_size)
		postProcessFragment(output_fragment, &input_fragment[i]);
}

void PerSampleProcessor::postProcessFragment(buffer<float>& output_fragment, float* input_fragment)
{
	for (int i = 0; i < m_input_fragment_size; i++)
		if (i != 2 && i != 3)
			output_fragment.push_back(input_fragment[i]);
}
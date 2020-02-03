#include "PerSampleProcessor.h"
#include <iostream>

PerSampleProcessor::PerSampleProcessor()
{
}

void PerSampleProcessor::postProcessFragments(buffer<float>& output_fragment, buffer<float>& input_fragment)
{
	for (uint i = 0; i < input_fragment.size(); i += m_input_fragment_size)
		postProcessFragment(output_fragment, &input_fragment[i]);
}
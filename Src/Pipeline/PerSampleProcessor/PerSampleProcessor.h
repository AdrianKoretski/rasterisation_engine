#pragma once

#include "../PipelineElement.h"

class PerSampleProcessor : public PipelineElement
{
public:
	PerSampleProcessor();
	void postProcessFragments(buffer<float>& output_fragment, buffer<float>& input_fragment);
protected:
	virtual void postProcessFragment(buffer<float>& output_fragment, float* input_fragment) = 0;

	float* m_depth_buffer;
};
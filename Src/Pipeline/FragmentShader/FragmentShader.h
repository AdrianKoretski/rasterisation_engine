#pragma once

#include "..//..//Definitions.h"
#include "../PipelineElement.h"

class FragmentShader : public PipelineElement
{
public:
	FragmentShader();
	void shadeFragments(buffer<float>& output_fragment, buffer<float>& inupt_fragment);
protected:
	virtual void shadeFragment(float* output_fragment, float* inupt_fragment) = 0;
};


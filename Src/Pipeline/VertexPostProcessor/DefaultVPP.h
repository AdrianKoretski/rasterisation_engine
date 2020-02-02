#pragma once

#include "VertexPostProcessor.h"

class DefaultVPP : public VertexPostProcessor
{
public:
	DefaultVPP();
protected:
	void shadeFragment(float* output_fragment, float* inupt_fragment);
	void setIOFragmentSizes();
	void setupUniforms();
};
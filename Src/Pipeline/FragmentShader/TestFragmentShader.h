#pragma once

#include "FragmentShader.h"

class TestFragmentShader : public FragmentShader
{
public:
	TestFragmentShader();
protected:
	void shadeFragment(float* output_fragment, float* inupt_fragment);
	void setIODataSize();
	void setupUniforms();
};
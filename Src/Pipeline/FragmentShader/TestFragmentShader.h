#pragma once

#include "FragmentShader.h"

class TestFragmentShader : public FragmentShader
{
public:
	TestFragmentShader();
	void setup();
	void reset();
protected:
	void shadeFragment(float* output_fragment, float* inupt_fragment);
	void setIODataSize();
	void setupUniforms();
};
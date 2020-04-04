#pragma once

#include "FragmentShader.h"

class TextureFS : public FragmentShader
{
public:
	TextureFS();
	void setup();
	void reset();
protected:
	void shadeFragment(float* output_fragment, float* inupt_fragment);
	void setIODataSize();
	void setupUniforms();
};
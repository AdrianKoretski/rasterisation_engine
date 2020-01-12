#pragma once

#include "..//Definitions.h"

class FragmentShader
{
public:
	FragmentShader();
	void shadeFragments(buffer<float>& output_fragment, buffer<float>& inupt_fragment);
	void setColor();
	v3f color;
private:
	void shadeFragment(buffer<float>& output_fragment, float* inupt_fragment);
};


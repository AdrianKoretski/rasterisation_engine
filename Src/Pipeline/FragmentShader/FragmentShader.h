#pragma once

#include "..//..//Definitions.h"
#include "../Uniform.h"

class FragmentShader
{
public:
	FragmentShader();
	void shadeFragments(buffer<float>& output_fragment, buffer<float>& inupt_fragment);
private:
	void shadeFragment(float* output_fragment, float* inupt_fragment);
	void setIOVertexSizes();

	uint m_input_fragment_size = 7;
	uint m_output_fragment_size = 7;
};


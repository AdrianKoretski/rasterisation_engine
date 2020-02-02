#pragma once

#include "..//..//Definitions.h"
#include "../Uniform.h"

class FragmentShader : public Uniform
{
public:
	FragmentShader();
	void shadeFragments(buffer<float>& output_fragment, buffer<float>& inupt_fragment);
protected:
	virtual void shadeFragment(float* output_fragment, float* inupt_fragment) = 0;
	virtual void setIOFragmentSizes() = 0;

	uint m_input_fragment_size = 4;
	uint m_output_fragment_size = 4;
};


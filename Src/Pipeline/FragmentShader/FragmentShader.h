#pragma once

#include "..//..//Definitions.h"

class FragmentShader
{
public:
	FragmentShader();
	void shadeFragments(buffer<float>& output_fragment, buffer<float>& inupt_fragment);
private:
	void shadeFragment(buffer<float>& output_fragment, float* inupt_fragment);
	uint m_input_vertex_size = 7;
	uint m_output_vertex_size = 7;
};


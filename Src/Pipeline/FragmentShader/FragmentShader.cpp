#include "FragmentShader.h"

FragmentShader::FragmentShader()
{
}

void FragmentShader::shadeFragments(buffer<float>& output_fragment, buffer<float>& inupt_fragment)
{
	output_fragment.resize(m_output_fragment_size * inupt_fragment.size() / m_input_fragment_size);
	for (uint i = 0; i < inupt_fragment.size(); i += m_input_fragment_size)
		shadeFragment(&output_fragment[i], &inupt_fragment[i]);
}
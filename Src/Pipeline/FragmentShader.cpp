#include "FragmentShader.h"

FragmentShader::FragmentShader()
{
}

void FragmentShader::shadeFragments(buffer<float>& output_fragment, buffer<float>& inupt_fragment)
{
	for (uint i = 0; i < inupt_fragment.size(); i += m_input_vertex_size)			// TODO: change 4 to a variable
		shadeFragment(output_fragment, &inupt_fragment[i]);
}

void FragmentShader::shadeFragment(buffer<float>& output_fragment, float* inupt_fragment)
{
	for (uint i = 0; i < m_input_vertex_size; i++)
		output_fragment.push_back(inupt_fragment[i]);
}

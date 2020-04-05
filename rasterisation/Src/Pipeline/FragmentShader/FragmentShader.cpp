#include "FragmentShader.h"

FragmentShader::FragmentShader()
{
}

void FragmentShader::shadeFragments(buffer<float>& output_fragment, buffer<float>& inupt_fragment)
{
	output_fragment.resize(m_output_data_size * inupt_fragment.size() / m_input_data_size);
	for (uint i = 0; i < inupt_fragment.size() / m_input_data_size; i++)
		shadeFragment(&output_fragment[i * m_output_data_size], &inupt_fragment[i * m_input_data_size]);
}
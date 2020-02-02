#include "TestFragmentShader.h"

TestFragmentShader::TestFragmentShader()
{
	setIOFragmentSizes();
	setupUniforms();
}

void TestFragmentShader::shadeFragment(float* output_fragment, float* inupt_fragment)
{
	memcpy(output_fragment, inupt_fragment, m_input_fragment_size * sizeof(float));
}

void TestFragmentShader::setIOFragmentSizes()
{
	m_input_fragment_size = 7;
	m_output_fragment_size = 7;
}

void TestFragmentShader::setupUniforms()
{
}
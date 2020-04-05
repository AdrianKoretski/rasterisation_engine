#include "TestFragmentShader.h"
#include <iostream>

TestFragmentShader::TestFragmentShader()
{
	setIODataSize();
	setupUniforms();
}

void TestFragmentShader::setup() {
}

void TestFragmentShader::reset() {
}

void TestFragmentShader::shadeFragment(float* output_fragment, float* inupt_fragment)
{
	memcpy(output_fragment, inupt_fragment, m_input_data_size * sizeof(float));
}

void TestFragmentShader::setIODataSize()
{
	m_input_data_size = 12;
	m_output_data_size = 12;
}

void TestFragmentShader::setupUniforms()
{
}
#include "TestVertexShader.h"
#include <iostream>

TestVertexShader::TestVertexShader()
{
	setIODataSize();
	setupUniforms();
}

void TestVertexShader::setup() {
}

void TestVertexShader::reset() {
}

void TestVertexShader::shadeVertex(float* output, float* input)
{
	v4f in(input[0], input[1], input[2], input[3]);

	v4f out = *m_persp * in;
	float depth = 1.f/out.w;
	out = out * depth;
	out.w = depth;

	for (int i = 0; i < 4; i++)
		output[i] = out[i];
	for (uint i = 4; i < m_output_data_size; i++)
		output[i] = input[i];
}

void TestVertexShader::setIODataSize()
{
	m_input_data_size = 12;
	m_output_data_size = 12;
}

void TestVertexShader::setupUniforms()
{
	m_uniform.resize(1);
	m_uniform_size.push_back(sizeof(m4f));
	m_uniform[0] = malloc(m_uniform_size[0]);
	m_persp = (m4f*)(m_uniform[0]);
}

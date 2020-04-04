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
	Vec4 in(input[0], input[1], input[2], input[3]);

	Vec4 out = *m_persp * in;
	float depth = 1.f/out.w;
	out = out * depth;
	out.w = depth;

	output[0] = out.x;
	output[1] = out.y;
	output[2] = out.z;
	output[3] = out.w;
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
	m_uniform_size.push_back(sizeof(Mat4));
	m_uniform[0] = malloc(m_uniform_size[0]);
	m_persp = (Mat4*)(m_uniform[0]);
}

#include "TestVertexShader.h"

TestVertexShader::TestVertexShader()
{
	setIOVertexSizes();
	setupUniforms();
	m_persp = (m4f*)(m_uniform[0]);
}

void TestVertexShader::shadeVertex(float* output, float* input)
{
	v4f in(input[0], input[1], input[2], input[3]);

	v4f out = *m_persp * in;

	out.x /= out.w;
	out.y /= out.w;
	out.z /= out.w;
	out.w = 1/out.w;

	for (int i = 0; i < 4; i++)
		output[i] = out[i];
	for (uint i = 4; i < m_output_vertex_size; i++)
		output[i] = input[i];
}

void TestVertexShader::setIOVertexSizes()
{
	m_input_vertex_size = 7;
	m_output_vertex_size = 7;
}

void TestVertexShader::setupUniforms()
{
	m_uniform.resize(1);
	m_uniform_size.push_back(sizeof(m4f));
	m_uniform[0] = malloc(m_uniform_size[0]);
}

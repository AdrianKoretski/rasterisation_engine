#pragma once

#include "VertexShader.h"

class TestVertexShader : public VertexShader
{
public:
	TestVertexShader();
protected:
	void shadeVertex(float* output, float* input);
	void setIODataSize();
	void setupUniforms();
private:
	m4f* m_persp;
};


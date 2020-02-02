#pragma once

#include "..//..//Definitions.h"
#include "VertexShader.h"

class TestVertexShader : public VertexShader
{
public:
	TestVertexShader();
protected:
	void shadeVertex(float* output, float* input);
	void setIOVertexSizes();
	void setupUniforms();
private:
	m4f* m_persp;
};


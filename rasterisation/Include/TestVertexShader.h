#pragma once

#include "VertexShader.h"

class TestVertexShader : public VertexShader
{
public:
	TestVertexShader();
	void setup();
	void reset();
protected:
	void shadeVertex(float* output, float* input);
	void setIODataSize();
	void setupUniforms();
private:
	Mat4* m_persp;
};


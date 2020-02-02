#pragma once

#include "..//..//Definitions.h"
#include "../Uniform.h"

class VertexShader : public Uniform
{
public:
	VertexShader();
	void processVertices(buffer<float>& output_VBO, buffer<float>& input_VBO);
protected:
	virtual void shadeVertex(float* output, float* input) = 0;
	virtual void setIOVertexSizes() = 0;

	uint m_input_vertex_size = 4;
	uint m_output_vertex_size = 4;
};
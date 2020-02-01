#pragma once

#include "..//Definitions.h"

class VertexShader
{
public:
	VertexShader();
	void processVertices(buffer<float>& output_VBO, buffer<float>& input_VBO);

	void setUniform(void* uniform, uint index);
protected:
	virtual void shadeVertex(float* output, float* input) = 0;
	virtual void setIOVertexSizes() = 0;
	virtual void setupUniforms() = 0;

	buffer<void*> m_uniform;
	buffer<uint> m_uniform_size;

	uint m_input_vertex_size = 4;
	uint m_output_vertex_size = 4;
};
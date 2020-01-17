#pragma once

#include "..//Definitions.h"

class VertexShader
{
public:
	VertexShader();
	void processVertices(buffer<float>& output_VBO, buffer<float>& input_VBO);
	uint addUniform(float* uniform, uint uniform_size);
	void setUniform(float* uniform, uint uniform_size, uint index);
private:
	void shadeVertex(float* output, float* input);

	uint m_input_vertex_size = 7;
	uint m_output_vertex_size = 7;

	buffer<float*> m_uniform;
	buffer<uint> m_uniform_size;
};


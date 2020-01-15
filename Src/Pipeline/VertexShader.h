#pragma once

#include "..//Definitions.h"

class VertexShader
{
public:
	VertexShader();
	void processVertices(buffer<float>& output_VBO, buffer<float>& input_VBO);
private:
	void shadeVertex(float* output, float* input);

	uint m_input_vertex_size = 7;
	uint m_output_vertex_size = 7;
	float* m_output_vertex;
};


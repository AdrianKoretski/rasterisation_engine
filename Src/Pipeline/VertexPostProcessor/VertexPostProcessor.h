#pragma once

#include "..//..//Definitions.h"
#include "../Uniform.h"

class VertexPostProcessor : public Uniform
{
public:
	VertexPostProcessor();
	virtual void postProcessVertices(
		buffer<float>& output_VBO, buffer<uint>& output_VAO, 
		buffer<float>& input_VBO, buffer<uint>& input_VAO) = 0;
	uint getOutputVertexSize();
protected:
	virtual void setIOVertexSizes() = 0;
	uint m_output_vertex_size = 4;
	uint m_input_vertex_size = 4;
};
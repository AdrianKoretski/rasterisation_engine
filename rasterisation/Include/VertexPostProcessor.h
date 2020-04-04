#pragma once

#include "Definitions.h"
#include "PipelineElement.h"

class VertexPostProcessor : public PipelineElement
{
public:
	VertexPostProcessor();
	virtual void postProcessVertices(
		buffer<float>& output_VBO, buffer<uint>& output_VAO, 
		buffer<float>& input_VBO, buffer<uint>& input_VAO) = 0;
};
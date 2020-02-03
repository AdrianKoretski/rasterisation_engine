#pragma once

#include "..//..//Definitions.h"
#include "../PipelineElement.h"

class VertexShader : public PipelineElement
{
public:
	VertexShader();
	void processVertices(buffer<float>& output_VBO, buffer<float>& input_VBO);
protected:
	virtual void shadeVertex(float* output, float* input) = 0;
};
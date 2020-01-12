#include "VertexShader.h"

VertexShader::VertexShader()
{
}

void VertexShader::processVertices(buffer<float>& output_VBO, buffer<float>& input_VBO)
{
	float* output_data = new float;
	for (int i = 0; i < input_VBO.size(); i++)
	{
		shadeVertex(output_data, &input_VBO[i]);
		output_VBO.push_back(*output_data);
	}
}

void VertexShader::shadeVertex(float* output, float* input)
{
	*output = *input;
}

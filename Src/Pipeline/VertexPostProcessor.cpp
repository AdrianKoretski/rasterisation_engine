#include "VertexPostProcessor.h"
#include "..//Definitions.h"

VertexPostProcessor::VertexPostProcessor(unsigned int width_resolution, unsigned int height_resolution)
{
	m_width_resolution = width_resolution;
	m_height_resolution = height_resolution;
}

// This is an example of simple vertex post processing. Ideally, this section would include triangle clipping and such.
void VertexPostProcessor::postProcessVertices(
	buffer<float>& output_VBO, buffer<unsigned int>& output_VAO,
	buffer<float>& input_VBO, buffer<unsigned int>& input_VAO)
{
	float* output_float = new float;
	int* output_int = new int;

	for (unsigned int i = 0; i < input_VBO.size(); i += m_vertex_size)
	{
		output_VBO.push_back((input_VBO[i+0] + 1) * m_width_resolution / 2);
		output_VBO.push_back((input_VBO[i+1] + 1) * m_height_resolution / 2);
		output_VBO.push_back(input_VBO[i+2]);
		output_VBO.push_back(input_VBO[i+3]);
	}
	for (unsigned int i = 0; i < input_VAO.size(); i++)
	{
		output_VAO.push_back(input_VAO[i]);
	}
}
#include "VertexPostProcessor.h"
#include "..//Definitions.h"

VertexPostProcessor::VertexPostProcessor(uint width_resolution, uint height_resolution)
{
	m_width_resolution = width_resolution;
	m_height_resolution = height_resolution;
}

// This is an example of simple vertex post processing. Ideally, this section would include triangle clipping and such.
void VertexPostProcessor::postProcessVertices(
	buffer<float>& output_VBO, buffer<uint>& output_VAO,
	buffer<float>& input_VBO, buffer<uint>& input_VAO)
{
	float* output_float = new float;
	int* output_int = new int;

	for (uint i = 0; i < input_VBO.size(); i += m_output_vertex_size)
	{
		output_VBO.push_back((input_VBO[i+0] + 1) * m_width_resolution / 2);
		output_VBO.push_back((input_VBO[i+1] + 1) * m_height_resolution / 2);
		for (uint j = 2; j < m_output_vertex_size; j++)
			output_VBO.push_back(input_VBO[i + j]);
	}
	for (uint i = 0; i < input_VAO.size(); i++)
		output_VAO.push_back(input_VAO[i]);
}

uint VertexPostProcessor::getOutputVertexSize()
{
	return m_output_vertex_size;
}

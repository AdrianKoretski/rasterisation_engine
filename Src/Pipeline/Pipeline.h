#pragma once

#include <vector>

#include "..//Definitions.h"
#include "VertexShader.h"
#include "VertexPostProcessor.h"
#include "Rasteriser.h"
#include "FragmentShader.h"
#include "PerSampleProcessor.h"

class Pipeline
{
public:
	Pipeline(unsigned int image_buffer_wigth, unsigned int image_buffer_height);
	void renderObject(buffer<float>& VBO, buffer<unsigned int>& VAO);
private:

	void setPixel(float* pixel_data);

	void processVertices(buffer<float>& output_VBO, buffer<unsigned int>& output_VAO, buffer<float>& input_VBO, buffer<unsigned int>& input_VAO);
	void renderTriangle(buffer<float>& input_VBO, unsigned int* input_VAO);
	void processTriangle(buffer<float>& output_fragments, float* vertex_0, float* vertex_1, float* vertex_2);

	buffer<VertexShader> m_vertex_shader;
	buffer<VertexPostProcessor> m_vertex_post_processor;
	buffer<Rasteriser> m_rasteriser;
	buffer<FragmentShader> m_fragment_shader;
	buffer<PerSampleProcessor> m_per_sample_processor;

	unsigned int m_vertex_size;
	unsigned int m_image_buffer_width;
	unsigned int m_image_buffer_height;
	buffer<float*> m_image_buffer;
};
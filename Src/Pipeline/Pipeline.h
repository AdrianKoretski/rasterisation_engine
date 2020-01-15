#pragma once

#include <vector>

#include "..//Definitions.h"
#include "VertexShader.h"
#include "VertexPostProcessor.h"
#include "Rasterisation/Rasteriser.h"
#include "FragmentShader.h"
#include "PerSampleProcessor.h"

class Pipeline
{
public:
	Pipeline(uint image_buffer_wigth, uint image_buffer_height);
	void renderObject(buffer<float>& VBO, buffer<uint>& VAO);
private:

	void setPixel(float* pixel_data);

	void processVertices(buffer<float>& output_VBO, buffer<uint>& output_VAO, buffer<float>& input_VBO, buffer<uint>& input_VAO);
	void renderTriangle(buffer<float>& input_VBO, uint* input_VAO);
	void processTriangle(buffer<float>& output_fragments, float* vertex_0, float* vertex_1, float* vertex_2);

	buffer<VertexShader> m_vertex_shader;
	buffer<VertexPostProcessor> m_vertex_post_processor;
	buffer<Rasteriser> m_rasteriser;
	buffer<FragmentShader> m_fragment_shader;
	buffer<PerSampleProcessor> m_per_sample_processor;

	uint m_vertex_size;
	uint m_image_buffer_width;
	uint m_image_buffer_height;
	buffer<float*> m_image_buffer;
};
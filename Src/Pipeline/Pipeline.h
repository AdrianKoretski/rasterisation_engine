#pragma once

#include <vector>

#include "../Definitions.h"
#include "../Scene/Camera.h"
#include "VertexShader/VertexShader.h"
#include "VertexPostProcessor/VertexPostProcessor.h"
#include "Rasterisation/Rasteriser.h"
#include "FragmentShader/FragmentShader.h"
#include "PerSampleProcessor/PerSampleProcessor.h"

class Pipeline
{
public:
	Pipeline(uint image_buffer_wigth, uint image_buffer_height, Camera* camera);

	uint addVertexShader(VertexShader* vertex_shader);
	uint addVertexPostProcessor(VertexPostProcessor* vertex_post_processor);
	uint addRasteriser(Rasteriser* rasteriser);
	uint addFragmentShader(FragmentShader* fragment_shader);
	uint addPerSampleProcessor(PerSampleProcessor* per_sample_processor);

	void setCurrentVertexShader(uint index);
	void setCurrentVertexPostProcessor(uint index);
	void setCurrentRasteriser(uint index);
	void setCurrentFragmentShader(uint index);
	void setCurrentPerSampleProcessor(uint index);

	void renderObject(buffer<float>& VBO, buffer<uint>& VAO);
	void saveRender(std::string file_name);
	void clearBuffers();
private:

	void setPixel(float* pixel_data);

	void processVertices(buffer<float>& output_VBO, buffer<uint>& output_VAO, buffer<float>& input_VBO, buffer<uint>& input_VAO);
	void renderTriangle(buffer<float>& input_VBO, uint* input_VAO);
	void processTriangle(buffer<float>& output_fragments, float* vertex_0, float* vertex_1, float* vertex_2);

	buffer<VertexShader*> m_vertex_shaders;
	buffer<VertexPostProcessor*> m_vertex_post_processors;
	buffer<Rasteriser*> m_rasterisers;
	buffer<FragmentShader*> m_fragment_shaders;
	buffer<PerSampleProcessor*> m_per_sample_processors;

	VertexShader* m_vertex_shader;
	VertexPostProcessor* m_vertex_post_processor;
	Rasteriser* m_rasteriser;
	FragmentShader* m_fragment_shader;
	PerSampleProcessor* m_per_sample_processor;

	uint m_vertex_size;
	uint m_image_buffer_width;
	uint m_image_buffer_height;
	buffer<float*> m_image_buffer;
};
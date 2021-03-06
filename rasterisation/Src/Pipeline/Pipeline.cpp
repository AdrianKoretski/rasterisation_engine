#include "Pipeline.h"
#include "EXR.h"

Pipeline::Pipeline(uint image_buffer_width, uint image_buffer_height, Camera* camera)
{
	m_image_buffer_width = image_buffer_width;
	m_image_buffer_height = image_buffer_height;

	m_image_buffer.resize(m_image_buffer_width * m_image_buffer_height * 3);
	for (uint i = 0; i < m_image_buffer_width * m_image_buffer_height; i++)
	{
		m_image_buffer[i * 3 + 0] = 0;
		m_image_buffer[i * 3 + 1] = 0;
		m_image_buffer[i * 3 + 2] = 0;
	}
}

void Pipeline::renderObject(buffer<float>& VBO, buffer<uint>& VAO)
{
	buffer<float> processed_VBO;
	buffer<uint> processed_VAO;

	processVertices(processed_VBO, processed_VAO, VBO, VAO);
	for (uint i = 0; i < processed_VAO.size(); i += 3)
		renderTriangle(processed_VBO, &processed_VAO[i]);
}

void Pipeline::processVertices(buffer<float>& output_VBO, buffer<uint>& output_VAO, buffer<float>& input_VBO, buffer<uint>& input_VAO)
{
	buffer<float> perspective_VBO;
	m_vertex_shader->processVertices(perspective_VBO, input_VBO);
	m_vertex_post_processor->postProcessVertices(output_VBO, output_VAO, perspective_VBO, input_VAO);
	m_vertex_size = m_vertex_post_processor->getOutputDataSize();
}

void Pipeline::processTriangle(buffer<float>& output_fragments, float* vertex_0, float* vertex_1, float* vertex_2)
{
	buffer<float> fragments;
	m_rasteriser->rasterise(fragments, vertex_0, vertex_1, vertex_2);
	m_fragment_shader->shadeFragments(output_fragments, fragments);
}

void Pipeline::renderTriangle(buffer<float>& input_VBO, uint* input_VAO)
{
	buffer<float> shaded_fragments;
	buffer<float> post_processed_fragments;
	processTriangle(shaded_fragments, 
		&input_VBO[m_vertex_size * input_VAO[0]],
		&input_VBO[m_vertex_size * input_VAO[1]],
		&input_VBO[m_vertex_size * input_VAO[2]]
	);
	m_per_sample_processor->postProcessFragments(post_processed_fragments, shaded_fragments);
	for (uint j = 0; j < post_processed_fragments.size(); j += 7)
		setPixel(&post_processed_fragments[j]);
}

void Pipeline::clearBuffers()
{
	for (uint i = 0; i < m_image_buffer_width * m_image_buffer_height * 3; i++)
		m_image_buffer[i] = 0;
	m_per_sample_processor->reset();
}

void Pipeline::saveRender(std::string file_name)
{
	saveEXR(&m_image_buffer[0], file_name + ".exr", m_image_buffer_width, m_image_buffer_height);
}

void Pipeline::setPixel(float* pixel_data)
{

	uint x = uint(floor(pixel_data[0]));
	uint y = uint(m_image_buffer_height - 1 - floor(pixel_data[1]));
	if (x >= m_image_buffer_width || x < 0 || y >= m_image_buffer_height || y < 0)
		return;
	m_image_buffer[(x + y * m_image_buffer_width) * 3 + 0] = pixel_data[2];
	m_image_buffer[(x + y * m_image_buffer_width) * 3 + 1] = pixel_data[3];
	m_image_buffer[(x + y * m_image_buffer_width) * 3 + 2] = pixel_data[4];
}

uint Pipeline::addVertexShader(VertexShader* vertex_shader)
{
	m_vertex_shaders.push_back(vertex_shader);
	return m_vertex_shaders.size() - 1;
}

uint Pipeline::addVertexPostProcessor(VertexPostProcessor* vertex_post_processor)
{
	m_vertex_post_processors.push_back(vertex_post_processor);
	return m_vertex_post_processors.size() - 1;
}

uint Pipeline::addRasteriser(Rasteriser* rasteriser)
{
	m_rasterisers.push_back(rasteriser);
	return m_rasterisers.size() - 1;
}

uint Pipeline::addFragmentShader(FragmentShader* fragment_shader)
{
	m_fragment_shaders.push_back(fragment_shader);
	return m_fragment_shaders.size() - 1;
}

uint Pipeline::addPerSampleProcessor(PerSampleProcessor* per_sample_processor)
{
	m_per_sample_processors.push_back(per_sample_processor);
	return m_per_sample_processors.size() - 1;
}

void Pipeline::setCurrentVertexShader(uint index)
{
	if (index >= m_vertex_shaders.size() || index < 0)
		return;
	m_vertex_shader = m_vertex_shaders[index];
}

void Pipeline::setCurrentVertexPostProcessor(uint index)
{
	if (index >= m_vertex_post_processors.size() || index < 0)
		return;
	m_vertex_post_processor = m_vertex_post_processors[index];
}

void Pipeline::setCurrentRasteriser(uint index)
{
	if (index >= m_rasterisers.size() || index < 0)
		return;
	m_rasteriser = m_rasterisers[index];
}

void Pipeline::setCurrentFragmentShader(uint index)
{
	if (index >= m_fragment_shaders.size() || index < 0)
		return;
	m_fragment_shader = m_fragment_shaders[index];
}

void Pipeline::setCurrentPerSampleProcessor(uint index)
{
	if (index >= m_per_sample_processors.size() || index < 0)
		return;
	m_per_sample_processor = m_per_sample_processors[index];
}
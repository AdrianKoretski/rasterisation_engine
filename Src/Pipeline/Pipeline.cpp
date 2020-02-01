#include "Pipeline.h"
#include "../Utilities.h"

Pipeline::Pipeline(uint image_buffer_width, uint image_buffer_height, Camera* camera)
{
	m_image_buffer_width = image_buffer_width;
	m_image_buffer_height = image_buffer_height;

	m_vertex_shader.push_back(new TestVertexShader());
	m_vertex_post_processor.push_back(*new VertexPostProcessor(image_buffer_width, image_buffer_height));
	m_rasteriser.push_back(*new Rasteriser(image_buffer_width, image_buffer_height));
	m_fragment_shader.push_back(*new FragmentShader());
	m_per_sample_processor.push_back(*new PerSampleProcessor(image_buffer_width, image_buffer_height));

	m_image_buffer.resize(m_image_buffer_width * m_image_buffer_height);
	for (uint i = 0; i < m_image_buffer_width * m_image_buffer_height; i++)
	{
		m_image_buffer[i] = new float[3];
		m_image_buffer[i][0] = 0;
		m_image_buffer[i][1] = 0;
		m_image_buffer[i][2] = 0;
	}
	m_camera = camera;
	m_vertex_shader[0]->setUniform((&m_camera->getViewPerspectiveMatrix()), 0);
}

void Pipeline::renderObject(buffer<float>& VBO, buffer<uint>& VAO)
{
	m_vertex_shader[0]->setUniform((&m_camera->getViewPerspectiveMatrix()), 0);
	buffer<float> processed_VBO;
	buffer<uint> processed_VAO;

	processVertices(processed_VBO, processed_VAO, VBO, VAO);
	for (uint i = 0; i < processed_VAO.size(); i += 3)
		renderTriangle(processed_VBO, &processed_VAO[i]);
}

void Pipeline::clearBuffers()
{
	for (uint i = 0; i < m_image_buffer_width * m_image_buffer_height; i++)
	{
		m_image_buffer[i][0] = 0;
		m_image_buffer[i][1] = 0;
		m_image_buffer[i][2] = 0;
	}
	m_per_sample_processor[0].clearBuffer();
}

void Pipeline::saveRender(std::string file_name)
{
	saveEXR(m_image_buffer, file_name + ".exr", m_image_buffer_width, m_image_buffer_height);
}

void Pipeline::setPixel(float* pixel_data)
{

	uint x = uint(floor(pixel_data[0]));
	uint y = uint(m_image_buffer_height - 1 - floor(pixel_data[1]));
	if (x >= m_image_buffer_width || x < 0 || y >= m_image_buffer_height || y < 0)
		return;
	m_image_buffer[x + y * m_image_buffer_width][0] = pixel_data[2];
	m_image_buffer[x + y * m_image_buffer_width][1] = pixel_data[3];
	m_image_buffer[x + y * m_image_buffer_width][2] = pixel_data[4];
}

void Pipeline::processVertices(buffer<float>& output_VBO, buffer<uint>& output_VAO, buffer<float>& input_VBO, buffer<uint>& input_VAO)
{
	buffer<float> perspective_VBO;
	m_vertex_shader[0]->processVertices(perspective_VBO, input_VBO);
	m_vertex_post_processor[0].postProcessVertices(output_VBO, output_VAO, perspective_VBO, input_VAO);
	m_vertex_size = m_vertex_post_processor[0].getOutputVertexSize();
}

void Pipeline::processTriangle(buffer<float>& output_fragments, float* vertex_0, float* vertex_1, float* vertex_2)
{
	buffer<float> fragments;
	m_rasteriser[0].rasterise(fragments, vertex_0, vertex_1, vertex_2);
	m_fragment_shader[0].shadeFragments(output_fragments, fragments);
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
	m_per_sample_processor[0].postProcessFragments(post_processed_fragments, shaded_fragments);
	for (uint j = 0; j < post_processed_fragments.size(); j += 5)
		setPixel(&post_processed_fragments[j]);
}
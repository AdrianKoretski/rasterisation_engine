#include <iostream>
#include <random>
#include "Definitions.h"
#include "Pipeline.h"
#include "Camera.h"
#include <string>

#include "TestVertexShader.h"
#include "DefaultVPP.h"
#include "Rasteriser.h"
#include "TestFragmentShader.h"
#include "TextureFS.h"
#include "DefaultPSP.h"
#include "GifMaker.h"
#include "ObjLoader.h"

struct vert
{
	vert(float a, float b, float c)
	{
		position = Vec3(a, b, c);
	}
	Vec3 position;
	Vec2 uv;
	Vec3 normal;
};

int main()
{
	uint width = 1920;
	uint height = 1080;
	GifMaker g(width, height);

	Camera* camera = &Camera();
	camera->setPerspective(90, 16.f / 9);
	camera->setCamera(Vec3(0, 0, 0), Vec3(0, 0, -1), Vec3(0, 1, 0));
	Pipeline pipeline(1920, 1080, camera);

	TestVertexShader* vs = new TestVertexShader();
	DefaultVPP* vpp = new DefaultVPP();
	Rasteriser* r = new Rasteriser();
	TestFragmentShader* fs = new TestFragmentShader();
	DefaultPSP* psp = new DefaultPSP();

	TextureFS* tfs = new TextureFS();

	vs->setUniform(&camera->getViewPerspectiveMatrix(), 0);
	vpp->setUniform(&width, 0);
	vpp->setUniform(&height, 1);
	psp->setUniform(&width, 0);
	psp->setUniform(&height, 1);
	psp->setup();

	pipeline.addVertexShader(vs);
	pipeline.addVertexPostProcessor(vpp);
	pipeline.addRasteriser(r);
	pipeline.addFragmentShader(fs);
	pipeline.addFragmentShader(tfs);
	pipeline.addPerSampleProcessor(psp);

	pipeline.setCurrentVertexShader(0);
	pipeline.setCurrentVertexPostProcessor(0);
	pipeline.setCurrentRasteriser(0);
	pipeline.setCurrentFragmentShader(1);
	pipeline.setCurrentPerSampleProcessor(0);

	buffer<float> VBO;
	buffer<uint> VAO;
	VBO.resize(24 * 9);
	vert* vertices = (vert*)VBO.data();
	vertices[0] = vert(0.5f, 0.5f, 0.5f);
	vertices[1] = vert(0.5f, 0.5f, -0.5f);
	vertices[2] = vert(0.5f, -0.5f, 0.5f);
	vertices[3] = vert(0.5f, -0.5f, -0.5f);

	vertices[4] = vert(-0.5f, -0.5f, 0.5f);
	vertices[5] = vert(-0.5f, -0.5f, -0.5f);
	vertices[6] = vert(-0.5f, 0.5f, 0.5f);
	vertices[7] = vert(-0.5f, 0.5f, -0.5f);

	vertices[8] = vert(-0.5f, 0.5f, 0.5f);
	vertices[9] = vert(-0.5f, 0.5f, -0.5f);
	vertices[10] = vert(0.5f, 0.5f, 0.5f);
	vertices[11] = vert(0.5f, 0.5f, -0.5f);

	vertices[12] = vert(0.5f, -0.5f, 0.5f);
	vertices[13] = vert(0.5f, -0.5f, -0.5f);
	vertices[14] = vert(-0.5f, -0.5f, 0.5f);
	vertices[15] = vert(-0.5f, -0.5f, -0.5f);

	vertices[16] = vert(-0.5f, -0.5f, 0.5f);
	vertices[17] = vert(-0.5f, 0.5f, 0.5f);
	vertices[18] = vert(0.5f, -0.5f, 0.5f);
	vertices[19] = vert(0.5f, 0.5f, 0.5f);

	vertices[20] = vert(0.5f, -0.5f, -0.5f);
	vertices[21] = vert(0.5f, 0.5f, -0.5f);
	vertices[22] = vert(-0.5f, -0.5f, -0.5f);
	vertices[23] = vert(-0.5f, 0.5f, -0.5f);

	for (int i = 0; i < 24; i += 4)
	{
		vertices[i + 0].uv = Vec2(0, 0);
		vertices[i + 1].uv = Vec2(1, 0);
		vertices[i + 2].uv = Vec2(0, 1);
		vertices[i + 3].uv = Vec2(1, 1);
	}

	for (int i = 0; i < 24; i += 4)
	{
		VAO.push_back(0 + i);
		VAO.push_back(2 + i);
		VAO.push_back(1 + i);
		VAO.push_back(3 + i);
		VAO.push_back(1 + i);
		VAO.push_back(2 + i);
	}

	ObjLoader obj_loader = ObjLoader();
	ObjModel* model = obj_loader.loadModel("test.obj");

	for (int i = 0; i < model->indices.size(); i++)
	{
		std::cout << model->indices[i] << std::endl;
	}

	std::cout << model->vertices.size() / 8 << std::endl;

	/*for (int i = 0; i < model->indices.size(); i++)
	{
		std::cout << model->vertices[i * 8 + 0] << " ";
		std::cout << model->vertices[i * 8 + 1] << " ";
		std::cout << model->vertices[i * 8 + 2] << "  ";
		std::cout << model->vertices[i * 8 + 3] << " ";
		std::cout << model->vertices[i * 8 + 4] << "  ";
		std::cout << model->vertices[i * 8 + 5] << " ";
		std::cout << model->vertices[i * 8 + 6] << " ";
		std::cout << model->vertices[i * 8 + 7] << std::endl;
	}*/

	for (int i = 0; i < 4; i++)
	{
		vertices[i].normal = Vec3(1, 0, 0);
	}

	for (int i = 0; i < 4; i++)
	{
		vertices[i + 4].normal = Vec3(0.5, 0, 0);
	}

	for (int i = 0; i < 4; i++)
	{
		vertices[i + 8].normal = Vec3(0, 1, 0);
	}

	for (int i = 0; i < 4; i++)
	{
		vertices[i + 12].normal = Vec3(0, 0.5, 0);
	}

	for (int i = 0; i < 4; i++)
	{
		vertices[i + 16].normal = Vec3(0, 0, 1);
	}

	for (int i = 0; i < 4; i++)
	{
		vertices[i + 20].normal = Vec3(0, 0, 0.5);
	}

	float angl = 0;
	for (angl = 0; angl < 3.14*2; angl += 0.03)
	{
		camera->setCamera(Vec3(2 * sin(angl), 0, 2 * cos(angl)), -Vec3(sin(angl), 0, cos(angl)), Vec3(0, 1, 0));
		vs->setUniform(&camera->getViewPerspectiveMatrix(), 0);
		pipeline.renderObject(model->vertices, model->indices);
		pipeline.saveRender(std::to_string(angl));
		g.addFrame(&pipeline.m_image_buffer[0]);
		pipeline.clearBuffers();
	}
	g.save("block.gif");
}
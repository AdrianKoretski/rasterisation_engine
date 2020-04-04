#include <iostream>
#include <random>
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
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

struct vert
{
	vert(float a, float b, float c, float d)
	{
		position = v4f(a, b, c, d);
	}
	v4f position;
	v3f color;
	v3f normal;
	v2f uv;
};

int main()
{
	uint width = 1920;
	uint height = 1080;

	Camera* camera = &Camera();
	camera->setPerspective(130, 16.f / 9);
	camera->setCamera(v3f(0, 0, 0), v3f(0, 0, -1), v3f(0, 1, 0));
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
	VBO.resize(24 * 12);
	vert* vertices = (vert*)VBO.data();
	vertices[0] = vert(0.5f, 0.5f, 0.5f, 1);
	vertices[1] = vert(0.5f, 0.5f, -0.5f, 1);
	vertices[2] = vert(0.5f, -0.5f, 0.5f, 1);
	vertices[3] = vert(0.5f, -0.5f, -0.5f, 1);

	vertices[4] = vert(-0.5f, -0.5f, 0.5f, 1);
	vertices[5] = vert(-0.5f, -0.5f, -0.5f, 1);
	vertices[6] = vert(-0.5f, 0.5f, 0.5f, 1);
	vertices[7] = vert(-0.5f, 0.5f, -0.5f, 1);

	vertices[8] = vert(-0.5f, 0.5f, 0.5f, 1);
	vertices[9] = vert(-0.5f, 0.5f, -0.5f, 1);
	vertices[10] = vert(0.5f, 0.5f, 0.5f, 1);
	vertices[11] = vert(0.5f, 0.5f, -0.5f, 1);

	vertices[12] = vert(0.5f, -0.5f, 0.5f, 1);
	vertices[13] = vert(0.5f, -0.5f, -0.5f, 1);
	vertices[14] = vert(-0.5f, -0.5f, 0.5f, 1);
	vertices[15] = vert(-0.5f, -0.5f, -0.5f, 1);

	vertices[16] = vert(-0.5f, -0.5f, 0.5f, 1);
	vertices[17] = vert(-0.5f, 0.5f, 0.5f, 1);
	vertices[18] = vert(0.5f, -0.5f, 0.5f, 1);
	vertices[19] = vert(0.5f, 0.5f, 0.5f, 1);

	vertices[20] = vert(0.5f, -0.5f, -0.5f, 1);
	vertices[21] = vert(0.5f, 0.5f, -0.5f, 1);
	vertices[22] = vert(-0.5f, -0.5f, -0.5f, 1);
	vertices[23] = vert(-0.5f, 0.5f, -0.5f, 1);

	for (int i = 0; i < 24; i += 4)
	{
		vertices[i + 0].uv = v2f(0, 0);
		vertices[i + 1].uv = v2f(1, 0);
		vertices[i + 2].uv = v2f(0, 1);
		vertices[i + 3].uv = v2f(1, 1);
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

	for (int i = 0; i < 4; i++)
	{
		vertices[i].color = v3f(1, 0, 0);
		vertices[i].normal = v3f(1, 0, 0);
	}

	for (int i = 0; i < 4; i++)
	{
		vertices[i + 4].color = v3f(0, 1, 1);
		vertices[i + 4].normal = v3f(0.5, 0, 0);
	}

	for (int i = 0; i < 4; i++)
	{
		vertices[i + 8].color = v3f(0, 1, 0);
		vertices[i + 8].normal = v3f(0, 1, 0);
	}

	for (int i = 0; i < 4; i++)
	{
		vertices[i + 12].color = v3f(1, 0, 1);
		vertices[i + 12].normal = v3f(0, 0.5, 0);
	}

	for (int i = 0; i < 4; i++)
	{
		vertices[i + 16].color = v3f(0, 0, 1);
		vertices[i + 16].normal = v3f(0, 0, 1);
	}

	for (int i = 0; i < 4; i++)
	{
		vertices[i + 20].color = v3f(1, 1, 0);
		vertices[i + 20].normal = v3f(0, 0, 0.5);
	}

	float angl = 0;
	for (angl = 0; angl < 3.14*2; angl += 0.1)
	{
		camera->setCamera(v3f(2 * sin(angl), 0, 2 * cos(angl)), -v3f(sin(angl), 0, cos(angl)), v3f(0, 1, 0));
		vs->setUniform(&camera->getViewPerspectiveMatrix(), 0);
		pipeline.renderObject(VBO, VAO);
		pipeline.saveRender("folder/" + std::to_string(angl));
		pipeline.clearBuffers();
	}
}
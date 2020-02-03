#include <iostream>
#include <random>
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Definitions.h"
#include "Pipeline/Pipeline.h"
#include "Scene/Camera.h"
#include <string>

#include "Pipeline/VertexShader/TestVertexShader.h"
#include "Pipeline/VertexPostProcessor/DefaultVPP.h"
#include "Pipeline/Rasterisation/Rasteriser.h"
#include "Pipeline/FragmentShader/TestFragmentShader.h"
#include "Pipeline/PerSampleProcessor/DefaultPSP.h"

struct vert
{
	vert(float a, float b, float c, float d)
	{
		position = v4f(a, b, c, d);
	}
	v4f position;
	v3f color;
};

int main()
{
	uint width = 1920;
	uint height = 1080;

	Camera* camera = &Camera();
	camera->setPerspective(130, 16.f / 9);
	camera->setCamera(v3f(0, 0, 2), v3f(0, 0, -1), v3f(0, 1, 0));
	Pipeline pipeline(1920, 1080, camera);

	TestVertexShader* vs = new TestVertexShader();
	DefaultVPP* vpp = new DefaultVPP();
	Rasteriser* r = new Rasteriser();
	TestFragmentShader* fs = new TestFragmentShader();
	DefaultPSP* psp = new DefaultPSP();

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
	pipeline.addPerSampleProcessor(psp);


	buffer<float> VBO;
	buffer<uint> VAO;
	VBO.resize(8 * 7);
	vert* vertices = (vert*)VBO.data();
	vertices[0] = vert( 0.5f, 0.5f, 0.5f, 1);
	vertices[1] = vert( 0.5f, 0.5f,-0.5f, 1);
	vertices[2] = vert( 0.5f,-0.5f, 0.5f, 1);
	vertices[3] = vert( 0.5f,-0.5f,-0.5f, 1);
	vertices[4] = vert(-0.5f, 0.5f, 0.5f, 1);
	vertices[5] = vert(-0.5f, 0.5f, -0.5f, 1);
	vertices[6] = vert(-0.5f, -0.5f, 0.5f, 1);
	vertices[7] = vert(-0.5f, -0.5f, -0.5f, 1);

	VAO.push_back(0);
	VAO.push_back(4);
	VAO.push_back(7);
	VAO.push_back(0);
	VAO.push_back(7);
	VAO.push_back(4);

	VAO.push_back(4);
	VAO.push_back(6);
	VAO.push_back(3);
	VAO.push_back(4);
	VAO.push_back(3);
	VAO.push_back(6);

	VAO.push_back(6);
	VAO.push_back(2);
	VAO.push_back(1);
	VAO.push_back(6);
	VAO.push_back(1);
	VAO.push_back(2);

	VAO.push_back(2);
	VAO.push_back(0);
	VAO.push_back(5);
	VAO.push_back(2);
	VAO.push_back(5);
	VAO.push_back(0);


	vertices[0].color = v3f(1, 0, 0);
	vertices[1].color = v3f(1, 1, 1);
	vertices[2].color = v3f(0, 1, 0);
	vertices[3].color = v3f(1, 1, 1);
	vertices[4].color = v3f(0, 0, 1);
	vertices[5].color = v3f(1, 1, 1);
	vertices[6].color = v3f(1, 1, 0);
	vertices[7].color = v3f(1, 1, 1);

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
#include <iostream>
#include <random>
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Definitions.h"
#include "Pipeline/Pipeline.h"
#include "Scene/Camera.h"

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
	m4f matrix = { 1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6 };
	float* fmat = (float*)&matrix;
	float* tst = new float[16];

	for (int i = 0; i < 16; i++)
		tst[i] = -1 - i;

	

	/*for (int i = 0; i < 16; i++)
		std::cout << fmat[i] << std::endl;*/

	Camera* camera = new Camera();
	camera->setCamera(v3f(0, 0, 2), v3f(0, 0, -1), v3f(0, 1, 0));
	Pipeline pipeline(320, 180, camera);

	buffer<float> VBO;
	buffer<uint> VAO;
	VBO.resize(3 * 7);
	vert* vertices = (vert*)VBO.data();
	vertices[0] = vert(0.5f, 0.5f, -0.5f, 1);
	vertices[1] = vert(-0.5f, 0.5f, -0.5f, 1);
	vertices[2] = vert(-0.5f, -0.5f, -1.5f, 1);
	/*vertices[0] = vert( 0.5f, 0.5f, 0.5f, 1);
	vertices[1] = vert( 0.5f, 0.5f,-0.5f, 1);
	vertices[2] = vert( 0.5f,-0.5f, 0.5f, 1);
	vertices[3] = vert( 0.5f,-0.5f,-0.5f, 1);
	vertices[4] = vert(-0.5f, 0.5f, 0.5f, 1);
	vertices[5] = vert(-0.5f, 0.5f, -0.5f, 1);
	vertices[6] = vert(-0.5f, -0.5f, 0.5f, 1);
	vertices[7] = vert(-0.5f, -0.5f, -0.5f, 1);*/

	VAO.push_back(0);
	VAO.push_back(1);
	VAO.push_back(2);

	/*VAO.push_back(0);
	VAO.push_back(4);
	VAO.push_back(7);

	VAO.push_back(4);
	VAO.push_back(6);
	VAO.push_back(3);

	VAO.push_back(6);
	VAO.push_back(2);
	VAO.push_back(1);
	
	VAO.push_back(2);
	VAO.push_back(0);
	VAO.push_back(5);*/


	vertices[0].color = v3f(1, 0, 0);
	vertices[1].color = v3f(0, 1, 0);
	vertices[2].color = v3f(0, 0, 1);
	/*vertices[3].color = v3f(0, 1, 0);
	vertices[4].color = v3f(1, 1, 1);
	vertices[5].color = v3f(0, 0, 1);
	vertices[6].color = v3f(1, 1, 1);
	vertices[7].color = v3f(1, 1, 0);

	for (int i = 0; i < 8; i++)
		vertices[i].color = v3f(1) - vertices[i].color;*/

	pipeline.renderObject(VBO, VAO);
}
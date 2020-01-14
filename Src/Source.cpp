#include <iostream>
#include <random>
#include "Pipeline/Pipeline.h"

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
	Pipeline pipeline(200, 200);

	buffer<float> VBO;
	buffer<unsigned int> VAO;
	VBO.resize(8 * 7);
	vert* vertices = (vert*)VBO.data();
	vertices[0] = vert( 0.5f, 0.5f, 0.5f, 1);
	vertices[1] = vert( 0.5f, 0.5f,-0.5f, 1);
	vertices[2] = vert( 0.5f,-0.5f, 0.5f, 1);
	vertices[3] = vert( 0.5f,-0.5f,-0.5f, 1);
	vertices[4] = vert(-0.5f, 0.5f, 0.5f, 1);
	vertices[5] = vert(-0.5f, 0.5f,-0.5f, 1);
	vertices[6] = vert(-0.5f,-0.5f, 0.5f, 1);
	vertices[7] = vert(-0.5f,-0.5f,-0.5f, 1);

	VAO.push_back(0);
	VAO.push_back(4);
	VAO.push_back(6);
	VAO.push_back(0);
	VAO.push_back(6);
	VAO.push_back(2);

	for (int i = 0; i < 16; i++)
		vertices[i].color = v3f((i >> 2) % 2, (i >> 1) % 2, i % 2);

	/*vertices[0] = vert(0.0f, -0.5f, 0, 1);
	vertices[1] = vert(0.0f, 0.5f, 0, 1);
	vertices[2] = vert(-0.5f, 0.f, 0, 1);
	vertices[0] = vert(0.15f, 0.55f, 0, 1);
	vertices[1] = vert(0.35f, 0.25f, 0, 1);
	vertices[2] = vert(0.95f, 0.85f, 0, 1);
	
	vertices[3] = vert(-0.75f, 0.5f, 0, 1);
	vertices[4] = vert(-0.5f, 0.25f, 0, 1);
	vertices[5] = vert(-0.25f, 0.75f, 0, 1);
	
	vertices[6] = vert(-0.35f, -0.25f, 0, 1);
	vertices[7] = vert(-0.75f, -0.25f, 0, 1);
	vertices[8] = vert(-0.25f, -0.75f, 0, 1);

	vertices[9] = vert(0.65f, -0.35f, 0, 1);
	vertices[10] = vert(0.25f, -0.25f, 0, 1);
	vertices[11] = vert(0.75f, -0.75f, 0, 1);

	vertices[12] = vert(0.95f, 0.25f, 0, 1);
	vertices[13] = vert(0.15f, 0.85f, 0, 1);

	vertices[14] = vert(-0.95f, 0.25f, 0, 1);
	vertices[15] = vert(-0.95f, 0.75f, 0, 1);

	//for (int i = 0; i < 16; i++)
		//vertices[i].color = v3f((float(rand() % 101)) / 100, (float(rand() % 101)) / 100, (float(rand() % 101)) / 100);
	for (int i = 0; i < 16; i++)
		vertices[i].color = v3f((i>>2)%2, (i>>1)%2, i%2);

	VAO.push_back(0);
	VAO.push_back(1);
	VAO.push_back(2);
	VAO.push_back(3);
	VAO.push_back(4);
	VAO.push_back(5);
	VAO.push_back(6);
	VAO.push_back(7);
	VAO.push_back(8);
	VAO.push_back(9);
	VAO.push_back(10);
	VAO.push_back(11);
	VAO.push_back(2);
	VAO.push_back(1);
	VAO.push_back(12);
	VAO.push_back(0);
	VAO.push_back(2);
	VAO.push_back(13);
	VAO.push_back(4);
	VAO.push_back(3);
	VAO.push_back(14);
	VAO.push_back(3);
	VAO.push_back(15);
	VAO.push_back(14);
	VAO.push_back(3);
	VAO.push_back(5);
	VAO.push_back(15);

	VAO.push_back(13);
	VAO.push_back(5);
	VAO.push_back(0);
	VAO.push_back(5);
	VAO.push_back(4);
	VAO.push_back(0);
	VAO.push_back(0);
	VAO.push_back(4);
	VAO.push_back(1);

	VAO.push_back(4);
	VAO.push_back(14);
	VAO.push_back(7);
	VAO.push_back(4);
	VAO.push_back(7);
	VAO.push_back(6);
	VAO.push_back(1);
	VAO.push_back(4);
	VAO.push_back(6);

	VAO.push_back(1);
	VAO.push_back(6);
	VAO.push_back(10);
	VAO.push_back(12);
	VAO.push_back(1);
	VAO.push_back(9);
	VAO.push_back(9);
	VAO.push_back(1);
	VAO.push_back(10);

	VAO.push_back(12);
	VAO.push_back(9);
	VAO.push_back(11);
	VAO.push_back(10);
	VAO.push_back(6);
	VAO.push_back(8);
	VAO.push_back(10);
	VAO.push_back(8);
	VAO.push_back(11);*/

	pipeline.renderObject(VBO, VAO);
}
#include <iostream>
#include <random>
#include "Definitions.h"
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
	Pipeline pipeline(2000, 2000);

	buffer<float> VBO;
	buffer<uint> VAO;
	VBO.resize(12 * 7);
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

	VAO.push_back(4);
	VAO.push_back(6);
	VAO.push_back(3);

	VAO.push_back(6);
	VAO.push_back(2);
	VAO.push_back(1);
	
	VAO.push_back(2);
	VAO.push_back(0);
	VAO.push_back(5);

	for (int i = 0; i < 12; i++)
		vertices[i].color = v3f((i >> 2) % 2, (i >> 1) % 2, i % 2);

	pipeline.renderObject(VBO, VAO);
}
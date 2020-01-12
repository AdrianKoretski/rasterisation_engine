#include <iostream>

#include "Pipeline/Pipeline.h"

int main()
{
	Pipeline pipeline(40, 40);

	buffer<float> VBO;
	VBO.resize(64);
	v4f* vertices = (v4f*)VBO.data();
	vertices[0] = v4f(0.0f, -0.5f, 0, 1);
	vertices[1] = v4f(0.0f, 0.5f, 0, 1);
	vertices[2] = v4f(-0.5f, 0.f, 0, 1);
	vertices[0] = v4f(0.15f, 0.55f, 0, 1);
	vertices[1] = v4f(0.35f, 0.25f, 0, 1);
	vertices[2] = v4f(0.95f, 0.85f, 0, 1);
	
	vertices[3] = v4f(-0.75f, 0.5f, 0, 1);
	vertices[4] = v4f(-0.5f, 0.25f, 0, 1);
	vertices[5] = v4f(-0.25f, 0.75f, 0, 1);
	
	vertices[6] = v4f(-0.35f, -0.25f, 0, 1);
	vertices[7] = v4f(-0.75f, -0.25f, 0, 1);
	vertices[8] = v4f(-0.25f, -0.75f, 0, 1);

	vertices[9] = v4f(0.65f, -0.35f, 0, 1);
	vertices[10] = v4f(0.25f, -0.25f, 0, 1);
	vertices[11] = v4f(0.75f, -0.75f, 0, 1);

	vertices[12] = v4f(0.95f, 0.25f, 0, 1);
	vertices[13] = v4f(0.15f, 0.85f, 0, 1);

	vertices[14] = v4f(-0.95f, 0.25f, 0, 1);
	vertices[15] = v4f(-0.95f, 0.75f, 0, 1);
	
	buffer<unsigned int> VAO;
	/*VAO.push_back(0);
	VAO.push_back(1);
	VAO.push_back(2);*/
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
	VAO.push_back(11);



	pipeline.renderObject(VBO, VAO);
}
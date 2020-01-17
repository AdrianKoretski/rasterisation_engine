#include <iostream>
#include <random>
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "Definitions.h"
#include "Pipeline/Pipeline.h"
#include "Scene/Camera.h"
#include <string>

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
	Camera* camera = &Camera();
	camera->setCamera(v3f(0, 0, 2), v3f(0, 0, -1), v3f(0, 1, 0));
	Pipeline pipeline(1920, 1080, camera);

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
		camera->setCamera(v3f(sin(angl), 0, cos(angl)), -v3f(sin(angl), 0, cos(angl)), v3f(0, 1, 0));
		pipeline.renderObject(VBO, VAO);
		pipeline.saveRender(std::to_string(angl));
		pipeline.clearBuffers();
	}
}
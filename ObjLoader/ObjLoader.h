#pragma once

#include "Vec2.h"
#include "Vec3.h"
#include "ObjModel.h"
#include <vector>
#include <string>

class ObjLoader
{
public:
	ObjLoader();
	ObjModel* loadModel(std::string file_name);
private:
	void processLine(std::string line);
	std::vector<std::string> splitLine(std::string line, char delimiter);
	void skipLine();
	int getPreviousIndex(int index);
	bool compare(int index, int i);

	std::vector<Vec3> positions;
	std::vector<Vec3> normals;
	std::vector<Vec2> uv;
	std::vector<unsigned int> input_indices;
	int m_line_counter = 0;
	int m_vertex_size = -1;
};
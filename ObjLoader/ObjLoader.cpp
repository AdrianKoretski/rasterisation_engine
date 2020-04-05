#include "ObjLoader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iterator>

ObjLoader::ObjLoader()
{
}

ObjModel* ObjLoader::loadModel(std::string file_name)
{
	positions.clear();
	normals.clear();
	uv.clear();
	input_indices.clear();
	m_line_counter = 0;

	std::ifstream input_file(file_name);

	if (!input_file.is_open())
	{
		std::cout << "ERROR: Could not open file." << std::endl;
		return NULL;
	}

	std::string line;
	while (std::getline(input_file, line))
		processLine(line);

	for (int i = 0; i < positions.size(); i++)
		std::cout << "position " << positions[i].x << " " << positions[i].y << " " << positions[i].z << std::endl;
	for (int i = 0; i < normals.size(); i++)
		std::cout << "normals " << normals[i].x << " " << normals[i].y << " " << normals[i].z << std::endl;
	for (int i = 0; i < uv.size(); i++)
		std::cout << "uv " << uv[i].x << " " << uv[i].y << std::endl;
	for (int i = 0; i < input_indices.size(); i++)
		std::cout << "input_indices " << input_indices[i] << std::endl;

	ObjModel* model = new ObjModel();
	int index_counter = 0;
	for (int i = 0; i < input_indices.size() / m_vertex_size; i++)
	{
		int index = getPreviousIndex(i);
		if (index == -1)
		{
			model->indices.push_back(index_counter);
			model->vertices.push_back(positions[input_indices[i * m_vertex_size + 0]-1].x);
			model->vertices.push_back(positions[input_indices[i * m_vertex_size + 0]-1].y);
			model->vertices.push_back(positions[input_indices[i * m_vertex_size + 0]-1].z);
			model->vertices.push_back(uv[input_indices[i * m_vertex_size + 1]-1].x);
			model->vertices.push_back(uv[input_indices[i * m_vertex_size + 1]-1].y);
			model->vertices.push_back(normals[input_indices[i * m_vertex_size + 2]-1].x);
			model->vertices.push_back(normals[input_indices[i * m_vertex_size + 2]-1].y);
			model->vertices.push_back(normals[input_indices[i * m_vertex_size + 2]-1].z);
			index_counter++;
		}
		else
			model->indices.push_back(model->indices[index]);
	}
	return model;
}

void ObjLoader::processLine(std::string line)
{
	m_line_counter++;
	std::vector<std::string> tokens = splitLine(line, ' ');
	if (tokens.size() == 0)
		return;
	if (!tokens[0].compare("v"))
	{
		if (tokens.size() != 4)
		{
			skipLine();
			return;
		}
		positions.push_back(Vec3(atof(tokens[1].c_str()), atof(tokens[2].c_str()), atof(tokens[3].c_str())));
	}
	else if (!tokens[0].compare("vt"))
	{
		if (tokens.size() != 3)
		{
			skipLine();
			return;
		}
		uv.push_back(Vec2(atof(tokens[1].c_str()), atof(tokens[2].c_str())));
	}
	else if (!tokens[0].compare("vn"))
	{
		if (tokens.size() != 4)
		{
			skipLine();
			return;
		}
		normals.push_back(Vec3(atof(tokens[1].c_str()), atof(tokens[2].c_str()), atof(tokens[3].c_str())));
	}
	else if (!tokens[0].compare("f"))
	{
		if (tokens.size() != 4)
		{
			skipLine();
			return;
		}
		if (m_vertex_size == -1)
			m_vertex_size = splitLine(tokens[1], '/').size();
		for (int i = 1; i < 4; i++)
		{
			std::vector<std::string> indices = splitLine(tokens[i], '/');
			for (int i = 0; i < m_vertex_size; i++)
				input_indices.push_back(atoi(indices[i].c_str()));
		}
	}
	else
		skipLine();
}

std::vector<std::string> ObjLoader::splitLine(std::string line, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(line);
	while (std::getline(tokenStream, token, delimiter))
		tokens.push_back(token);
	return tokens;
}

void ObjLoader::skipLine()
{
	std::cout << "ERROR: Could not read line " << m_line_counter << ". This line will be skipped." << std::endl;
}

int ObjLoader::getPreviousIndex(int index)
{
	for (int i = 0; i < index; i++)
	{
		if (compare(index, i))
			return i;
	}
	return -1;
}

bool ObjLoader::compare(int index, int i)
{
	for (int j = 0; j < m_vertex_size; j++)
		if (input_indices[index * m_vertex_size + j] != input_indices[i * m_vertex_size + j])
			return false;
	return true;
}

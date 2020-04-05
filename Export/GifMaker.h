#pragma once

#include <string>
#include <vector>

class GifMaker
{
public:
	GifMaker(int width, int height);

	void addFrame(float* frame);
	void save(std::string file_name);
private:
	int m_width;
	int m_height;

	std::vector<uint8_t*> m_frames;
};
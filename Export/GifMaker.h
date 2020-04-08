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
	int m_frame_counter = 0;
	char* m_frame;
};
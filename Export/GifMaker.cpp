#include "GifMaker.h"
#include "gif.h"

GifMaker::GifMaker(int width, int height)
{
	m_width = width;
	m_height = height;
}

void GifMaker::addFrame(float* frame)
{
	uint8_t* new_frame = (uint8_t*)malloc(sizeof(uint8_t) * 4 * m_width * m_height);
	for (int i = 0; i < m_width * m_height; i++)
	{
		new_frame[i * 4 + 0] = frame[i * 3 + 0] * 255;
		new_frame[i * 4 + 1] = frame[i * 3 + 1] * 255;
		new_frame[i * 4 + 2] = frame[i * 3 + 2] * 255;
		new_frame[i * 4 + 3] = 0;
	}
	m_frames.push_back(new_frame);
}

void GifMaker::save(std::string file_name)
{
	GifWriter g;
	GifBegin(&g, file_name.c_str(), m_width, m_height, 2);
	for (int i = 0; i < m_frames.size(); i += 1)
		GifWriteFrame(&g, m_frames[i], m_width, m_height, 2);
	GifEnd(&g);
}
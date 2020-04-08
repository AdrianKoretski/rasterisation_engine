#include "GifMaker.h"
#include "gif.h"
#include <iostream>
#include <fstream>

GifMaker::GifMaker(int width, int height)
{
	m_width = width;
	m_height = height;
	m_frame = (char*)malloc(sizeof(char) * 4 * m_width * m_height);
}

void GifMaker::addFrame(float* frame)
{
	std::ofstream myfile;
	myfile.open("temp_gif_"+ std::to_string(m_frame_counter));
	m_frame_counter++;
	for (int i = 0; i < m_width * m_height; i++)
	{
		m_frame[i * 4 + 0] = frame[i * 3 + 0] * 255;
		m_frame[i * 4 + 1] = frame[i * 3 + 1] * 255;
		m_frame[i * 4 + 2] = frame[i * 3 + 2] * 255;
		m_frame[i * 4 + 3] = 0;
	}
	myfile.write(m_frame, 4 * m_width * m_height);
	myfile.close();
}

void GifMaker::save(std::string file_name)
{
	GifWriter g;
	std::ifstream myfile;
	GifBegin(&g, file_name.c_str(), m_width, m_height, 2);
	for (int i = 0; i < m_frame_counter; i++)
	{
		myfile.open("temp_gif_" + std::to_string(i));
		myfile.read(m_frame, 4 * m_width * m_height);
		GifWriteFrame(&g, (uint8_t*)m_frame, m_width, m_height, 2);
		myfile.close();
		remove(("temp_gif_" + std::to_string(i)).c_str());
	}
	free(m_frame);
	GifEnd(&g);
}
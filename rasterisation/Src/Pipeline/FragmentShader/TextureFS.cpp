#include "TextureFS.h"

TextureFS::TextureFS()
{
	setIODataSize();
	setupUniforms();
}

void TextureFS::setup() {
}

void TextureFS::reset() {
}

void TextureFS::shadeFragment(float* output_fragment, float* inupt_fragment)
{
	Vec2* uv = (Vec2*)(&inupt_fragment[4]);
	memcpy(output_fragment, inupt_fragment, m_input_data_size * sizeof(float));
	if (((uv->y * 4) - 0.5 - floor(uv->y * 4)) * ((uv->x * 4) - 0.5 - floor(uv->x * 4)) > 0)
		output_fragment[4] = 1;
	else
		output_fragment[4] = 0;
	output_fragment[5] = 1;
	output_fragment[6] = 1;
}

void TextureFS::setIODataSize()
{
	m_input_data_size = 9;
	m_output_data_size = 9;
}

void TextureFS::setupUniforms()
{
}
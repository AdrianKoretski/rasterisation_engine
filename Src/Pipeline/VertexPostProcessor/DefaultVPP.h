#pragma once

#include "VertexPostProcessor.h"

class DefaultVPP : public VertexPostProcessor
{
public:
	DefaultVPP();
	void postProcessVertices(
		buffer<float>& output_VBO, buffer<uint>& output_VAO,
		buffer<float>& input_VBO, buffer<uint>& input_VAO);
protected:
	void setIODataSize();
	void setupUniforms();
private:
	uint* m_width_resolution;
	uint* m_height_resolution;
};
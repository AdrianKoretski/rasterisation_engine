#pragma once

#include "PerSampleProcessor.h"

class DefaultPSP : public PerSampleProcessor
{
public:
	DefaultPSP();
	void setup();
	void reset();
protected:
	void postProcessFragment(buffer<float>& output_fragment, float* input_fragment);
	void setIODataSize();
	void setupUniforms();
private:
	uint* m_depth_buffer_width;
	uint* m_depth_buffer_height;
};
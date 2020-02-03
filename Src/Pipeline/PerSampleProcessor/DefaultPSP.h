#pragma once

#include "PerSampleProcessor.h"

class DefaultPSP : public PerSampleProcessor
{
public:
	DefaultPSP();
	void clearBuffer();
	void setupBuffer();
protected:
	void postProcessFragment(buffer<float>& output_fragment, float* input_fragment);
	void setIOFragmentSizes();
	void setupUniforms();
private:
	uint* m_depth_buffer_width;
	uint* m_depth_buffer_height;
};
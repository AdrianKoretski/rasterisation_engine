#pragma once

#include "..//..//Definitions.h"
#include "../Uniform.h"

class PerSampleProcessor : public Uniform
{
public:
	PerSampleProcessor();
	void postProcessFragments(buffer<float>& output_fragment, buffer<float>& input_fragment);
	virtual void setupBuffer() = 0;
	virtual void clearBuffer() = 0;
protected:
	virtual void postProcessFragment(buffer<float>& output_fragment, float* input_fragment) = 0;
	virtual void setIOFragmentSizes() = 0;

	uint m_input_fragment_size = 4;
	float* m_depth_buffer;
	uint m_depth_buffer_width = 1920;
	uint m_depth_buffer_height = 1080;
};


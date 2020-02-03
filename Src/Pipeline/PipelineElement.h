#pragma once

#include "../Definitions.h"

class PipelineElement
{
public:
	PipelineElement();
	void setUniform(void* uniform, uint index);
	uint getInputDataSize();
	uint getOutputDataSize();

	virtual void setup() = 0;
	virtual void reset() = 0;
protected:
	virtual void setupUniforms() = 0;
	virtual void setIODataSize() = 0;

	buffer<void*> m_uniform;
	buffer<uint> m_uniform_size;

	uint m_input_data_size = 4;
	uint m_output_data_size = 4;
};
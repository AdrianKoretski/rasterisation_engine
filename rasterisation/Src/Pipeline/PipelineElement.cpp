#include "PipelineElement.h"

PipelineElement::PipelineElement() {
}

void PipelineElement::setUniform(void* uniform, uint index)
{
	memcpy(m_uniform[index], uniform, m_uniform_size[index]);
}

uint PipelineElement::getInputDataSize()
{
	return m_input_data_size;
}

uint PipelineElement::getOutputDataSize()
{
	return m_output_data_size;
}

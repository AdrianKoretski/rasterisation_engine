#include "Uniform.h"

Uniform::Uniform() {
}

void Uniform::setUniform(void* uniform, uint index)
{
	memcpy(m_uniform[index], uniform, m_uniform_size[index]);
}
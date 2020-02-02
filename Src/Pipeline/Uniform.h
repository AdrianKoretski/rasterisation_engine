#pragma once

#include "../Definitions.h"

class Uniform
{
public:
	Uniform();
	void setUniform(void* uniform, uint index);
protected:
	virtual void setupUniforms() = 0;

	buffer<void*> m_uniform;
	buffer<uint> m_uniform_size;
};
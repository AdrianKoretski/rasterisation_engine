#include "FragmentShader.h"
#include <stdlib.h>
#include <random>
#include <chrono>
#include <iostream>

FragmentShader::FragmentShader()
{
	std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(
		std::chrono::system_clock::now().time_since_epoch()
		);
	srand(ms.count());
	setColor();
}

void FragmentShader::shadeFragments(buffer<float>& output_fragment, buffer<float>& inupt_fragment)
{
	for (int i = 0; i < inupt_fragment.size(); i += 4)			// TODO: change 4 to a variable
		shadeFragment(output_fragment, &inupt_fragment[i]);
}

void FragmentShader::setColor()
{
	color = v3f((float(rand() % 100)) / 100, (float(rand() % 100)) / 100, (float(rand() % 100)) / 100);
	//color = v3f(0.1f, 0.1f, 0.1f);
}

void FragmentShader::shadeFragment(buffer<float>& output_fragment, float* inupt_fragment)
{
	output_fragment.push_back(inupt_fragment[0]);
	output_fragment.push_back(inupt_fragment[1]);
	output_fragment.push_back(color.x);
	output_fragment.push_back(color.y);
	output_fragment.push_back(color.z);
}

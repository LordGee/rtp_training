#pragma once

#include <math.h>

namespace rtp1
{
	namespace my_math
	{
		static float Sigmoid(float a, float p) {
			float ap = (-a) / p;
			return (1 / (1 + exp(ap)));
		}
	}
}
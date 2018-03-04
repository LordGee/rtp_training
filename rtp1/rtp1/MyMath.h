#pragma once

#include <math.h>

namespace rtp1
{
	namespace my_math
	{
		/* Returns a sigmoid result as part of the activation 
		 * function when evaluating neurons */
		static float Sigmoid(float a, float p) {
			float ap = (-a) / p;
			return (1 / (1 + exp(ap)));
		}
	}
}
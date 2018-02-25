#pragma once
#include <vector>

namespace rtp1
{
	
	class Neuron {
	public:
		int						p_NumberOfInputs;
		std::vector<float>		p_Weights;

	public:
		Neuron() {
			p_NumberOfInputs = 0;
		}

	};

}
#pragma once
#include <vector>

using namespace System;
using namespace System::Collections::Generic;

namespace rtp1
{
	
	public ref class Neuron {
	public:
		int p_NumberOfInputs;
		std::vector<float> *p_Weights;

	public:
		Neuron() {
			p_NumberOfInputs = 0;
			p_Weights = new std::vector<float>;
		}

	};

}
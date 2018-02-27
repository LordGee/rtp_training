#pragma once
#include <vector>

namespace rtp1
{
	
	class Neuron {
	public:
		int						p_NumberOfInputs;
		float					* p_Weights, * p_WeightChanges, * p_BiasValues, * p_BiasWeights;
		float					p_NeuronValue, p_DesiredValue, p_Error;

	public:
		Neuron() {
			p_NumberOfInputs = 0;
		}

	};

}
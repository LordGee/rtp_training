#pragma once
using namespace System;
using namespace System::Collections::Generic;

namespace rtp1
{
	
	public ref class Neuron {
	public:
		int p_NumberOfInputs;
		List<float>^ p_Weights;

	public:
		Neuron() {
			p_NumberOfInputs = 0;
			p_Weights = gcnew List<float>();
		}

	};

}
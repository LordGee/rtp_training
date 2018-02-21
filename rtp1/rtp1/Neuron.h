#pragma once
using namespace System;
using namespace System::Collections::Generic;

namespace rtp1
{
	
	public ref class Neuron {
	public:
		int numberOfInputs;
		List<float>^ weights;

	public:
		Neuron() {
			numberOfInputs = 0;
			weights = gcnew List<float>();
		}

	};

}
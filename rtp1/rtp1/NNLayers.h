#pragma once

#include "Neuron.h"

using namespace System;
using namespace System::Collections::Generic;

namespace rtp1
{
	ref class NNLayer {
	private:
		int totalNeurons;
		List<Neuron^>^ neurons;

	public:
		NNLayer() {
			totalNeurons = -1;
			neurons = gcnew List<Neuron^>;
		}
	};
}
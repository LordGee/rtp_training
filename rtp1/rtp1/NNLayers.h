#pragma once

#include "Neuron.h"

using namespace System;
using namespace System::Collections::Generic;

namespace rtp1
{
	ref class NNLayer {
	private:
		int m_TotalNeurons;
		List<Neuron^>^ m_Neurons;

	public:
		NNLayer() {
			m_TotalNeurons = -1;
			m_Neurons = gcnew List<Neuron^>;
		}
		void Evaluate(List<float> input, List<float> %output);

	protected:
		void SaveLayer(const char* %filename);
		void LoadLayer(List<Neuron^> neuron);
		

}
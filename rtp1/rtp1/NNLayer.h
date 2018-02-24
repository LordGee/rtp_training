#pragma once

#include <vector>
#include "Neuron.h"
#include "MyMath.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace rtp1::my_math;

namespace rtp1
{

	public ref class NNLayer {
	private:
		int m_TotalNeurons;
		List<Neuron^>^ m_Neurons;

	public:
		NNLayer() {
			m_TotalNeurons = -1;
			m_Neurons = gcnew List<Neuron^>;
		}
		// void Evaluate(List<float> input, List<float>% output);
	public: void Evaluate(List<float> input, std::vector<float> &output);
		void SetNeurons(List<Neuron^>^ neurons, int numberOfNeurons);

	protected:
		void SaveLayer(const char* %filename);
		void LoadLayer(List<Neuron^> neuron);

	};
}
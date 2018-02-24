#pragma once

#include <vector>
#include "Neuron.h"
#include "MyMath.h"

using namespace rtp1::my_math;

namespace rtp1
{

	class NNLayer {
	private:
		int m_TotalNeurons;
		std::vector<Neuron> *m_Neurons;

	public:
		NNLayer() {
			m_TotalNeurons = -1;
			m_Neurons = new std::vector<Neuron>;
		}
		//void Evaluate(List<float> input, List<float> output);
		void Evaluate(std::vector<float> input, std::vector<float> &output);
		void SetNeurons(std::vector<Neuron> neurons, int numberOfNeurons);

	protected:
		void SaveLayer(const char* %filename);
		void LoadLayer(std::vector<Neuron> neuron);

	};
}
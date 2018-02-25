#pragma once

#include <vector>
#include "Neuron.h"
#include "MyMath.h"

using namespace rtp1::my_math;

namespace rtp1
{

	class NNLayer {
	private:
		std::vector<Neuron>		m_Neurons;
		std::vector<float>		m_Errors, m_BiasValues;

	public:
		unsigned int			p_TotalNeurons, p_NumberOfChildNeurons, p_NumberOfParentNeurons;
		float					p_LearningRate, p_MomentumFactor;
		bool					p_LinearOutput, p_UseMomentum;

	public:
		NNLayer() {
			p_TotalNeurons = -1;
		}
		void Evaluate(std::vector<float> input, std::vector<float> &output);
		void SetNeurons(std::vector<Neuron> neurons, int numberOfNeurons);
		void SaveLayer(const char* %filename);
		void LoadLayer(std::vector<Neuron> neuron);

		void RandomiseWeights(int min, int max);
		void CalculateErrors();
		void AdjustWeights();
		void CalculateNeuronValues();

	};
}
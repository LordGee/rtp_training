#pragma once

#include "NNLayer.h";
#include <vector>;

using namespace System;
using namespace System::Collections::Generic;

namespace rtp1
{
	class NeuralNetwork {
	private:
		unsigned int				m_InputAmount, m_OutputAmount;
		std::vector<float>			m_Inputs, m_Outputs;
		NNLayer						m_InputLayer, m_OutputLayer;
		std::vector<NNLayer>		m_HiddenLayers;

	public:
		NeuralNetwork() {
			// m_InputLayer = NULL;
			// m_OutputLayer = NULL;
		}
		~NeuralNetwork() { ClearNN(); }

		void Initialise(unsigned int input, unsigned int hidden, unsigned int noHidden, unsigned int output);

		void SetInput(std::vector<float> inputs);
		void UpdateNeuralNetwork();
		float GetOutput(int index);
		void WriteNNToFile(const char* filename);
		void ReadNNFromFile(const char* filename);
		void ClearNN();
		void PopulateNeurons(int input, int hidden, int output);

		void SetDesiredOutput(int index, float value);
		void FeedForward();
		void BackPropagate();
		int GetMaxOutputID();
		float CalculateError();
		void SetLearningRate(float rate);
		void SetLinearOutput(bool useLinear);
		void SetMomentum(bool useMomentum, float factor);


	};
}
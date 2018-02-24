#pragma once

#include "NNLayer.h";
#include <vector>;

using namespace System;
using namespace System::Collections::Generic;

namespace rtp1
{
	public ref class NeuralNetwork {
	private:
		int m_InputAmount, m_OutputAmount;
		std::vector<float> *m_Inputs, *m_Outputs;
		NNLayer *m_InputLayer, *m_OutputLayer;
		std::vector<NNLayer> *m_HiddenLayers;

	public:
		NeuralNetwork() {
			m_InputLayer = new NNLayer();
			m_OutputLayer = new NNLayer();
			m_Inputs = new std::vector<float>;
			m_Outputs = new std::vector<float>;
			m_HiddenLayers = new std::vector<NNLayer>;
		}
		~NeuralNetwork() { ClearNN(); }

		void SetInput(std::vector<float> inputs);
		void UpdateNeuralNetwork();
		float GetOutput(int index);
		void WriteNNToFile(const char* filename);
		void ReadNNFromFile(const char* filename);
		void ClearNN();
		void PopulateNeurons(int input, int hidden, int output);

	};
}
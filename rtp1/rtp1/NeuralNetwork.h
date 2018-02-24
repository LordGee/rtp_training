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
		List<float>^ m_Inputs;
		// List<float>^ m_Outputs;
		std::vector<float>* m_Outputs;
		NNLayer ^m_InputLayer, ^m_OutputLayer;
		List<NNLayer^> ^m_HiddenLayers;

	public:
		NeuralNetwork() {
			m_InputLayer = gcnew NNLayer();
			m_OutputLayer = gcnew NNLayer();
			m_HiddenLayers = gcnew List<NNLayer^>;
			// m_Outputs = gcnew List<float>;
			m_Outputs = new std::vector<float>;
		}
		~NeuralNetwork() { ClearNN(); }

		void SetInput(List<float> ^input);
		void UpdateNeuralNetwork();
		float GetOutput(int index);
		void WriteNNToFile(const char* filename);
		void ReadNNFromFile(const char* filename);
		void ClearNN();
		void PopulateNeurons(int input, int hidden, int output);

	};
}
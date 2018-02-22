#pragma once

#include "NNLayer.h";

using namespace System;
using namespace System::Collections::Generic;

namespace rtp1
{
	ref class NeuralNetwork {
	private:
		int m_InputAmount, m_OutputAmount;
		List<float> ^m_Inputs, ^m_Outputs;
		NNLayer ^m_InputLayer, ^m_OutputLayer;
		List<NNLayer^> ^m_HiddenLayers;

	public:
		NeuralNetwork() {
			m_InputLayer = gcnew NNLayer();
			m_OutputLayer = gcnew NNLayer();
			m_HiddenLayers = gcnew List<NNLayer^>;
			m_Outputs = gcnew List<float>;
		}
		~NeuralNetwork()
		{
			if (m_InputLayer != nullptr) {
				m_InputLayer = nullptr;
			}
			if (m_OutputLayer != nullptr) {
				m_OutputLayer = nullptr;
			}
			for (int i = 0; i < m_HiddenLayers->Count; i ++) {
				if (m_HiddenLayers[i] != nullptr) {
					m_HiddenLayers[i] = nullptr;
				}
			}
			m_HiddenLayers->Clear();
		}
		void SetInput(List<float> input);

		

	};
}
#include "NeuralNetwork.h";

void rtp1::NeuralNetwork::SetInput(std::vector<float> inputs)
{
	m_Inputs = &inputs;
}

void rtp1::NeuralNetwork::UpdateNeuralNetwork()
{
	m_Outputs = new std::vector<float>;
	// m_Outputs = new std::vector<float>;
	for (int i = 0; i < m_HiddenLayers->size(); i++) {
		if (i > 0) {
			m_Inputs = m_Outputs;
		}	
		m_HiddenLayers->at(i).Evaluate(*m_Inputs, *m_Outputs);
	}
	m_Inputs = m_Outputs;
	m_OutputLayer->Evaluate(*m_Inputs, *m_Outputs);
}

float rtp1::NeuralNetwork::GetOutput(int index)
{

}

void rtp1::NeuralNetwork::WriteNNToFile(const char* filename)
{

}

void rtp1::NeuralNetwork::ReadNNFromFile(const char* filename)
{

}

void rtp1::NeuralNetwork::ClearNN()
{
	if (m_InputLayer != nullptr) {
		m_InputLayer = nullptr;
	}
	if (m_OutputLayer != nullptr) {
		m_OutputLayer = nullptr;
	}
	for (int i = 0; i < m_HiddenLayers->size(); i++) {
		if (m_HiddenLayers->at(i) != nullptr) {
			m_HiddenLayers->at(i) = nullptr;
		}
	}
	m_HiddenLayers->capacity = nullptr;
}

void rtp1::NeuralNetwork::PopulateNeurons(int input, int hidden, int output)
{

}


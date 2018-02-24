#include "NNLayer.h";

void rtp1::NNLayer::Evaluate(const std::vector<float> input, std::vector<float> &output)
{
	int inputIndex = 0;
	for (int i = 0; i < m_TotalNeurons; i++) {
		float activation = 0.0f;
		for (int j = 0; j < m_Neurons->at(i)->p_NumberOfInputs - 1; j++) {
			activation += input[inputIndex] * m_Neurons->at(i)->p_Weights[j];
			inputIndex++;
		}
		activation += m_Neurons->at(i)->p_Weights[m_Neurons->at(i)->p_NumberOfInputs] * 1;
		output.push_back(Sigmoid(activation, 1.0f));
		inputIndex = 0;
	}
}

void rtp1::NNLayer::SetNeurons(std::vector<Neuron> neurons, int numberOfNeurons)
{
	m_TotalNeurons = numberOfNeurons;
	m_Neurons = &neurons;
}

void rtp1::NNLayer::SaveLayer(const char* %filename)
{

}

void rtp1::NNLayer::LoadLayer(std::vector<Neuron> neuron)
{

}


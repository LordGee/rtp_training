#include "NeuralNetwork.h";

void rtp1::NeuralNetwork::Initialise(unsigned int input, unsigned int hidden, unsigned int noHidden, unsigned int output)
{
	for (int i = 0; i < noHidden; i++) {
		NNLayer temp;
		m_HiddenLayers.push_back(temp);
	}

	m_InputLayer.p_TotalNeurons = input;
	m_InputLayer.p_NumberOfChildNeurons = hidden;
	m_InputLayer.p_NumberOfParentNeurons = 0;
	m_InputLayer.Initialise(NULL, &m_HiddenLayers[0]);
	m_InputLayer.RandomiseWeights(0, 200);

	for (int i = 0; i < noHidden; i++) {
		NNLayer temp;
		m_HiddenLayers.push_back(temp);
		m_HiddenLayers[i].p_TotalNeurons = hidden;
		if (noHidden == 1) {
			m_HiddenLayers[i].p_NumberOfChildNeurons = output;
			m_HiddenLayers[i].p_NumberOfParentNeurons = input;
			m_HiddenLayers[i].Initialise(&m_InputLayer, &m_OutputLayer);
		} else if (noHidden > 1) {
			if (i == 0) {
				m_HiddenLayers[i].p_NumberOfChildNeurons = hidden;
				m_HiddenLayers[i].p_NumberOfParentNeurons = input;
				m_HiddenLayers[i].Initialise(&m_InputLayer, &m_HiddenLayers[1]);
			} else if (i + 1 == noHidden) {
				m_HiddenLayers[i].p_NumberOfChildNeurons = output;
				m_HiddenLayers[i].p_NumberOfParentNeurons = hidden;
				m_HiddenLayers[i].Initialise(&m_HiddenLayers[i - 1], &m_OutputLayer);
			}
			else {
				m_HiddenLayers[i].p_NumberOfChildNeurons = hidden;
				m_HiddenLayers[i].p_NumberOfParentNeurons = hidden;
				m_HiddenLayers[i].Initialise(&m_HiddenLayers[i - 1], &m_HiddenLayers[i + 1]);
			}
		}
		m_HiddenLayers[i].RandomiseWeights(0, 200);
	}
	
	m_OutputLayer.p_TotalNeurons = input;
	m_OutputLayer.p_NumberOfChildNeurons = hidden;
	m_OutputLayer.p_NumberOfParentNeurons = 0;
	m_OutputLayer.Initialise(&m_HiddenLayers[noHidden - 1], NULL);
	m_OutputLayer.RandomiseWeights(0, 200);
}

void rtp1::NeuralNetwork::SetLearningRate(float rate)
{
	m_InputLayer.p_LearningRate = rate;
	for (int i = 0; i < m_HiddenLayers.size(); i++)	{
		m_HiddenLayers[i].p_LearningRate = rate;
	}
	m_OutputLayer.p_LearningRate = rate;
}

void rtp1::NeuralNetwork::SetInput(std::vector<float> inputs)
{
	m_Inputs = inputs;
}

void rtp1::NeuralNetwork::UpdateNeuralNetwork()
{
	m_Outputs.clear();
	for (int i = 0; i < m_HiddenLayers.size(); i++) {
		if (i > 0) {
			m_Inputs = m_Outputs;
		}	
		m_HiddenLayers[i].Evaluate(m_Inputs, m_Outputs);
	}
	m_Inputs = m_Outputs;
	m_OutputLayer.Evaluate(m_Inputs, m_Outputs);
}

float rtp1::NeuralNetwork::GetOutput(int index)
{
	if (index >= m_OutputAmount) {
		return 0.0f;
	}
	return m_Outputs[index];
}

void rtp1::NeuralNetwork::WriteNNToFile(const char* filename)
{

}

void rtp1::NeuralNetwork::ReadNNFromFile(const char* filename)
{

}

void rtp1::NeuralNetwork::ClearNN()
{
	m_InputLayer.CleanUp();
	for (int i = 0; i < m_HiddenLayers.size(); i++)	{
		m_HiddenLayers[i].CleanUp();
	}
	m_OutputLayer.CleanUp();
}

void rtp1::NeuralNetwork::PopulateNeurons(int input, int hidden, int output)
{

}

void rtp1::NeuralNetwork::SetDesiredOutput(int index, float value)
{

}

void rtp1::NeuralNetwork::FeedForward()
{

}

void rtp1::NeuralNetwork::BackPropagate()
{

}

int rtp1::NeuralNetwork::GetMaxOutputID()
{


	return 1; // placeholder
}

float rtp1::NeuralNetwork::CalculateError()
{

	return 1.0f; // placeholder
}



void rtp1::NeuralNetwork::SetLinearOutput(bool useLinear)
{

}

void rtp1::NeuralNetwork::SetMomentum(bool useMomentum, float factor)
{

}


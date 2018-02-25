#include "NeuralNetwork.h";

void rtp1::NeuralNetwork::Initialise(unsigned int input, unsigned int hidden, unsigned int noHidden, unsigned int output)
{
	m_InputLayer.p_TotalNeurons = input;
	m_InputLayer.p_NumberOfChildNeurons = hidden;
	m_InputLayer.p_NumberOfParentNeurons = 0;
	m_InputLayer.Initialise(NULL, &m_HiddenLayers[0]);
	m_InputLayer.RandomiseWeights(0, 200);

	for (int i = 0; i < noHidden; i++) {
		NNLayer temp;
		temp.p_TotalNeurons = hidden;
		// determine position
		if (noHidden == 1) {
			temp.p_NumberOfChildNeurons = output;
			temp.p_NumberOfParentNeurons = input;
			temp.Initialise(&m_InputLayer, &m_OutputLayer);
		} else if (noHidden > 1) {
			if (i == 0) {
				temp.p_NumberOfChildNeurons = hidden;
				temp.p_NumberOfParentNeurons = input;
				temp.Initialise(&m_InputLayer, &m_HiddenLayers[1]);
			} else if (i + 1 == noHidden) {
				temp.p_NumberOfChildNeurons = output;
				temp.p_NumberOfParentNeurons = hidden;
				temp.Initialise(&m_HiddenLayers[i - 1], &m_OutputLayer);
			}
			else {
				temp.p_NumberOfChildNeurons = hidden;
				temp.p_NumberOfParentNeurons = hidden;
				temp.Initialise(&m_HiddenLayers[i - 1], &m_HiddenLayers[i + 1]);
			}
		}
		
		temp.RandomiseWeights(0, 200);
		m_HiddenLayers.push_back(temp);
	}
	
	m_OutputLayer.p_TotalNeurons = input;
	m_OutputLayer.p_NumberOfChildNeurons = hidden;
	m_OutputLayer.p_NumberOfParentNeurons = 0;
	m_OutputLayer.Initialise(&m_HiddenLayers[noHidden - 1], NULL);
	m_OutputLayer.RandomiseWeights(0, 200);
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
	if (m_InputLayer != NULL) {
		free(&m_InputLayer);
		// use cleanup in nnlayer class
		m_InputLayer = NULL;
	}
	if (m_OutputLayer != nullptr) {
		delete m_OutputLayer;
		m_OutputLayer = NULL;
	}
	for (int i = 0; i < m_HiddenLayers.size(); i++) {
		if (m_HiddenLayers[i] != NULL) {
			delete m_HiddenLayers[i];
			m_HiddenLayers[i] = NULL;
		}
	}
	m_HiddenLayers.clear();
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

}

float rtp1::NeuralNetwork::CalculateError()
{

}

void rtp1::NeuralNetwork::SetLearningRate(float rate)
{

}

void rtp1::NeuralNetwork::SetLinearOutput(bool useLinear)
{

}

void rtp1::NeuralNetwork::SetMomentum(bool useMomentum, float factor)
{

}


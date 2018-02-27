#include "NNLayer.h"
#include <ctime>

void rtp1::NNLayer::Initialise(NNLayer* parent, NNLayer* child)
{
	for (int i = 0; i < p_TotalNeurons; i++) {
		Neuron temp;
		m_Neurons.push_back(temp);
	}
	if (parent != NULL)	{
		m_Parent = parent;
	}
	if (child != NULL) {
		m_Child = child;
		for (int i = 0; i < p_TotalNeurons; i++) {
			m_Neurons[i].p_Weights = (float*)malloc(sizeof(float) *p_NumberOfChildNeurons);
			m_Neurons[i].p_WeightChanges = (float*)malloc(sizeof(float) *p_NumberOfChildNeurons);
			m_Neurons[i].p_BiasValues = (float*)malloc(sizeof(float) *p_NumberOfChildNeurons);
			m_Neurons[i].p_BiasWeights = (float*)malloc(sizeof(float) *p_NumberOfChildNeurons);
		}
	}
	for (int i = 0; i < p_TotalNeurons; i++) {
		m_Neurons[i].p_NeuronValue = 0;
		m_Neurons[i].p_DesiredValue = 0;
		m_Neurons[i].p_Error = 0;
		if (child != NULL) {
			for (int j = 0; j < p_NumberOfChildNeurons; j++) {
				m_Neurons[i].p_Weights[j] = 0.0;
				m_Neurons[i].p_WeightChanges[j] = 0.0f;
				m_Neurons[i].p_BiasValues[j] = 0.0f;
				m_Neurons[i].p_BiasWeights[j] = 0.0f;
			}
		}
	}
}

void rtp1::NNLayer::RandomiseWeights(int min, int max)
{
	const int MIN = min, MAX = max;
	int number;
	srand((unsigned)time(NULL));
	for (int i = 0; i < p_TotalNeurons; i++) {
		for (int j = 0; j < p_NumberOfChildNeurons; j++) {
			number = abs(rand() % (MAX - MIN + 1) + MIN);
			if (number > MAX) { number = MAX; }
			if (number < MIN) {	number = MIN; }
			m_Neurons[i].p_Weights[j] = number / 100.0 - 1;
			number = abs(rand() % (MAX - MIN + 1) + MIN);
			if (number > MAX) {	number = MAX; }
			if (number < MIN) {	number = MIN; }
			m_Neurons[i].p_BiasWeights[j] = number / 100.0f - 1;
		}
	}
}

void rtp1::NNLayer::Evaluate(std::vector<float> input, std::vector<float> &output)
{
	int inputIndex = 0;
	for (int i = 0; i < p_TotalNeurons; i++) {
		float activation = 0.0f;
		for (int j = 0; j < m_Neurons[i].p_NumberOfInputs - 1; j++) {
			activation += input[inputIndex] * m_Neurons[i].p_Weights[j];
			inputIndex++;
		}
		activation += m_Neurons[i].p_Weights[m_Neurons[i].p_NumberOfInputs] * 1;
		output.push_back(Sigmoid(activation, 1.0f));
		inputIndex = 0;
	}
}

void rtp1::NNLayer::SetNeurons(std::vector<Neuron> neurons, int numberOfNeurons)
{
	p_TotalNeurons = numberOfNeurons;
	m_Neurons = neurons;
}

void rtp1::NNLayer::SaveLayer(const char* %filename)
{

}

void rtp1::NNLayer::LoadLayer(std::vector<Neuron> neuron)
{

}



void rtp1::NNLayer::CalculateErrors()
{

}

void rtp1::NNLayer::AdjustWeights()
{

}

void rtp1::NNLayer::CalculateNeuronValues()
{

}

void rtp1::NNLayer::CleanUp()
{
	free(m_Errors);
	if (&m_Neurons != NULL) {
		for (int i = 0; i < m_Neurons.size(); i++) {
			for (int j = 0; j < p_NumberOfChildNeurons; j++) {
				free(&m_Neurons[i].p_WeightChanges[j]);
				free(&m_Neurons[i].p_Weights[j]);
				free(&m_Neurons[i].p_BiasValues[j]);
				free(&m_Neurons[i].p_BiasWeights[j]);
			}
			free(&m_Neurons[i].p_WeightChanges);
			free(&m_Neurons[i].p_Weights);
			free(&m_Neurons[i]);
		}
		free(&m_Neurons);
	}
}


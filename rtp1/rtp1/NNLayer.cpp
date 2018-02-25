#include "NNLayer.h";

void rtp1::NNLayer::Initialise(NNLayer* parent, NNLayer* child)
{

}

void rtp1::NNLayer::Evaluate(std::vector<float> input, std::vector<float> &output)
{
	int inputIndex = 0;
	for (int i = 0; i < p_TotalNeurons; i++) {
		float activation = 0.0f;
		for (int j = 0; j < m_Neurons[i]->p_NumberOfInputs - 1; j++) {
			activation += input[inputIndex] * m_Neurons[i]->p_Weights[j];
			inputIndex++;
		}
		activation += m_Neurons[i]->p_Weights[m_Neurons[i]->p_NumberOfInputs] * 1;
		output.push_back(Sigmoid(activation, 1.0f));
		inputIndex = 0;
	}
}

void rtp1::NNLayer::SetNeurons(std::vector<Neuron *> neurons, int numberOfNeurons)
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

void rtp1::NNLayer::RandomiseWeights(int min, int max)
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
	free(m_BiasValues);
	free(m_Errors);
	if (&m_Neurons != NULL) {
		for (int i = 0; i < m_Neurons.size(); i++) {
			for (int j = 0; j < m_Neurons[i]->p_Weights.size(); j++) {
				free(&m_Neurons[i]->p_Weights[j]);
			}
			//free(m_WeightChanges[i]);
			free(&m_Neurons[i]->p_Weights);
			free(&m_Neurons[i]);
		}
		free(&m_Neurons);
		// free(m_WeightChanges);
	}
	if (m_BiasValues != NULL) { free(m_BiasValues); }
	// if (BiasWeights != NULL) { free(BiasWeights); }
}


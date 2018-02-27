#include "Brain.h"
#include <cstddef>
#include <climits>
#include <complex>
#include <fstream>

void Brain::Initialise(unsigned int _neuronInput, unsigned int _neuronHidden, unsigned int _neuronOutput)
{
	m_InputLayer.NumberOfNeurons = _neuronInput;
	m_InputLayer.NumberOfChildNeurons = _neuronHidden;
	m_InputLayer.NumberOfParentNeurons = 0;
	m_InputLayer.Initialize(NULL, &m_HiddenLayers);
	m_InputLayer.RandomiseWeights(0, 200);

	m_HiddenLayers.NumberOfNeurons = _neuronHidden;
	m_HiddenLayers.NumberOfChildNeurons = _neuronOutput;
	m_HiddenLayers.NumberOfParentNeurons = _neuronInput;
	m_HiddenLayers.Initialize(&m_InputLayer, &m_OutputLayer);
	m_HiddenLayers.RandomiseWeights(0, 200);

	m_OutputLayer.NumberOfNeurons = _neuronOutput;
	m_OutputLayer.NumberOfChildNeurons = 0;
	m_OutputLayer.NumberOfParentNeurons = _neuronHidden;
	m_OutputLayer.Initialize(&m_HiddenLayers, NULL);
	m_OutputLayer.RandomiseWeights(0, 200);
}

void Brain::CleanUp()
{
	m_InputLayer.CleanUp();
	m_HiddenLayers.CleanUp();
	m_OutputLayer.CleanUp();
}

void Brain::SetInput(int _index, double _value)
{
	if (_index >= 0 && _index < m_InputLayer.NumberOfNeurons) {
		m_InputLayer.NeuronValues[_index] = _value;
	}
}

double Brain::GetOutput(int _index)
{
	if (_index >= 0 && _index < m_OutputLayer.NumberOfNeurons) {
		return m_OutputLayer.NeuronValues[_index];
	}
	return (double)INT_MAX;
}

void Brain::SetDesiredOutput(int _index, double _value)
{
	if (_index >= 0 && _index < m_OutputLayer.NumberOfNeurons) {
		m_OutputLayer.DesiredValues[_index] = _value;
	}
}

void Brain::FeedForward()
{
	m_InputLayer.CalculateNeuronValues();
	m_HiddenLayers.CalculateNeuronValues();
	m_OutputLayer.CalculateNeuronValues();
}

void Brain::BackPropagate()
{
	m_OutputLayer.CalculateErrors();
	m_HiddenLayers.CalculateErrors();
	m_HiddenLayers.AdjustWeights();
	m_InputLayer.AdjustWeights();
}

int Brain::GetMaxOutputID()
{
	double maxValue = m_OutputLayer.NeuronValues[0];
	unsigned int id = 0;
	for (int i = 0; i < m_OutputLayer.NumberOfNeurons; i++) {
		if (m_OutputLayer.NeuronValues[i] > maxValue) {
			maxValue = m_OutputLayer.NeuronValues[i];
			id = i;
		}
	}
	return id;
}

double Brain::CalculateError()
{
	double error = 0;
	for (int i = 0; i < m_OutputLayer.NumberOfNeurons; i++) {
		error += std::pow(m_OutputLayer.NeuronValues[i] - m_OutputLayer.DesiredValues[i], 2);
	}
	error = error / m_OutputLayer.NumberOfNeurons;
	return error;
}

void Brain::SetLearningRate(double _rate)
{
	m_InputLayer.LearningRate = _rate;
	m_HiddenLayers.LearningRate = _rate;
	m_OutputLayer.LearningRate = _rate;
}

void Brain::SetLinearOutput(bool _useLinear)
{
	m_InputLayer.LinearOutput = _useLinear;
	m_HiddenLayers.LinearOutput = _useLinear;
	m_OutputLayer.LinearOutput = _useLinear;
}

void Brain::SetMomentum(bool _useMomentum, double _factor)
{
	m_InputLayer.UseMomentum = _useMomentum;
	m_HiddenLayers.UseMomentum = _useMomentum;
	m_OutputLayer.UseMomentum = _useMomentum;
	m_InputLayer.MomentumFactor = _factor;
	m_HiddenLayers.MomentumFactor = _factor;
	m_OutputLayer.MomentumFactor = _factor;
}

void Brain::DumpData(const char* filename)
{
	std::ofstream f;
	f.open(filename);
	f << "---------------------------------------------------------------\n";
	f << "Input Layer\n";
	f << "---------------------------------------------------------------\n";
	f << "\n\n" << "Neuron Values:\n\n";
	for (int i = 0; i < m_InputLayer.NumberOfNeurons; i++) {
		f << i << ". = " << m_InputLayer.NeuronValues[i] << "\n";
	}
	f << "\n\n" << "Weight Values:\n\n";
	for (int i = 0; i < m_InputLayer.NumberOfNeurons; i++) {
		for (int j = 0; j < m_InputLayer.NumberOfChildNeurons; j++) {
			f << i << ". " << j << ". = " << m_InputLayer.Weights[i][j] << "\n";
		}
	}
	f << "\n\n" << "Bias Weights:\n\n";
	for (int i = 0; i < m_InputLayer.NumberOfChildNeurons; i++) {
		f << i << ". = " << m_InputLayer.BiasWeights[i] << "\n";
	}
	f << "\n\n\n";
	f << "---------------------------------------------------------------\n";
	f << "Hidden Layer\n";
	f << "---------------------------------------------------------------\n";
	f << "\n\n" << "Neuron Values:\n\n";
	for (int i = 0; i < m_HiddenLayers.NumberOfNeurons; i++) {
		f << i << ". = " << m_HiddenLayers.NeuronValues[i] << "\n";
	}
	f << "\n\n" << "Weight Values:\n\n";
	for (int i = 0; i < m_HiddenLayers.NumberOfNeurons; i++) {
		for (int j = 0; j < m_HiddenLayers.NumberOfChildNeurons; j++) {
			f << i << ". " << j << ". = " << m_HiddenLayers.Weights[i][j] << "\n";
		}
	}
	f << "\n\n" << "Bias Weights:\n\n";
	for (int i = 0; i < m_HiddenLayers.NumberOfChildNeurons; i++) {
		f << i << ". = " << m_HiddenLayers.BiasWeights[i] << "\n";
	}
	f << "\n\n\n";
	f << "---------------------------------------------------------------\n";
	f << "Output Layer\n";
	f << "---------------------------------------------------------------\n";
	f << "\n\n" << "Neuron Values:\n\n";
	for (int i = 0; i < m_OutputLayer.NumberOfNeurons; i++) {
		f << i << ". = " << m_OutputLayer.NeuronValues[i] << "\n";
	}
	f << "\n\n" << "Weight Values:\n\n";
	for (int i = 0; i < m_OutputLayer.NumberOfNeurons; i++) {
		for (int j = 0; j < m_OutputLayer.NumberOfChildNeurons; j++) {
			f << i << ". " << j << ". = " << m_OutputLayer.Weights[i][j] << "\n";
		}
	}
	f << "\n\n" << "Bias Weights:\n\n";
	for (int i = 0; i < m_OutputLayer.NumberOfChildNeurons; i++) {
		f << i << ". = " << m_OutputLayer.BiasWeights[i] << "\n";
	}
	f << "\n\n\n";
	f.close();
}

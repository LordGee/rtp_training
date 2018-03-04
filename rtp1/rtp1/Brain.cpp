#include "Brain.h"
#include <cstddef>
#include <climits>
#include <complex>
#include <fstream>
#include "FileManager.h"

using namespace rtp1::my_file;

/* This function is called regardless of whether a new project or an existing load
 * and configures a neural network passed on the values that are being loaded from 
 * the text info file. */
void Brain::InitialiseNew(const char* name, bool NNNew)
{
	CleanUp();
	std::vector<double> temp = ReadInfoFile(name);
	if (temp.size() > 0) {
		int hiddenNeurons = (int)((temp[0] + temp[2]) - (temp[0] / 2));
		Initialise((int)temp[0], hiddenNeurons, (int)temp[1], (int)temp[2]);
		if (NNNew) {
			RandomWeights();
		} else {
			LoadAllLayers(name);
		}
		SetLearningRate(temp[3]);
		SetMomentum(temp[4], temp[5]);
		SetLinearOutput(temp[6]);
		SaveAllLayers(name);
	}
}

/* Configures each layer in the newly configured neural network */
void Brain::Initialise(unsigned int noInputNeurons, unsigned int noHiddenNeurons, unsigned int noHiddenLayers, unsigned int noOutputNeurons)
{
	m_InputLayer.NumberOfNeurons = noInputNeurons;
	m_InputLayer.NumberOfChildNeurons = noHiddenNeurons;
	m_InputLayer.NumberOfParentNeurons = 0;
	m_InputLayer.Initialize(NULL, &m_HiddenLayers);
	m_HiddenLayers.NumberOfNeurons = noHiddenNeurons;
	m_HiddenLayers.NumberOfChildNeurons = noOutputNeurons;
	m_HiddenLayers.NumberOfParentNeurons = noInputNeurons;
	m_HiddenLayers.Initialize(&m_InputLayer, &m_OutputLayer);
	m_OutputLayer.NumberOfNeurons = noOutputNeurons;
	m_OutputLayer.NumberOfChildNeurons = 0;
	m_OutputLayer.NumberOfParentNeurons = noHiddenNeurons;
	m_OutputLayer.Initialize(&m_HiddenLayers, NULL);
}

/* Sets each layer to configure the initial random weights 
 * This is only executed for newly created networks */
void Brain::RandomWeights()
{
	m_InputLayer.RandomiseWeights(0, 200);
	m_HiddenLayers.RandomiseWeights(0, 200);
	m_OutputLayer.RandomiseWeights(0, 200);
}

/* Sets the learning rate for each Layer object */
void Brain::SetLearningRate(double _rate)
{
	m_InputLayer.LearningRate = _rate;
	m_HiddenLayers.LearningRate = _rate;
	m_OutputLayer.LearningRate = _rate;
}

/* Sets the input neuron values before starting the feed forward process */
void Brain::SetInput(unsigned int _index, double _value)
{
	if (_index >= 0 && _index < m_InputLayer.NumberOfNeurons) {
		m_InputLayer.NeuronValues[_index] = _value;
	}
}

/* Each layer calls the calculate neuron values where each is evaluated */
void Brain::FeedForward()
{
	// If I could implement threading it would be right HERE!
	m_InputLayer.CalculateNeuronValues();
	m_HiddenLayers.CalculateNeuronValues();
	m_OutputLayer.CalculateNeuronValues();
}

/* This iterates through each of the output layer neurons comparing the 
 * value. The neuron with the highest value is returned. */
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

/* Sets a predetermined desired output value*/
void Brain::SetDesiredOutput(unsigned int _index, double _value)
{
	if (_index >= 0 && _index < m_OutputLayer.NumberOfNeurons) {
		m_OutputLayer.DesiredValues[_index] = _value;
	}
}

/* Calculates the difference the current output neuron value against 
 * the desired value. The error variance is then returned. */
double Brain::CalculateError()
{
	double error = 0;
	for (int i = 0; i < m_OutputLayer.NumberOfNeurons; i++) {
		error += std::pow(m_OutputLayer.NeuronValues[i] - 
			m_OutputLayer.DesiredValues[i], 2);
	}
	error = error / m_OutputLayer.NumberOfNeurons;
	return error;
}

/* The back propagation re-evaluates the network by calculating 
 * the errors and then adjusting the weights */
void Brain::BackPropagate()
{
	m_OutputLayer.CalculateErrors();
	m_HiddenLayers.CalculateErrors();
	m_HiddenLayers.AdjustWeights();
	m_InputLayer.AdjustWeights();
}

/* Each layer is saved to a text file  */
void Brain::SaveAllLayers(std::string name)
{
	m_InputLayer.SaveLayerData(name, "input");
	m_HiddenLayers.SaveLayerData(name, "hidden");
	m_OutputLayer.SaveLayerData(name, "output");
}

/* Each layer is loaded from an existing text file */
void Brain::LoadAllLayers(const char* name)
{
	m_InputLayer.LoadLayerData(name, "input");
	m_HiddenLayers.LoadLayerData(name, "hidden");
	m_OutputLayer.LoadLayerData(name, "output");
}

/* Each layer is cleaned up and memory freed*/
void Brain::CleanUp()
{
	m_InputLayer.CleanUp();
	m_HiddenLayers.CleanUp();
	m_OutputLayer.CleanUp();
}

/* Returns a specific neuron value from the output layer */
double Brain::GetOutput(unsigned int _index)
{
	if (_index >= 0 && _index < m_OutputLayer.NumberOfNeurons) {
		return m_OutputLayer.NeuronValues[_index];
	}
	return (double)INT_MAX;
}

/* Sets each layer to use a linear output method instead 
 * of the sigmoid method*/
void Brain::SetLinearOutput(bool _useLinear)
{
	m_InputLayer.LinearOutput = _useLinear;
	m_HiddenLayers.LinearOutput = _useLinear;
	m_OutputLayer.LinearOutput = _useLinear;
}

/* Sets each layer whether to use the momentum factor and 
 * also defines what the factor amount is*/
void Brain::SetMomentum(bool _useMomentum, double _factor)
{
	m_InputLayer.UseMomentum = _useMomentum;
	m_HiddenLayers.UseMomentum = _useMomentum;
	m_OutputLayer.UseMomentum = _useMomentum;
	m_InputLayer.MomentumFactor = _factor;
	m_HiddenLayers.MomentumFactor = _factor;
	m_OutputLayer.MomentumFactor = _factor;
}
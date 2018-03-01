#pragma once

#include "Layer.h"

class Brain {

private:
	Layer m_InputLayer;
	Layer m_HiddenLayers;
	Layer m_OutputLayer;

public:
	void InitialiseNew(const char* name, bool NNNew);
	void Initialise(unsigned int noInputNeurons, unsigned int noHiddenNeurons, unsigned int noHiddenLayers, unsigned int noOutputNeurons);
	void RandomWeights();
	void SetLearningRate(double _rate);
	void SetMomentum(bool _useMomentum, double _factor);
	void SetLinearOutput(bool _useLinear);
	void SetInput(unsigned int _index, double _value);
	void FeedForward();
	int GetMaxOutputID();
	// Training specific
	void SetDesiredOutput(unsigned int _index, double _value);
	double CalculateError();
	void BackPropagate();

	void SaveAllLayers(const char* name);
	void LoadAllLayers(const char* name);
	
	double GetOutput(unsigned int _index);
	
	void CleanUp();

};
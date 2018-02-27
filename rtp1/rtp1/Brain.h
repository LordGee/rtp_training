#pragma once

#include "Layer.h"

class Brain {

private:
	Layer m_InputLayer;
	Layer m_HiddenLayers;
	Layer m_OutputLayer;

public:
	void Initialise(unsigned int _neuronInput, unsigned int _neuronHidden, unsigned int _neuronOutput);
	void CleanUp();
	void SetInput(int _index, double _value);
	double GetOutput(int _index);
	void SetDesiredOutput(int _index, double _value);
	void FeedForward();
	void BackPropagate();
	int GetMaxOutputID();
	double CalculateError();
	void SetLearningRate(double _rate);
	void SetLinearOutput(bool _useLinear);
	void SetMomentum(bool _useMomentum, double _factor);
	void DumpData(const char* filename);

};
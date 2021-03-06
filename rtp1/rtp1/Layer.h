#pragma once

#include <string>

class Layer {
public:
	unsigned int	NumberOfNeurons, NumberOfChildNeurons, NumberOfParentNeurons;
	double*			NeuronValues, *DesiredValues, *BiasWeights;
	double			LearningRate, MomentumFactor;
	bool			LinearOutput, UseMomentum;

private:
	double**		m_WeightChanges;
	double**		m_Weights;
	double*			m_Errors, *m_BiasValues;
	Layer*			m_ParentLayer;
	Layer*			m_ChildLayer;

public:
	Layer();
	void Initialize(Layer* _parentLayer, Layer* _childLayer);
	void RandomiseWeights(int _rangeMin, int _rangeMax);
	void CalculateNeuronValues();
	void CalculateErrors();
	void AdjustWeights();

	void SaveLayerData(std::string name, const char* layer);
	void LoadLayerData(const char* name, const char* layer);

	void CleanUp();
};
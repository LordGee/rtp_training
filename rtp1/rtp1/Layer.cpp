#include "Layer.h"
#include <cstdlib>
#include <ctime>
#include "MyMath.h"

using namespace rtp1::my_math;

Layer::Layer()
{
	m_ParentLayer = NULL;
	m_ChildLayer = NULL;
	LinearOutput = false;
	UseMomentum = false;
	MomentumFactor = 0.9f;
}

void Layer::Initialize(Layer* _parentLayer, Layer* _childLayer)
{
	NeuronValues = (double*)malloc(sizeof(double) *NumberOfNeurons);
	DesiredValues = (double*)malloc(sizeof(double) *NumberOfNeurons);
	m_Errors = (double*)malloc(sizeof(double) *NumberOfNeurons);
	if (_parentLayer != NULL) {
		m_ParentLayer = _parentLayer;
	}
	if (_childLayer != NULL) {
		m_ChildLayer = _childLayer;
		Weights = (double**)malloc(sizeof(double) *NumberOfNeurons);
		m_WeightChanges = (double**)malloc(sizeof(double) *NumberOfNeurons);
		for (int i = 0; i < NumberOfNeurons; i++) {
			Weights[i] = (double*)malloc(sizeof(double) *NumberOfNeurons);
			m_WeightChanges[i] = (double*)malloc(sizeof(double) *NumberOfNeurons);
		}
		m_BiasValues = (double*)malloc(sizeof(double) *NumberOfNeurons);
		BiasWeights = (double*)malloc(sizeof(double) *NumberOfNeurons);
	}
	else {
		Weights = NULL;
		m_BiasValues = NULL;
		BiasWeights = NULL;
		m_WeightChanges = NULL;
	}
	for (int i = 0; i < NumberOfNeurons; i++) {
		NeuronValues[i] = 0;
		DesiredValues[i] = 0;
		m_Errors[i] = 0;
		if (_childLayer != NULL) {
			for (int j = 0; j < NumberOfChildNeurons; j++) {
				Weights[i][j] = 0;
				m_WeightChanges[i][j] = 0;
			}
		}
	}
	if (_childLayer != NULL) {
		for (int j = 0; j < NumberOfChildNeurons; j++) {
			m_BiasValues[j] = 0;
			BiasWeights[j] = 0;
		}
	}
}

void Layer::RandomiseWeights(const int _rangeMin, const int _rangeMax)
{
	int number;
	srand((unsigned)time(NULL));
	for (int i = 0; i < NumberOfNeurons; i++) {
		for (int j = 0; j < NumberOfChildNeurons; j++) {
			number = abs(rand() % (_rangeMax - _rangeMin + 1) + _rangeMin);
			if (number > _rangeMax) {
				number = _rangeMax;
			}
			if (number < _rangeMin) {
				number = _rangeMin;
			}
			Weights[i][j] = number / 100.0f - 1;
		}
	}
	for (int i = 0; i < NumberOfChildNeurons; i++) {
		number = abs(rand() % (_rangeMax - _rangeMin + 1) + _rangeMin);
		if (number > _rangeMax) {
			number = _rangeMax;
		}
		if (number < _rangeMin) {
			number = _rangeMin;
		}
		BiasWeights[i] = number / 100.0f - 1;
	}
}

void Layer::CalculateNeuronValues()
{
	if (m_ParentLayer != NULL) {
		for (int i = 0; i < NumberOfNeurons; i++) {
			double activation = 0;
			for (int j = 0; j < NumberOfParentNeurons; j++) {
				activation += m_ParentLayer->NeuronValues[j] * m_ParentLayer->Weights[j][i];
			}
			activation += m_ParentLayer->m_BiasValues[i] * m_ParentLayer->BiasWeights[i];
			if (m_ChildLayer == NULL && LinearOutput) {
				NeuronValues[i] = activation;
			} else {
				NeuronValues[i] = Sigmoid(activation, 1.0f);
			}
		}
	}
}

void Layer::CalculateErrors()
{
	if (m_ChildLayer == NULL) {
		for (int i = 0; i < NumberOfNeurons; i++) {
			m_Errors[i] = (DesiredValues[i] - NeuronValues[i]) * NeuronValues[i] * (1.0f - NeuronValues[i]);
		}
	}
	else if (m_ParentLayer == NULL) {
		for (int i = 0; i < NumberOfNeurons; i++) {
			m_Errors[i] = 0.0f;
		}
	}
	else {
		for (int i = 0; i < NumberOfNeurons; i++) {
			double sum = 0;
			for (int j = 0; j < NumberOfChildNeurons; j++) {
				sum += m_ChildLayer->m_Errors[j] * Weights[i][j];
			}
			m_Errors[i] = sum * NeuronValues[i] * (1.0f - NeuronValues[i]);
		}
	}
}

void Layer::AdjustWeights()
{
	if (m_ChildLayer != NULL) {
		for (int i = 0; i < NumberOfNeurons; i++) {
			for (int j = 0; j < NumberOfChildNeurons; j++) {
				double deltaWeights = LearningRate * m_ChildLayer->m_Errors[j] * NeuronValues[i];
				if (UseMomentum) {
					Weights[i][j] += deltaWeights + MomentumFactor * m_WeightChanges[i][j];
					m_WeightChanges[i][j] = deltaWeights;
				} else {
					Weights[i][j] += deltaWeights;
				}
			}
		}
		for (int i = 0; i < NumberOfChildNeurons; i++) {
			BiasWeights[i] += LearningRate * m_ChildLayer->m_Errors[i] * m_BiasValues[i];
		}
	}
}

void Layer::CleanUp()
{
	free(NeuronValues);
	free(DesiredValues);
	free(m_Errors);
	if (Weights != NULL) {
		for (int i = 0; i < NumberOfNeurons; i++) {
			free(Weights[i]);
			free(m_WeightChanges[i]);
		}
		free(Weights);
		free(m_WeightChanges);
	}
	if (m_BiasValues != NULL) { free(m_BiasValues); }
	if (BiasWeights != NULL) { free(BiasWeights); }
}







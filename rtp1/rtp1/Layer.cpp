#include "Layer.h"
#include <cstdlib>
#include <ctime>
#include "MyMath.h"
#include <fstream>
#include <string>
#include <vector>

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
		m_Weights = (double**)malloc(sizeof(double) *NumberOfNeurons);
		m_WeightChanges = (double**)malloc(sizeof(double) *NumberOfNeurons);
		for (int i = 0; i < NumberOfNeurons; i++) {
			m_Weights[i] = (double*)malloc(sizeof(double) *NumberOfNeurons);
			m_WeightChanges[i] = (double*)malloc(sizeof(double) *NumberOfNeurons);
		}
		m_BiasValues = (double*)malloc(sizeof(double) *NumberOfNeurons);
		BiasWeights = (double*)malloc(sizeof(double) *NumberOfNeurons);
	}
	else {
		m_Weights = NULL;
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
				m_Weights[i][j] = 0;
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
			m_Weights[i][j] = number / 100.0f - 1;
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
				activation += m_ParentLayer->NeuronValues[j] * m_ParentLayer->m_Weights[j][i];
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
				sum += m_ChildLayer->m_Errors[j] * m_Weights[i][j];
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
					m_Weights[i][j] += deltaWeights + MomentumFactor * m_WeightChanges[i][j];
					m_WeightChanges[i][j] = deltaWeights;
				} else {
					m_Weights[i][j] += deltaWeights;
				}
			}
		}
		for (int i = 0; i < NumberOfChildNeurons; i++) {
			BiasWeights[i] += LearningRate * m_ChildLayer->m_Errors[i] * m_BiasValues[i];
		}
	}
}

void Layer::SaveLayerData(const char* name, const char* layer)
{
	std::string folder = "data/";
	std::string filename = name;
	std::string layername = layer;
	std::string extension = "_info.txt";
	std::string openFile = folder + filename + layername + extension;

	std::ofstream wf;
	wf.open(openFile);

	for (int i = 0; i < NumberOfNeurons; i++) {
		for (int j = 0; j < NumberOfChildNeurons; j++) {
			wf << m_Weights[i][j] << std::endl;
		}
	}
	for (int j = 0; j < NumberOfChildNeurons; j++) {
		wf << BiasWeights[j] << std::endl;
	}

	wf.close();
}

void Layer::LoadLayerData(const char* name, const char* layer)
{
	std::string folder = "data/";
	std::string filename = name;
	std::string layername = layer;
	std::string extension = "_info.txt";
	std::string openFile = folder + filename + layername + extension;

	std::string word;
	std::string::size_type size;
	double number = 0.0;
	std::vector<double> temp;

	std::ifstream rf;
	rf.open(openFile);
	if (rf.is_open()) {
		while (!rf.eof()) {
			rf >> std::skipws >> word;
			if (word != "") {
				number = (double)stod(word, &size);
				temp.push_back(number);
			}
		}
	}
	rf.close();

	int counter = 0;
	for (int i = 0; i < NumberOfNeurons; i++) {
		for (int j = 0; j < NumberOfChildNeurons; j++) {
			m_Weights[i][j] = temp[counter];
			counter++;
		}
	}
	for (int j = 0; j < NumberOfChildNeurons; j++) {
		BiasWeights[j] = temp[counter];
		counter++;
	}
}

void Layer::CleanUp()
{
	free(NeuronValues);
	free(DesiredValues);
	free(m_Errors);
	if (m_Weights != NULL) {
		for (int i = 0; i < NumberOfNeurons; i++) {
			free(m_Weights[i]);
			free(m_WeightChanges[i]);
		}
		free(m_Weights);
		free(m_WeightChanges);
	}
	if (m_BiasValues != NULL) { free(m_BiasValues); }
	if (BiasWeights != NULL) { free(BiasWeights); }
}







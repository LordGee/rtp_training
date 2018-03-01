#include "Draw.h"
#include "FileManager.h";

using namespace System::Windows::Forms;
using namespace rtp1::my_file;


void rtp1::MyDrawing::NNInitLoad(const char* name)
{
	m_TheBrain.InitialiseNew(name, false);
}

void rtp1::MyDrawing::NNInitNew(const char* name, int inputs, int hiddenLayers, 
	int outputs, double learningRate, bool useMomentum, double momentumFactor, 
	bool useLinear)
{
	CreateInfoFile(name, inputs, hiddenLayers, outputs, learningRate, 
		useMomentum, momentumFactor, useLinear);
	m_TheBrain.InitialiseNew(name, true);

}

void rtp1::MyDrawing::AddMyDrawing()
{
	Bitmap bMap("img/temp.bmp");
	for (int y = 0; y < bMap.Height; y++) {
		for (int x = 0; x < bMap.Width; x++) {
			float colour = bMap.GetPixel(x, y).R + bMap.GetPixel(x, y).G + bMap.GetPixel(x, y).B;
			if (colour > 0) {
				m_MyDrawing.push_back(colour / MAX_ACCUM_COLOUR_VALUE);
			} else {
				m_MyDrawing.push_back(0);
			}
		}
	}
	int z = 0;
}

char rtp1::MyDrawing::AnalyseMyLetter(unsigned int _inputs, unsigned int _numHiddenLayer, unsigned int _numNeuronsPerHidden, unsigned int _outputs)
{
	char output = 'A';

	int numInputs = m_MyDrawing.size();

	m_TheBrain.Initialise(numInputs, _numNeuronsPerHidden, _numHiddenLayer, _outputs);
	m_TheBrain.SetLearningRate(0.2f);
	m_TheBrain.SetMomentum(true, 0.9);

	for (int i = 0; i < numInputs; i++) {
		m_TheBrain.SetInput(i, m_MyDrawing[i]);
	}

	m_TheBrain.FeedForward();

	int outputValue = m_TheBrain.GetMaxOutputID();

	int z = 0;
	return output;
}

bool rtp1::MyDrawing::TrainMyLetter(char _c)
{
	int goalValue = 7;
	int numInputs = m_MyDrawing.size();

	m_TheBrain.Initialise(numInputs, numInputs - 26, 2, 26);
	m_TheBrain.SetLearningRate(0.2f);
	m_TheBrain.SetMomentum(true, 0.9);

	double error = 1;
	int count = 0;

	for (int i = 0; i < numInputs; i++) {
		m_TheBrain.SetInput(i, m_MyDrawing[i]);
	}
	m_TheBrain.FeedForward();

	while (error > 0.0001 && count < 50000) {
		error = 0;
		count++;
		for (int i = 0; i < numInputs; i++) {
			m_TheBrain.SetInput(i, m_MyDrawing[i]);
		}
		for (int i = 0; i < 26; i++) {
			if (i == goalValue)	{
				m_TheBrain.SetDesiredOutput(i, 1);
			} else {
				m_TheBrain.SetDesiredOutput(i, 0);
			}
		}
		m_TheBrain.FeedForward();
		error += m_TheBrain.CalculateError();
		m_TheBrain.BackPropagate();
		error = error / numInputs;
	}

	int x = m_TheBrain.GetMaxOutputID();

	int z = 0;
	return true;
}


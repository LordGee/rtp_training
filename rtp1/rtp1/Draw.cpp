#include "Draw.h"
#include "FileManager.h";

using namespace System::Windows::Forms;
using namespace rtp1::my_file;


std::vector<double> rtp1::MyDrawing::NNInitLoad(const char* name)
{
	m_TheBrain.InitialiseNew(name, false);
	m_Filename = name;
	std::vector<double> temp = ReadInfoFile(m_Filename);
	return temp;
}

void rtp1::MyDrawing::NNInitNew(const char* name, int inputs, int hiddenLayers, 
	int outputs, double learningRate, bool useMomentum, double momentumFactor, 
	bool useLinear, int letterCase)
{
	CreateInfoFile(name, inputs, hiddenLayers, outputs, learningRate, 
		useMomentum, momentumFactor, useLinear, letterCase);
	m_TheBrain.InitialiseNew(name, true);

}

void rtp1::MyDrawing::AddMyDrawing()
{
	Bitmap bMap(IMG_LOCATION);
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
}

char rtp1::MyDrawing::AnalyseMyLetter()
{
	int numInputs = m_MyDrawing.size();

	for (int i = 0; i < numInputs; i++) {
		m_TheBrain.SetInput(i, m_MyDrawing[i]);
	}

	m_TheBrain.FeedForward();

	int outputValue = m_TheBrain.GetMaxOutputID();

	return outputValue;
}

char rtp1::MyDrawing::TrainMyLetter(int _c)
{
	int numInputs = m_MyDrawing.size();

	double error = 1;
	int count = 0;
	/*
	for (int i = 0; i < numInputs; i++) {
		m_TheBrain.SetInput(i, m_MyDrawing[i]);
	}
	m_TheBrain.FeedForward();
	*/

	while (error > 0.0001 && count < 50000) {
		error = 0;
		count++;
		for (int i = 0; i < numInputs; i++) {
			m_TheBrain.SetInput(i, m_MyDrawing[i]);
		}
		for (int i = 0; i < 26; i++) {
			if (i == _c) {
				m_TheBrain.SetDesiredOutput(i, 1);
			} else {
				m_TheBrain.SetDesiredOutput(i, 0);
			}
		}
		m_TheBrain.FeedForward();
		error += m_TheBrain.CalculateError();
		m_TheBrain.BackPropagate();
		// error = error / numInputs;
	}
	m_TheBrain.SaveAllLayers(m_Filename);

	return m_TheBrain.GetMaxOutputID();
}


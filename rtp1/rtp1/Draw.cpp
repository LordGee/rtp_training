#include "Draw.h"
#include "FileManager.h";

using namespace System::Windows::Forms;
using namespace rtp1::my_file;

/* Initiates the load process from a text file and generates the neural network */
std::vector<double> rtp1::MyDrawing::NNInitLoad(const char* name)
{
	m_TheBrain.InitialiseNew(name, false);
	m_Filename = name;
	std::vector<double> temp = ReadInfoFile(name);
	return temp;
}

/* Creates a new network from the options chosen */
void rtp1::MyDrawing::NNInitNew(const char* name, int inputs, int hiddenLayers, 
	int outputs, double learningRate, bool useMomentum, double momentumFactor, 
	bool useLinear, int letterCase)
{
	CreateInfoFile(name, inputs, hiddenLayers, outputs, learningRate, 
		useMomentum, momentumFactor, useLinear, letterCase);
	m_TheBrain.InitialiseNew(name, true);
}

/* Converts the saved bitmap image to a flat vector array of 0's and 1's */
void rtp1::MyDrawing::AddMyDrawing()
{
	m_MyDrawing.clear();
	Bitmap bMap(IMG_LOCATION);
	for (int y = 0; y < bMap.Height; y++) {
		for (int x = 0; x < bMap.Width; x++) {
			float colour = bMap.GetPixel(x, y).R + 
				bMap.GetPixel(x, y).G + 
				bMap.GetPixel(x, y).B;
			if (colour > 255) {
				m_MyDrawing.push_back(1);
				//m_MyDrawing.push_back(colour / MAX_ACCUM_COLOUR_VALUE);
			} else {
				m_MyDrawing.push_back(0);
			}
		}
	}
}

/* This sets up the neural network by setting the input layer values 
 * and then starts the feed forward process to evaluate the results 
 * The dominant output value is then returned */
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

/* This  starts the process of training the neural network by 
 * looping through the test cases and performing back propagation 
 * to calculate to manipulates the various weights to the 
 * desired outcome */
char rtp1::MyDrawing::TrainMyLetter(int _c)
{
	int numInputs = m_MyDrawing.size();
	double error = 1;
	int count = 0;
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
		error = error / numInputs;
	}
	m_TheBrain.SaveAllLayers(m_Filename);
	return m_TheBrain.GetMaxOutputID();
}
#include "Draw.h"

using namespace System::Windows::Forms;

rtp1::MyDrawing::MyDrawing()
{
}

void rtp1::MyDrawing::AddMyDrawing()
{
	Bitmap bMap("../unmanaged/img/temp.bmp");
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

	TheBrain.Initialise(numInputs, _numNeuronsPerHidden, _numHiddenLayer, _outputs);
	TheBrain.SetLearningRate(0.2f);
	TheBrain.SetMomentum(true, 0.9);

	for (int i = 0; i < numInputs; i++) {
		TheBrain.SetInput(i, m_MyDrawing[i]);
	}

	TheBrain.FeedForward();

	int outputValue = TheBrain.GetMaxOutputID();

	TheBrain.DumpData("../unmanaged/data/brain.txt");

	int z = 0;
	return output;
}

bool rtp1::MyDrawing::TrainMyLetter(char _c)
{
	int goalValue = 7;
	int numInputs = m_MyDrawing.size();

	TheBrain.Initialise(numInputs, numInputs - 26, 2, 26);
	TheBrain.SetLearningRate(0.2f);
	TheBrain.SetMomentum(true, 0.9);

	double error = 1;
	int count = 0;

	for (int i = 0; i < numInputs; i++) {
		TheBrain.SetInput(i, m_MyDrawing[i]);
	}
	TheBrain.FeedForward();

	TheBrain.DumpData("../unmanaged/data/PreBrain.txt");
	while (error > 0.0001 && count < 50000) {
		error = 0;
		count++;
		for (int i = 0; i < numInputs; i++) {
			TheBrain.SetInput(i, m_MyDrawing[i]);
		}
		for (int i = 0; i < 26; i++) {
			if (i == goalValue)	{
				TheBrain.SetDesiredOutput(i, 1);
			} else {
				TheBrain.SetDesiredOutput(i, 0);
			}
		}
		TheBrain.FeedForward();
		error += TheBrain.CalculateError();
		TheBrain.BackPropagate();
		error = error / numInputs;
	}

	int x = TheBrain.GetMaxOutputID();
	TheBrain.DumpData("../unmanaged/data/PostBrain.txt");
	int z = 0;
	return true;
}


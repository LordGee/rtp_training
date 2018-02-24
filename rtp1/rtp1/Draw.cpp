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

char rtp1::MyDrawing::AnalyseMyLetter(int _numHiddenLayer, int _numNeuronsPerHidden)
{
	char output = 'A';

	int numInputs = m_MyDrawing.size();


	return output;
}


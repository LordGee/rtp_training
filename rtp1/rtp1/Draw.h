#pragma once

#include "Brain.h"
#include <vector>

#define MAX_ACCUM_COLOUR_VALUE 765

namespace rtp1
{
	using namespace System;
	using namespace System::Drawing;

	struct Draw
	{
		float x, y;
	};

	class MyDrawing {
	private:
		std::vector<float> m_MyDrawing;
		Brain TheBrain;

	public:
		MyDrawing();
		void AddMyDrawing();
		char AnalyseMyLetter(unsigned int _inputs, unsigned int _numHiddenLayer, unsigned int _numNeuronsPerHidden, unsigned int _outputs);
		bool TrainMyLetter(char _c);


		void StartDrawing(System::EventArgs^ e);
		void FinishDrawing();


	private:
		void DrawingThread();
	};


}
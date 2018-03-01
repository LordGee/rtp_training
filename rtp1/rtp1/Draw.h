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
		Brain m_TheBrain;

	public:
		void NNInitLoad(const char* name);
		void NNInitNew(const char* name, int inputs, int hiddenLayers, int outputs,
			double learningRate, bool useMomentum, double momentumFactor, bool useLinear);
		void AddMyDrawing();
		char AnalyseMyLetter(unsigned int _inputs, unsigned int _numHiddenLayer, unsigned int _numNeuronsPerHidden, unsigned int _outputs);
		bool TrainMyLetter(char _c);
	};


}
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
		std::vector<double> NNInitLoad(const char* name);
		void NNInitNew(const char* name, int inputs, int hiddenLayers, int outputs,
			double learningRate, bool useMomentum, double momentumFactor, 
			bool useLinear, int letterCase);
		void AddMyDrawing();
		char AnalyseMyLetter();
		bool TrainMyLetter(int _c);
	};


}
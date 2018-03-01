#pragma once

#include <vector>

namespace rtp1
{
	namespace my_file
	{
		std::string GetPath(const char* name);

		void CreateInfoFile(const char* name, int inputs, int hiddenLayers,
			int outputs, double learningRate, bool useMomentum,
			double momentumFactor, bool useLinear);

		std::vector<double> ReadInfoFile(const char* name);
	}
}
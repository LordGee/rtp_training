#include "FileManager.h"
#include <fstream>
#include <string>

/* Concatenates the correct file path for use in the fail creation an reading process */
std::string rtp1::my_file::GetPath(const char* name)
{
	std::string folder = "data/";
	std::string filename = name;
	std::string extension = "_info.txt";
	std::string openFile = folder + filename + extension;
	return openFile;
}

/* Writes to a text file the information required to reload a neural network */
void rtp1::my_file::CreateInfoFile(const char* name, int inputs, int hiddenLayers,
	int outputs, double learningRate, bool useMomentum, double momentumFactor,
	bool useLinear, int letterCase)
{
	std::string openFile = GetPath(name);
	std::ofstream wf;
	wf.open(openFile);
	wf << inputs << std::endl;
	wf << hiddenLayers << std::endl;
	wf << outputs << std::endl;
	wf << learningRate << std::endl;
	wf << useMomentum << std::endl;
	wf << momentumFactor << std::endl;
	wf << useLinear << std::endl;
	wf << letterCase << std::endl;
	wf.close();
}

/* Read a text info file into a temporary vector array and is 
 * returned upon completion */
std::vector<double> rtp1::my_file::ReadInfoFile(const char* name)
{
	std::string openFile = GetPath(name);
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
	return temp;
}
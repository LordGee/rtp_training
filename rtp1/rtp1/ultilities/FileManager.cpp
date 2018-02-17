#include "FileManager.h"
#include <fstream>

char rtp1::util::FileManager::LoadFile(const char* filename)
{
	m_Read.open(filename);
	int x = 0, y = 0;
	char output;
	if (m_Read.is_open()) {
		while (!m_Read.eof()) {
			m_Read >> std::noskipws >> output;
		}
	}
	m_Read.close();
	return output;
}

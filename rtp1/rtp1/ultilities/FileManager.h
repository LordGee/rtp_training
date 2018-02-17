#pragma once
#include <fstream>

namespace rtp1
{
	namespace util
	{
		class FileManager
		{
		private:
			std::ifstream m_Read;
			const char* m_Filename;

		public:
			FileManager();
			~FileManager();
			char LoadFile(const char* filename);
			bool SaveFile();

		private:
			void CleanUp();

		};
	}
}
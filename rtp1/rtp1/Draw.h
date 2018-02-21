#pragma once

#include <vector>

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
		std::vector<Draw> m_MyDrawing;

	public:
		MyDrawing();
		void StartDrawing(System::EventArgs^ e);
		void FinishDrawing();


	private:
		void DrawingThread();
	};


}
#pragma once

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

	public:
		MyDrawing();
		void AddMyDrawing();


		void StartDrawing(System::EventArgs^ e);
		void FinishDrawing();


	private:
		void DrawingThread();
	};


}
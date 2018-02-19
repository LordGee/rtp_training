#pragma once

#include <vector>


struct Draw
{
	float x, y;
};

class MyDrawing {
private:
	std::vector<Draw> m_MyDrawing;

public:
	MyDrawing();
	//void StartDrawing(System::EventArgs^ e);
	void FinishDrawing();

private:
	void DrawingThread();
};
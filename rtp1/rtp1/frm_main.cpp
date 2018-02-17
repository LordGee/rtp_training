#include "frm_main.h"
#include <fstream>

using namespace System;
using namespace System::Windows::Forms;

public struct Grid {
	int posX, posY;
	char object;
};

void SetupGame();

std::vector<Grid>* m_Grid = new std::vector<Grid>;

int main () {
	SetupGame();

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	rtp1::frm_main mainForm;
	

	Application::Run(%mainForm);
}

void SetupGame()
{
	std::ifstream readGrid;
	readGrid.open("res/pong_half_grid.csv");
	int x = 0, y = 0, c = 0;
	char output;
	if (readGrid.is_open()) {
		while (!readGrid.eof()) {
			readGrid >> std::noskipws >> output;
			if (output != '\n') {
				Grid g;
				g.object = output;
				g.posX = x;
				g.posY = y;
				m_Grid->push_back(g);
				x++;
			} else {
				x = 0;
				y++;
			}
		}
	}
	readGrid.close();
}

System::Void rtp1::frm_main::pnl_GameCanvas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	const float width = 10.0f;
	float localX = width, localY = width;

	for each (Grid g in *m_Grid) {
		if (g.object == 'X') {
			Pen^ skyBluePen = gcnew Pen(Brushes::LightSkyBlue);
			skyBluePen->Width = 1;
			e->Graphics->DrawRectangle(skyBluePen, Rectangle(g.posX * localX + localX, g.posY * localY + localY, width, width));
		}
	}
}

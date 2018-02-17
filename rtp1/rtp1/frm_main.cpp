#include "frm_main.h"
#include "Game.h"
#include <fstream>

using namespace System;
using namespace System::Windows::Forms;
using namespace rtp1;

Game* game;
std::vector<Grid>* m_Grid = new std::vector<Grid>;
void SetupGame();



int main () {

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	rtp1::frm_main mainForm;
	Application::Run(%mainForm);

	
}

void SetupGame()
{
	
}

void rtp1::frm_main::RefreshCanvas()
{
	// GET THIS TO WORK
	//pnl_GameCanvas.Refresh();
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

System::Void rtp1::frm_main::btn_Play_Click(System::Object^ sender, System::EventArgs^ e)
{
	game = &Game(Game::PONG);
}



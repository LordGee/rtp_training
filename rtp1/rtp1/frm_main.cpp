#include "frm_main.h"
#include <vector>
#include "Draw.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace rtp1;

std::vector<Draw>* draw = new std::vector<Draw>;

[STAThread]
int main () {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	rtp1::frm_main mainForm;
	Application::Run(%mainForm);
}

System::Void rtp1::frm_main::pnl_GameCanvas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	for each (Draw d in *draw) {
		Pen^ skyBluePen = gcnew Pen(Brushes::LightSkyBlue);
		skyBluePen->Width = 5;
		e->Graphics->DrawEllipse(skyBluePen, (int)d.x, (int)d.y, 10, 10);
	}
}

System::Void rtp1::frm_main::btn_Play_Click(System::Object^ sender, System::EventArgs^ e)
{
	
}

System::Void rtp1::frm_main::btn_StopGame_Click(System::Object^ sender, System::EventArgs^ e)
{
	m_GameRunning = false;
}

System::Void rtp1::frm_main::pnl_GameCanvas_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	m_DrawingNow = true;
}

System::Void rtp1::frm_main::pnl_GameCanvas_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (m_DrawingNow)
	{
		if (e->Button == System::Windows::Forms::MouseButtons::Left)
		{
			Draw d;
			d.x = e->X;
			d.y = e->Y;
			draw->push_back(d);
		}
		else if (e->Button == System::Windows::Forms::MouseButtons::Right) {
			draw->pop_back();
		}
	}
}

System::Void rtp1::frm_main::pnl_GameCanvas_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	m_DrawingNow = false;
	pnl_GameCanvas->Refresh();
}


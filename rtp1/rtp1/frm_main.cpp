#include "frm_main.h"
#include <vector>
#include "Draw.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Drawing::Drawing2D;
using namespace rtp1;

std::vector<Draw>* draw = new std::vector<Draw>;
MyDrawing d;

[STAThread]
int main () {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	rtp1::frm_main mainForm;
	Application::Run(%mainForm);
}

System::Void rtp1::frm_main::pnl_GameCanvas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	SolidBrush^ brush = gcnew SolidBrush(Color::White);
	for each (Draw d in *draw) {
		e->Graphics->FillEllipse(brush, (int)d.x, (int)d.y, 20, 20);
	}
}

System::Void rtp1::frm_main::pnl_GameCanvas_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	m_DrawingNow = true;
	if (e->Button == System::Windows::Forms::MouseButtons::Right) {
		if (draw->size() > 0)
		{
			draw->pop_back();
		}
	}
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
	}
}

System::Void rtp1::frm_main::pnl_GameCanvas_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	m_DrawingNow = false;
	pnl_GameCanvas->Refresh();

	//Bitmap bmp(100, 100);
	Bitmap ^bmp = gcnew Bitmap(pnl_GameCanvas->ClientSize.Width, pnl_GameCanvas->ClientSize.Height);
	pnl_GameCanvas->DrawToBitmap(bmp, pnl_GameCanvas->ClientRectangle);

	// ref: https://www.pcreview.co.uk/threads/how-do-you-resize-an-image-in-managed-c-net-using-gdi-or-gdi.2286087/

	Bitmap ^bmp2 = gcnew Bitmap(
		(int)(bmp->Width * 0.025),
		(int)(bmp->Height * 0.025),
		PixelFormat::Format24bppRgb
	);

	Graphics ^g = Graphics::FromImage(bmp2);
	g->InterpolationMode = InterpolationMode::HighQualityBicubic;
	g->DrawImage(bmp, 0, 0, bmp2->Width, bmp2->Height);

	bmp2->Save("../unmanaged/img/temp.bmp");

	MyDrawing d;
	d.AddMyDrawing();
	
	

	delete bmp;
	delete bmp2;
}

System::Void rtp1::frm_main::btn_ClearPanel_Click(System::Object^ sender, System::EventArgs^ e)
{
	draw->clear();
	pnl_GameCanvas->Refresh();
}

System::Void rtp1::frm_main::cbx_Quality_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	switch ((int)cbx_Quality->SelectedIndex) {
	case 0:
		m_Quality = 0.025;
		break;
	default:
		m_Quality = 0.025;
		break;
	}
		


}

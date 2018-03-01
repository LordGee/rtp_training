#include "frm_main.h"
#include "Draw.h"
#include "abc.h"
#include <vector>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Imaging;
using namespace System::Drawing::Drawing2D;
using namespace System::Runtime::InteropServices;
using namespace rtp1;
using namespace rtp1::my_letters;

MyDrawing d;
std::vector<Draw>* draw = new std::vector<Draw>;
std::vector<char>* letters = new std::vector<char>;

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
	if (m_DrawingNow) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			Draw d;
			d.x = (float)e->X;
			d.y = (float)e->Y;
			draw->push_back(d);
		}
	}
}

System::Void rtp1::frm_main::pnl_GameCanvas_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	m_DrawingNow = false;
	pnl_GameCanvas->Refresh();

	Bitmap ^bmp = gcnew Bitmap(pnl_GameCanvas->ClientSize.Width, pnl_GameCanvas->ClientSize.Height);
	pnl_GameCanvas->DrawToBitmap(bmp, pnl_GameCanvas->ClientRectangle);

	// ref: https://www.pcreview.co.uk/threads/how-do-you-resize-an-image-in-managed-c-net-using-gdi-or-gdi.2286087/

	Bitmap ^bmp2 = gcnew Bitmap(
		(int)(m_Quality),
		(int)(m_Quality),
		PixelFormat::Format24bppRgb
	);
	Graphics ^g = Graphics::FromImage(bmp2);
	g->InterpolationMode = InterpolationMode::HighQualityBicubic;
	g->DrawImage(bmp, 0, 0, bmp2->Width, bmp2->Height);

	bmp2->Save("img/temp.bmp");

	MyDrawing d;
	d.AddMyDrawing();
	if (!m_Training) { 
		d.AnalyseMyLetter(m_Quality * m_Quality, m_Hidden, (int)((m_Quality * m_Quality) - (int)(letters->size())), (int)letters->size());
	} else {
		d.TrainMyLetter('g');
	}

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
	case 0:	m_Quality = 15;
		break;
	case 1:	m_Quality = 30;
		break;
	case 2:	m_Quality = 60;
		break;
	default: m_Quality = 15;
		break;
	}
}

System::Void rtp1::frm_main::cbx_ProjectType_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	((int)cbx_ProjectType->SelectedIndex == 0) ? m_Training = true : m_Training = false;
	if (m_Training)	{
		lbl_Operations2->Visible = true;
		cbx_TrainingValue->Visible = true;
	} else {
		lbl_Operations2->Visible = false;
		cbx_TrainingValue->Visible = false;
	}
}

System::Void rtp1::frm_main::nud_HiddenLayers_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	m_Hidden = (int)nud_HiddenLayers->Value;
}

System::Void rtp1::frm_main::cbx_Output_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	SetLetterArray(cbx_Output->SelectedIndex, *letters);
	m_LettersSet = true;
}

System::Void rtp1::frm_main::tbx_NewName_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (tbx_NewName->TextLength >= 3) {
		SetCreateVisibility(true);
	} else {
		SetCreateVisibility(false);
	}
}

void rtp1::frm_main::SetCreateVisibility(bool _value)
{
	lbl_Create2->Visible = _value;
	lbl_Create3->Visible = _value;
	lbl_Create4->Visible = _value;
	lbl_Create5->Visible = _value;
	cbx_Quality->Visible = _value;
	nud_HiddenLayers->Visible = _value;
	cbx_Output->Visible = _value;
	btn_Create->Visible = _value;
	nud_LearningRate->Visible = _value;
	nud_MomentumFactor->Visible = _value;
	cbx_UseMomentum->Visible = _value;
	cbx_LinearOutput->Visible = _value;
}

System::Void rtp1::frm_main::tbx_ExistName_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (tbx_ExistName->TextLength >= 3)	{
		btn_Load->Visible = true;
		String^ test = tbx_ExistName->Text;
	} else {
		btn_Load->Visible = false;
	}
}

System::Void rtp1::frm_main::btn_Load_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ temp = tbx_ExistName->Text;
	temp = temp->ToLower();
	// Reference: https://stackoverflow.com/questions/1098431/how-do-i-convert-a-systemstring-to-const-char
	m_Name = (const char*)(Marshal::StringToHGlobalAnsi(temp)).ToPointer();
	d.NNInitLoad(m_Name);
}

System::Void rtp1::frm_main::btn_Create_Click(System::Object^ sender, System::EventArgs^ e)
{
	String^ temp = tbx_NewName->Text;
	temp = temp->ToLower();
	m_Name = (const char*)(Marshal::StringToHGlobalAnsi(temp)).ToPointer();
	if (!m_LettersSet) {
		SetLetterArray(3, *letters);
	}
	// TODO: come back change output value
	d.NNInitNew(m_Name, m_Quality * m_Quality, m_Hidden, letters->size(),
		(double)nud_LearningRate->Value, cbx_UseMomentum->Checked, 
		(double)nud_MomentumFactor->Value, cbx_LinearOutput->Checked);

}


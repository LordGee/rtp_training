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

/* When the panel is refreshed the paint function is activated and draws the x,y from an array to the panel */
System::Void rtp1::frm_main::pnl_GameCanvas_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	SolidBrush^ brush = gcnew SolidBrush(Color::White);
	for each (Draw dr in *draw) {
		e->Graphics->FillEllipse(brush, (int)dr.x, (int)dr.y, 20, 20);
	}
}

/* When a mouse down action is detected on this panel the drawing boolean becomes active, if the right mouse 
 * button is pressed will remove the last element from the drawing array */
System::Void rtp1::frm_main::pnl_GameCanvas_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (m_NNRunning) {
		if (e->Button == System::Windows::Forms::MouseButtons::Right) {
			if (draw->size() > 0) {
				draw->pop_back();
			}
		} else if(e->Button == System::Windows::Forms::MouseButtons::Left) {
			m_DrawingNow = true;
		}
	}
}

/* If the left mouse button is pressed, while moving across the panel, each coordinate is recorded into the draw array */
System::Void rtp1::frm_main::pnl_GameCanvas_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (m_DrawingNow) {
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			Draw dr;
			dr.x = (float)e->X;
			dr.y = (float)e->Y;
			draw->push_back(dr);
		}
	}
}

/* After drawing the mouse button is released and the process of manipulating the and passing it to processed begins */
System::Void rtp1::frm_main::pnl_GameCanvas_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	if (m_NNRunning && m_DrawingNow) {
		UpdateStatus(Status::PROCESSING);
		m_DrawingNow = false;
		pnl_GameCanvas->Refresh();
		Bitmap ^bmp = gcnew Bitmap(pnl_GameCanvas->ClientSize.Width, 
			pnl_GameCanvas->ClientSize.Height);
		pnl_GameCanvas->DrawToBitmap(bmp, pnl_GameCanvas->ClientRectangle);
		// Resize image for processing
		// ref: https://www.pcreview.co.uk/threads/how-do-you-resize-an-image-in-managed-c-net-using-gdi-or-gdi.2286087/
		Bitmap ^bmp2 = gcnew Bitmap(
			(int)(m_Quality),
			(int)(m_Quality),
			PixelFormat::Format24bppRgb	);
		Graphics ^g = Graphics::FromImage(bmp2);
		g->InterpolationMode = InterpolationMode::HighQualityBicubic;
		g->DrawImage(bmp, 0, 0, bmp2->Width, bmp2->Height);
		bmp2->Save(IMG_LOCATION);
		ProcessDrawing();
		delete bmp;
		delete bmp2;
	}
}

/* When the clear button is pressed will remove all elements from the draw array, and then 
 * refresh the panel. As there are no elements within the array nothing will be drawn */
System::Void rtp1::frm_main::btn_ClearPanel_Click(System::Object^ sender, System::EventArgs^ e)
{
	draw->clear();
	pnl_GameCanvas->Refresh();
}

/* As the value changes within the combo box the new value is then recorded */
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

/* As the value changes within the combo box the new value is then recorded, depending on the option change depends on the other options being visiable */
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

/* Currently just sets to a value of one regardless, hopefully will improve on this in the future */
System::Void rtp1::frm_main::nud_HiddenLayers_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
	// m_Hidden = (int)nud_HiddenLayers->Value;
	m_Hidden = 1; // to be reverted to the above once the application allows for multiple hidden layers
}


/* As the value changes within the combo box the new value then adds the appropriate letter array */
System::Void rtp1::frm_main::cbx_Output_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
{
	SetLetterArray(cbx_Output->SelectedIndex, *letters);
	m_LetterCase = cbx_Output->SelectedIndex;
	m_LettersSet = true;
}

/* Ensure text boxes contain at least three characters before becoming active */
System::Void rtp1::frm_main::tbx_NewName_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (tbx_NewName->TextLength >= 3) {
		SetCreateVisibility(true);
	} else {
		SetCreateVisibility(false);
	}
}

/* Sets the visibility of the creation of a NN once a new name is given */
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

/* Updates the status label depending on the enum value passed in */
void rtp1::frm_main::UpdateStatus(Status status)
{
	if (status == Status::AWAITING) {
		lbl_Status->Text = "Awaiting Neural Network to be Activated!";
		lbl_Status->ForeColor = ForeColor.Red;
		m_NNRunning = false;
	} else if (status == Status::PROCESSING) {
		lbl_Status->Text = "PROCESSING... Please wait.";
		lbl_Status->ForeColor = ForeColor.DarkOrange;
		m_NNRunning = false;
	} else if (status == Status::READY) {
		lbl_Status->Text = "READY";
		lbl_Status->ForeColor = ForeColor.Green;
		m_NNRunning = true;
		lbl_Operations1->Visible = true;
		cbx_ProjectType->Visible = true;
	}
	lbl_Status->Refresh();
}

/* Updates the results of the analysis or training of a character */
void rtp1::frm_main::UpdateResults(int output)
{
	Char result = letters->at(output);
	lbl_Result->Text = result.ToString();
	UpdateStatus(Status::READY);
}

/* Processes the drawing and demands a result from the neural network, this
 * result is then updated to the results label */
void rtp1::frm_main::ProcessDrawing()
{
	d.AddMyDrawing();
	if (!m_Training) {
		m_OutputResult = d.AnalyseMyLetter();
	} else {
		m_OutputResult = d.TrainMyLetter(cbx_TrainingValue->SelectedIndex);
	}
	UpdateResults(m_OutputResult);
}


/* Ensure text boxes contain at least three characters before becoming active */
System::Void rtp1::frm_main::tbx_ExistName_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (tbx_ExistName->TextLength >= 3)	{
		btn_Load->Visible = true;
	} else {
		btn_Load->Visible = false;
	}
}

/* When the load button is pressed, begins the process of loading the NN info back in */
System::Void rtp1::frm_main::btn_Load_Click(System::Object^ sender, System::EventArgs^ e)
{
	UpdateStatus(Status::PROCESSING);
	String^ temp = tbx_ExistName->Text;
	temp = temp->ToLower();
	// Reference: https://stackoverflow.com/questions/1098431/how-do-i-convert-a-systemstring-to-const-char
	m_Name = (const char*)(Marshal::StringToHGlobalAnsi(temp)).ToPointer();
	std::vector<double> info = d.NNInitLoad(m_Name);
	if (info.size() > 0) {
		m_LetterCase = info[7];
		SetLetterArray(m_LetterCase, *letters);
		m_Quality = sqrt(info[0]);
		m_Hidden = info[1];
		UpdateStatus(Status::READY);
	} else {
		UpdateStatus(Status::AWAITING);
	}
}

/* When the create button is pressed, begins the process of generating a new NN */
System::Void rtp1::frm_main::btn_Create_Click(System::Object^ sender, System::EventArgs^ e)
{
	UpdateStatus(Status::PROCESSING);
	String^ temp = tbx_NewName->Text;
	temp = temp->ToLower();
	m_Name = (const char*)(Marshal::StringToHGlobalAnsi(temp)).ToPointer();
	if (!m_LettersSet) {
		SetLetterArray(0, *letters);
		m_LetterCase = 0;
	}
	d.NNInitNew(m_Name, m_Quality * m_Quality, m_Hidden, letters->size(),
		(double)nud_LearningRate->Value, cbx_UseMomentum->Checked, 
		(double)nud_MomentumFactor->Value, cbx_LinearOutput->Checked, m_LetterCase);
	UpdateStatus(Status::READY);
}

/* When the training value combo box is selected will load into the items the values 
 * from the currently active letter array*/
System::Void rtp1::frm_main::cbx_TrainingValue_Click(System::Object^ sender, System::EventArgs^ e)
{
	cbx_TrainingValue->Items->Clear();
	for (int i = 0; i < letters->size(); i++) {
		Char result = letters->at(i);
		cbx_TrainingValue->Items->Add(result.ToString());
	}
}
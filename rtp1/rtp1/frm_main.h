#pragma once

#include <vector>

namespace rtp1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

	public ref class frm_main : public System::Windows::Forms::Form
	{
	private:
		bool m_GameRunning = false;
		bool m_DrawingNow = false;
		

	public:
		frm_main(void) { InitializeComponent();	}

	protected:
		~frm_main()	{ if (components) {	delete components; } }

	// User Components
	private: System::Windows::Forms::Panel^  pnl_StartOptions;
	private: System::Windows::Forms::Panel^  pnl_StatInfo;
	private: System::Windows::Forms::Button^  btn_Play;
	public: System::Windows::Forms::Panel^  pnl_GameCanvas;
	private: System::Windows::Forms::Button^  btn_StopGame;
	
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			this->pnl_StartOptions = (gcnew System::Windows::Forms::Panel());
			this->btn_Play = (gcnew System::Windows::Forms::Button());
			this->pnl_StatInfo = (gcnew System::Windows::Forms::Panel());
			this->btn_StopGame = (gcnew System::Windows::Forms::Button());
			this->pnl_GameCanvas = (gcnew System::Windows::Forms::Panel());
			this->pnl_StartOptions->SuspendLayout();
			this->pnl_StatInfo->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnl_StartOptions
			// 
			this->pnl_StartOptions->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->pnl_StartOptions->Controls->Add(this->btn_Play);
			this->pnl_StartOptions->Location = System::Drawing::Point(18, 18);
			this->pnl_StartOptions->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pnl_StartOptions->Name = L"pnl_StartOptions";
			this->pnl_StartOptions->Size = System::Drawing::Size(450, 1011);
			this->pnl_StartOptions->TabIndex = 0;
			// 
			// btn_Play
			// 
			this->btn_Play->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btn_Play->Location = System::Drawing::Point(150, 850);
			this->btn_Play->Name = L"btn_Play";
			this->btn_Play->Size = System::Drawing::Size(100, 50);
			this->btn_Play->TabIndex = 0;
			this->btn_Play->Text = L"Play";
			this->btn_Play->UseVisualStyleBackColor = false;
			this->btn_Play->Click += gcnew System::EventHandler(this, &frm_main::btn_Play_Click);
			// 
			// pnl_StatInfo
			// 
			this->pnl_StatInfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->pnl_StatInfo->Controls->Add(this->btn_StopGame);
			this->pnl_StatInfo->Location = System::Drawing::Point(1428, 18);
			this->pnl_StatInfo->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pnl_StatInfo->Name = L"pnl_StatInfo";
			this->pnl_StatInfo->Size = System::Drawing::Size(450, 1011);
			this->pnl_StatInfo->TabIndex = 1;
			// 
			// btn_StopGame
			// 
			this->btn_StopGame->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->btn_StopGame->Location = System::Drawing::Point(150, 850);
			this->btn_StopGame->Name = L"btn_StopGame";
			this->btn_StopGame->Size = System::Drawing::Size(100, 50);
			this->btn_StopGame->TabIndex = 1;
			this->btn_StopGame->Text = L"Stop";
			this->btn_StopGame->UseVisualStyleBackColor = false;
			this->btn_StopGame->Click += gcnew System::EventHandler(this, &frm_main::btn_StopGame_Click);
			// 
			// pnl_GameCanvas
			// 
			this->pnl_GameCanvas->BackColor = System::Drawing::Color::Black;
			this->pnl_GameCanvas->Location = System::Drawing::Point(500, 60);
			this->pnl_GameCanvas->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pnl_GameCanvas->Name = L"pnl_GameCanvas";
			this->pnl_GameCanvas->Size = System::Drawing::Size(900, 923);
			this->pnl_GameCanvas->TabIndex = 2;
			this->pnl_GameCanvas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frm_main::pnl_GameCanvas_Paint);
			this->pnl_GameCanvas->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &frm_main::pnl_GameCanvas_MouseDown);
			this->pnl_GameCanvas->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &frm_main::pnl_GameCanvas_MouseMove);
			this->pnl_GameCanvas->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &frm_main::pnl_GameCanvas_MouseUp);
			// 
			// frm_main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1896, 1048);
			this->Controls->Add(this->pnl_GameCanvas);
			this->Controls->Add(this->pnl_StatInfo);
			this->Controls->Add(this->pnl_StartOptions);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"frm_main";
			this->Text = L"RTP Learning";
			this->pnl_StartOptions->ResumeLayout(false);
			this->pnl_StatInfo->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pnl_GameCanvas_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
	private: System::Void btn_Play_Click(System::Object^  sender, System::EventArgs^  e); 
	private: System::Void btn_StopGame_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void pnl_GameCanvas_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void pnl_GameCanvas_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void pnl_GameCanvas_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);

};
}

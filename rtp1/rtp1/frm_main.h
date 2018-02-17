#pragma once

#include "Game.h"
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

	public:
		frm_main(void) { InitializeComponent();	}

	protected:
		~frm_main()	{ if (components) {	delete components; } }

	// User Components
	private: System::Windows::Forms::Panel^  pnl_StartOptions;
	private: System::Windows::Forms::Panel^  pnl_StatInfo;
	public: System::Windows::Forms::Panel^  pnl_GameCanvas;
	
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			this->pnl_StartOptions = (gcnew System::Windows::Forms::Panel());
			this->pnl_StatInfo = (gcnew System::Windows::Forms::Panel());
			this->pnl_GameCanvas = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// pnl_StartOptions
			// 
			this->pnl_StartOptions->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->pnl_StartOptions->Location = System::Drawing::Point(12, 12);
			this->pnl_StartOptions->Name = L"pnl_StartOptions";
			this->pnl_StartOptions->Size = System::Drawing::Size(300, 657);
			this->pnl_StartOptions->TabIndex = 0;
			// 
			// pnl_StatInfo
			// 
			this->pnl_StatInfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->pnl_StatInfo->Location = System::Drawing::Point(952, 12);
			this->pnl_StatInfo->Name = L"pnl_StatInfo";
			this->pnl_StatInfo->Size = System::Drawing::Size(300, 657);
			this->pnl_StatInfo->TabIndex = 1;
			// 
			// pnl_GameCanvas
			// 
			this->pnl_GameCanvas->BackColor = System::Drawing::Color::Black;
			this->pnl_GameCanvas->Location = System::Drawing::Point(333, 39);
			this->pnl_GameCanvas->Name = L"pnl_GameCanvas";
			this->pnl_GameCanvas->Size = System::Drawing::Size(600, 600);
			this->pnl_GameCanvas->TabIndex = 2;
			this->pnl_GameCanvas->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frm_main::pnl_GameCanvas_Paint);
			// 
			// frm_main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->pnl_GameCanvas);
			this->Controls->Add(this->pnl_StatInfo);
			this->Controls->Add(this->pnl_StartOptions);
			this->DoubleBuffered = true;
			this->Name = L"frm_main";
			this->Text = L"RTP Learning";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pnl_GameCanvas_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
	};
}

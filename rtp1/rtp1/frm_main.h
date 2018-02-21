#pragma once


namespace rtp1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class frm_main : public System::Windows::Forms::Form
	{
	private:
		bool m_GameRunning = false;
		bool m_DrawingNow = false;
		bool m_Training = false;
		float m_Quality = 0.025f;
		
	public:
		frm_main(void) { InitializeComponent();	}

	protected:
		~frm_main()	{ if (components) {	delete components; } }

	private: System::Windows::Forms::Panel^  pnl_StartOptions;
	private: System::Windows::Forms::Panel^  pnl_StatInfo;
	private: System::Windows::Forms::ComboBox^  cbx_ProjectType;
	private: System::Windows::Forms::Button^  btn_ClearPanel;
	public: System::Windows::Forms::Panel^  pnl_GameCanvas;
	private: System::Windows::Forms::ComboBox^  cbx_Quality;
	
	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void) {
			this->pnl_StartOptions = (gcnew System::Windows::Forms::Panel());
			this->cbx_Quality = (gcnew System::Windows::Forms::ComboBox());
			this->btn_ClearPanel = (gcnew System::Windows::Forms::Button());
			this->cbx_ProjectType = (gcnew System::Windows::Forms::ComboBox());
			this->pnl_StatInfo = (gcnew System::Windows::Forms::Panel());
			this->pnl_GameCanvas = (gcnew System::Windows::Forms::Panel());
			this->pnl_StartOptions->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnl_StartOptions
			// 
			this->pnl_StartOptions->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->pnl_StartOptions->Controls->Add(this->cbx_Quality);
			this->pnl_StartOptions->Controls->Add(this->btn_ClearPanel);
			this->pnl_StartOptions->Controls->Add(this->cbx_ProjectType);
			this->pnl_StartOptions->Location = System::Drawing::Point(12, 12);
			this->pnl_StartOptions->Name = L"pnl_StartOptions";
			this->pnl_StartOptions->Size = System::Drawing::Size(300, 657);
			this->pnl_StartOptions->TabIndex = 0;
			// 
			// cbx_Quality
			// 
			this->cbx_Quality->FormattingEnabled = true;
			this->cbx_Quality->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"15x15 (Low Quality / High Performance)", L"30x30 (In the middle)",
					L"60x60 (High Quality / Low Performance)"
			});
			this->cbx_Quality->Location = System::Drawing::Point(68, 92);
			this->cbx_Quality->Name = L"cbx_Quality";
			this->cbx_Quality->Size = System::Drawing::Size(150, 21);
			this->cbx_Quality->TabIndex = 2;
			this->cbx_Quality->Text = L"Select Quality";
			this->cbx_Quality->SelectedIndexChanged += gcnew System::EventHandler(this, &frm_main::cbx_Quality_SelectedIndexChanged);
			// 
			// btn_ClearPanel
			// 
			this->btn_ClearPanel->Location = System::Drawing::Point(65, 217);
			this->btn_ClearPanel->Name = L"btn_ClearPanel";
			this->btn_ClearPanel->Size = System::Drawing::Size(75, 23);
			this->btn_ClearPanel->TabIndex = 1;
			this->btn_ClearPanel->Text = L"Clear";
			this->btn_ClearPanel->UseVisualStyleBackColor = true;
			this->btn_ClearPanel->Click += gcnew System::EventHandler(this, &frm_main::btn_ClearPanel_Click);
			// 
			// cbx_ProjectType
			// 
			this->cbx_ProjectType->FormattingEnabled = true;
			this->cbx_ProjectType->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Training", L"Analysis" });
			this->cbx_ProjectType->Location = System::Drawing::Point(68, 39);
			this->cbx_ProjectType->Name = L"cbx_ProjectType";
			this->cbx_ProjectType->Size = System::Drawing::Size(150, 21);
			this->cbx_ProjectType->TabIndex = 0;
			this->cbx_ProjectType->Text = L"Select Method";
			this->cbx_ProjectType->SelectedIndexChanged += gcnew System::EventHandler(this, &frm_main::cbx_ProjectType_SelectedIndexChanged);
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
			this->pnl_GameCanvas->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &frm_main::pnl_GameCanvas_MouseDown);
			this->pnl_GameCanvas->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &frm_main::pnl_GameCanvas_MouseMove);
			this->pnl_GameCanvas->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &frm_main::pnl_GameCanvas_MouseUp);
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
			this->pnl_StartOptions->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void pnl_GameCanvas_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
	private: System::Void pnl_GameCanvas_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void pnl_GameCanvas_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void pnl_GameCanvas_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn_ClearPanel_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbx_Quality_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbx_ProjectType_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
};
}

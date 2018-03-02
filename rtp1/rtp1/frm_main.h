#pragma once

namespace rtp1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	 public enum class Status {
		PROCESSING,
		READY,
		AWAITING
	};

	public ref class frm_main : public System::Windows::Forms::Form
	{
	
	private:
		bool m_NNInit = false;
		bool m_NNRunning = false;
		bool m_DrawingNow = false;
		bool m_Training = false;
		bool m_LettersSet = false;
		int m_Quality = 15, m_Hidden = 1;
		const char* m_Name;
		int m_OutputResult, m_LetterCase;
		
	private: System::Windows::Forms::NumericUpDown^  nud_HiddenLayers;
	private: System::Windows::Forms::Label^  lbl_Create4;

	private: System::Windows::Forms::Label^  lbl_Create3;

	private: System::Windows::Forms::Label^  lbl_Create2;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  btn_Load;

	public: System::Windows::Forms::TextBox^  tbx_ExistName;


	private: System::Windows::Forms::Label^  lbl_Create1;
	private: System::Windows::Forms::TextBox^  tbx_NewName;



	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Button^  btn_Create;
	private: System::Windows::Forms::Label^  lbl_Operations2;


	private: System::Windows::Forms::ComboBox^  cbx_TrainingValue;
	private: System::Windows::Forms::Label^  lbl_Operations1;


	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::NumericUpDown^  nud_MomentumFactor;
	private: System::Windows::Forms::NumericUpDown^  nud_LearningRate;
	private: System::Windows::Forms::CheckBox^  cbx_UseMomentum;
	private: System::Windows::Forms::CheckBox^  cbx_LinearOutput;
	private: System::Windows::Forms::Label^  lbl_Create5;
	private: System::Windows::Forms::Label^  lbl_Status;
	private: System::Windows::Forms::Label^  lbl_Result;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  cbx_Output;
		
			
		
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
			this->cbx_LinearOutput = (gcnew System::Windows::Forms::CheckBox());
			this->lbl_Create5 = (gcnew System::Windows::Forms::Label());
			this->nud_MomentumFactor = (gcnew System::Windows::Forms::NumericUpDown());
			this->nud_LearningRate = (gcnew System::Windows::Forms::NumericUpDown());
			this->cbx_UseMomentum = (gcnew System::Windows::Forms::CheckBox());
			this->btn_Create = (gcnew System::Windows::Forms::Button());
			this->lbl_Create1 = (gcnew System::Windows::Forms::Label());
			this->tbx_NewName = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->lbl_Create4 = (gcnew System::Windows::Forms::Label());
			this->lbl_Create3 = (gcnew System::Windows::Forms::Label());
			this->lbl_Create2 = (gcnew System::Windows::Forms::Label());
			this->nud_HiddenLayers = (gcnew System::Windows::Forms::NumericUpDown());
			this->cbx_Output = (gcnew System::Windows::Forms::ComboBox());
			this->cbx_Quality = (gcnew System::Windows::Forms::ComboBox());
			this->btn_ClearPanel = (gcnew System::Windows::Forms::Button());
			this->cbx_ProjectType = (gcnew System::Windows::Forms::ComboBox());
			this->pnl_StatInfo = (gcnew System::Windows::Forms::Panel());
			this->lbl_Result = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pnl_GameCanvas = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btn_Load = (gcnew System::Windows::Forms::Button());
			this->tbx_ExistName = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->lbl_Operations2 = (gcnew System::Windows::Forms::Label());
			this->cbx_TrainingValue = (gcnew System::Windows::Forms::ComboBox());
			this->lbl_Operations1 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->lbl_Status = (gcnew System::Windows::Forms::Label());
			this->pnl_StartOptions->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_MomentumFactor))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_LearningRate))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_HiddenLayers))->BeginInit();
			this->pnl_StatInfo->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// pnl_StartOptions
			// 
			this->pnl_StartOptions->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->pnl_StartOptions->Controls->Add(this->cbx_LinearOutput);
			this->pnl_StartOptions->Controls->Add(this->lbl_Create5);
			this->pnl_StartOptions->Controls->Add(this->nud_MomentumFactor);
			this->pnl_StartOptions->Controls->Add(this->nud_LearningRate);
			this->pnl_StartOptions->Controls->Add(this->cbx_UseMomentum);
			this->pnl_StartOptions->Controls->Add(this->btn_Create);
			this->pnl_StartOptions->Controls->Add(this->lbl_Create1);
			this->pnl_StartOptions->Controls->Add(this->tbx_NewName);
			this->pnl_StartOptions->Controls->Add(this->label6);
			this->pnl_StartOptions->Controls->Add(this->lbl_Create4);
			this->pnl_StartOptions->Controls->Add(this->lbl_Create3);
			this->pnl_StartOptions->Controls->Add(this->lbl_Create2);
			this->pnl_StartOptions->Controls->Add(this->nud_HiddenLayers);
			this->pnl_StartOptions->Controls->Add(this->cbx_Output);
			this->pnl_StartOptions->Controls->Add(this->cbx_Quality);
			this->pnl_StartOptions->Location = System::Drawing::Point(12, 137);
			this->pnl_StartOptions->Name = L"pnl_StartOptions";
			this->pnl_StartOptions->Size = System::Drawing::Size(300, 345);
			this->pnl_StartOptions->TabIndex = 0;
			// 
			// cbx_LinearOutput
			// 
			this->cbx_LinearOutput->AutoSize = true;
			this->cbx_LinearOutput->Location = System::Drawing::Point(52, 273);
			this->cbx_LinearOutput->Margin = System::Windows::Forms::Padding(2);
			this->cbx_LinearOutput->Name = L"cbx_LinearOutput";
			this->cbx_LinearOutput->Size = System::Drawing::Size(112, 17);
			this->cbx_LinearOutput->TabIndex = 15;
			this->cbx_LinearOutput->Text = L"Use Linear Output";
			this->cbx_LinearOutput->UseVisualStyleBackColor = true;
			this->cbx_LinearOutput->Visible = false;
			// 
			// lbl_Create5
			// 
			this->lbl_Create5->AutoSize = true;
			this->lbl_Create5->Location = System::Drawing::Point(52, 220);
			this->lbl_Create5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Create5->Name = L"lbl_Create5";
			this->lbl_Create5->Size = System::Drawing::Size(77, 13);
			this->lbl_Create5->TabIndex = 14;
			this->lbl_Create5->Text = L"Learning Rate:";
			this->lbl_Create5->Visible = false;
			// 
			// nud_MomentumFactor
			// 
			this->nud_MomentumFactor->DecimalPlaces = 1;
			this->nud_MomentumFactor->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->nud_MomentumFactor->Location = System::Drawing::Point(172, 244);
			this->nud_MomentumFactor->Margin = System::Windows::Forms::Padding(2);
			this->nud_MomentumFactor->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nud_MomentumFactor->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->nud_MomentumFactor->Name = L"nud_MomentumFactor";
			this->nud_MomentumFactor->Size = System::Drawing::Size(80, 20);
			this->nud_MomentumFactor->TabIndex = 13;
			this->nud_MomentumFactor->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9, 0, 0, 65536 });
			this->nud_MomentumFactor->Visible = false;
			// 
			// nud_LearningRate
			// 
			this->nud_LearningRate->DecimalPlaces = 1;
			this->nud_LearningRate->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->nud_LearningRate->Location = System::Drawing::Point(172, 218);
			this->nud_LearningRate->Margin = System::Windows::Forms::Padding(2);
			this->nud_LearningRate->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nud_LearningRate->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 65536 });
			this->nud_LearningRate->Name = L"nud_LearningRate";
			this->nud_LearningRate->Size = System::Drawing::Size(80, 20);
			this->nud_LearningRate->TabIndex = 12;
			this->nud_LearningRate->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 9, 0, 0, 65536 });
			this->nud_LearningRate->Visible = false;
			// 
			// cbx_UseMomentum
			// 
			this->cbx_UseMomentum->AutoSize = true;
			this->cbx_UseMomentum->Location = System::Drawing::Point(52, 245);
			this->cbx_UseMomentum->Margin = System::Windows::Forms::Padding(2);
			this->cbx_UseMomentum->Name = L"cbx_UseMomentum";
			this->cbx_UseMomentum->Size = System::Drawing::Size(100, 17);
			this->cbx_UseMomentum->TabIndex = 11;
			this->cbx_UseMomentum->Text = L"Use Momentum";
			this->cbx_UseMomentum->UseVisualStyleBackColor = true;
			this->cbx_UseMomentum->Visible = false;
			// 
			// btn_Create
			// 
			this->btn_Create->Location = System::Drawing::Point(121, 311);
			this->btn_Create->Margin = System::Windows::Forms::Padding(2);
			this->btn_Create->Name = L"btn_Create";
			this->btn_Create->Size = System::Drawing::Size(50, 21);
			this->btn_Create->TabIndex = 1;
			this->btn_Create->Text = L"Create";
			this->btn_Create->UseVisualStyleBackColor = true;
			this->btn_Create->Visible = false;
			this->btn_Create->Click += gcnew System::EventHandler(this, &frm_main::btn_Create_Click);
			// 
			// lbl_Create1
			// 
			this->lbl_Create1->AutoSize = true;
			this->lbl_Create1->Location = System::Drawing::Point(52, 39);
			this->lbl_Create1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Create1->Name = L"lbl_Create1";
			this->lbl_Create1->Size = System::Drawing::Size(78, 13);
			this->lbl_Create1->TabIndex = 10;
			this->lbl_Create1->Text = L"Give it a name:";
			// 
			// tbx_NewName
			// 
			this->tbx_NewName->Location = System::Drawing::Point(52, 54);
			this->tbx_NewName->Margin = System::Windows::Forms::Padding(2);
			this->tbx_NewName->Name = L"tbx_NewName";
			this->tbx_NewName->Size = System::Drawing::Size(201, 20);
			this->tbx_NewName->TabIndex = 1;
			this->tbx_NewName->TextChanged += gcnew System::EventHandler(this, &frm_main::tbx_NewName_TextChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(3, 3);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(244, 24);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Create New Neural Network";
			// 
			// lbl_Create4
			// 
			this->lbl_Create4->AutoSize = true;
			this->lbl_Create4->Location = System::Drawing::Point(52, 163);
			this->lbl_Create4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Create4->Name = L"lbl_Create4";
			this->lbl_Create4->Size = System::Drawing::Size(102, 13);
			this->lbl_Create4->TabIndex = 7;
			this->lbl_Create4->Text = L"Select Output Case:";
			this->lbl_Create4->Visible = false;
			// 
			// lbl_Create3
			// 
			this->lbl_Create3->AutoSize = true;
			this->lbl_Create3->Location = System::Drawing::Point(52, 123);
			this->lbl_Create3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Create3->Name = L"lbl_Create3";
			this->lbl_Create3->Size = System::Drawing::Size(130, 13);
			this->lbl_Create3->TabIndex = 6;
			this->lbl_Create3->Text = L"Number of Hidden Layers:";
			this->lbl_Create3->Visible = false;
			// 
			// lbl_Create2
			// 
			this->lbl_Create2->AutoSize = true;
			this->lbl_Create2->Location = System::Drawing::Point(52, 79);
			this->lbl_Create2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Create2->Name = L"lbl_Create2";
			this->lbl_Create2->Size = System::Drawing::Size(97, 13);
			this->lbl_Create2->TabIndex = 5;
			this->lbl_Create2->Text = L"Select Input Value:";
			this->lbl_Create2->Visible = false;
			// 
			// nud_HiddenLayers
			// 
			this->nud_HiddenLayers->Location = System::Drawing::Point(52, 138);
			this->nud_HiddenLayers->Margin = System::Windows::Forms::Padding(2);
			this->nud_HiddenLayers->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->nud_HiddenLayers->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nud_HiddenLayers->Name = L"nud_HiddenLayers";
			this->nud_HiddenLayers->Size = System::Drawing::Size(200, 20);
			this->nud_HiddenLayers->TabIndex = 3;
			this->nud_HiddenLayers->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->nud_HiddenLayers->Visible = false;
			this->nud_HiddenLayers->ValueChanged += gcnew System::EventHandler(this, &frm_main::nud_HiddenLayers_ValueChanged);
			// 
			// cbx_Output
			// 
			this->cbx_Output->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(3) {
				L"Lowercase \t(abc)", L"Uppercase \t(ABC)",
					L"Mixedcase\t(aBc)"
			});
			this->cbx_Output->FormattingEnabled = true;
			this->cbx_Output->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Lowercase (abc)", L"Uppercase (ABC)", L"Mixedcase (aBc)" });
			this->cbx_Output->Location = System::Drawing::Point(52, 178);
			this->cbx_Output->Margin = System::Windows::Forms::Padding(2);
			this->cbx_Output->Name = L"cbx_Output";
			this->cbx_Output->Size = System::Drawing::Size(201, 21);
			this->cbx_Output->TabIndex = 4;
			this->cbx_Output->Text = L"Select Output";
			this->cbx_Output->Visible = false;
			this->cbx_Output->SelectedIndexChanged += gcnew System::EventHandler(this, &frm_main::cbx_Output_SelectedIndexChanged);
			// 
			// cbx_Quality
			// 
			this->cbx_Quality->FormattingEnabled = true;
			this->cbx_Quality->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"15x15 = 225\t(Low Quality / High Performance)",
					L"30x30 = 900\t(In the middle)", L"60x60 = 3600\t(High Quality / Low Performance)"
			});
			this->cbx_Quality->Location = System::Drawing::Point(52, 96);
			this->cbx_Quality->Name = L"cbx_Quality";
			this->cbx_Quality->Size = System::Drawing::Size(201, 21);
			this->cbx_Quality->TabIndex = 2;
			this->cbx_Quality->Text = L"Select Quality";
			this->cbx_Quality->Visible = false;
			this->cbx_Quality->SelectedIndexChanged += gcnew System::EventHandler(this, &frm_main::cbx_Quality_SelectedIndexChanged);
			// 
			// btn_ClearPanel
			// 
			this->btn_ClearPanel->Location = System::Drawing::Point(595, 649);
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
			this->cbx_ProjectType->Location = System::Drawing::Point(52, 65);
			this->cbx_ProjectType->Name = L"cbx_ProjectType";
			this->cbx_ProjectType->Size = System::Drawing::Size(201, 21);
			this->cbx_ProjectType->TabIndex = 5;
			this->cbx_ProjectType->Text = L"Select Method";
			this->cbx_ProjectType->Visible = false;
			this->cbx_ProjectType->SelectedIndexChanged += gcnew System::EventHandler(this, &frm_main::cbx_ProjectType_SelectedIndexChanged);
			// 
			// pnl_StatInfo
			// 
			this->pnl_StatInfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->pnl_StatInfo->Controls->Add(this->lbl_Result);
			this->pnl_StatInfo->Controls->Add(this->label1);
			this->pnl_StatInfo->Location = System::Drawing::Point(952, 12);
			this->pnl_StatInfo->Name = L"pnl_StatInfo";
			this->pnl_StatInfo->Size = System::Drawing::Size(300, 657);
			this->pnl_StatInfo->TabIndex = 1;
			// 
			// lbl_Result
			// 
			this->lbl_Result->AutoSize = true;
			this->lbl_Result->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 128, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Result->Location = System::Drawing::Point(63, 214);
			this->lbl_Result->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Result->Name = L"lbl_Result";
			this->lbl_Result->Size = System::Drawing::Size(177, 193);
			this->lbl_Result->TabIndex = 1;
			this->lbl_Result->Text = L"\?";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(8, 6);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Results";
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
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->btn_Load);
			this->panel1->Controls->Add(this->tbx_ExistName);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(300, 120);
			this->panel1->TabIndex = 3;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(3, 3);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(258, 24);
			this->label5->TabIndex = 3;
			this->label5->Text = L"Load Existing Neural Network";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(52, 38);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(96, 13);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Existing NN Name:";
			// 
			// btn_Load
			// 
			this->btn_Load->Location = System::Drawing::Point(121, 87);
			this->btn_Load->Margin = System::Windows::Forms::Padding(2);
			this->btn_Load->Name = L"btn_Load";
			this->btn_Load->Size = System::Drawing::Size(50, 19);
			this->btn_Load->TabIndex = 1;
			this->btn_Load->Text = L"Load";
			this->btn_Load->UseVisualStyleBackColor = true;
			this->btn_Load->Visible = false;
			this->btn_Load->Click += gcnew System::EventHandler(this, &frm_main::btn_Load_Click);
			// 
			// tbx_ExistName
			// 
			this->tbx_ExistName->Location = System::Drawing::Point(52, 53);
			this->tbx_ExistName->Margin = System::Windows::Forms::Padding(2);
			this->tbx_ExistName->Name = L"tbx_ExistName";
			this->tbx_ExistName->Size = System::Drawing::Size(201, 20);
			this->tbx_ExistName->TabIndex = 0;
			this->tbx_ExistName->TextChanged += gcnew System::EventHandler(this, &frm_main::tbx_ExistName_TextChanged);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->panel2->Controls->Add(this->lbl_Operations2);
			this->panel2->Controls->Add(this->cbx_TrainingValue);
			this->panel2->Controls->Add(this->lbl_Operations1);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Controls->Add(this->cbx_ProjectType);
			this->panel2->Location = System::Drawing::Point(12, 488);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(300, 181);
			this->panel2->TabIndex = 4;
			// 
			// lbl_Operations2
			// 
			this->lbl_Operations2->AutoSize = true;
			this->lbl_Operations2->Location = System::Drawing::Point(52, 101);
			this->lbl_Operations2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Operations2->Name = L"lbl_Operations2";
			this->lbl_Operations2->Size = System::Drawing::Size(109, 13);
			this->lbl_Operations2->TabIndex = 4;
			this->lbl_Operations2->Text = L"Select Value to Train:";
			this->lbl_Operations2->Visible = false;
			// 
			// cbx_TrainingValue
			// 
			this->cbx_TrainingValue->FormattingEnabled = true;
			this->cbx_TrainingValue->Location = System::Drawing::Point(52, 117);
			this->cbx_TrainingValue->Name = L"cbx_TrainingValue";
			this->cbx_TrainingValue->Size = System::Drawing::Size(201, 21);
			this->cbx_TrainingValue->TabIndex = 6;
			this->cbx_TrainingValue->Text = L"Select Character";
			this->cbx_TrainingValue->Visible = false;
			this->cbx_TrainingValue->Click += gcnew System::EventHandler(this, &frm_main::cbx_TrainingValue_Click);
			// 
			// lbl_Operations1
			// 
			this->lbl_Operations1->AutoSize = true;
			this->lbl_Operations1->Location = System::Drawing::Point(52, 49);
			this->lbl_Operations1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Operations1->Name = L"lbl_Operations1";
			this->lbl_Operations1->Size = System::Drawing::Size(83, 13);
			this->lbl_Operations1->TabIndex = 2;
			this->lbl_Operations1->Text = L"Operating Type:";
			this->lbl_Operations1->Visible = false;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(3, 3);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(102, 24);
			this->label8->TabIndex = 1;
			this->label8->Text = L"Operations";
			// 
			// lbl_Status
			// 
			this->lbl_Status->AutoSize = true;
			this->lbl_Status->BackColor = System::Drawing::Color::Transparent;
			this->lbl_Status->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_Status->ForeColor = System::Drawing::Color::Red;
			this->lbl_Status->Location = System::Drawing::Point(331, 12);
			this->lbl_Status->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lbl_Status->Name = L"lbl_Status";
			this->lbl_Status->Size = System::Drawing::Size(216, 24);
			this->lbl_Status->TabIndex = 5;
			this->lbl_Status->Text = L"Awaiting Neural Network";
			// 
			// frm_main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1264, 681);
			this->Controls->Add(this->lbl_Status);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->pnl_GameCanvas);
			this->Controls->Add(this->pnl_StatInfo);
			this->Controls->Add(this->pnl_StartOptions);
			this->Controls->Add(this->btn_ClearPanel);
			this->DoubleBuffered = true;
			this->Name = L"frm_main";
			this->Text = L"RTP Learning";
			this->pnl_StartOptions->ResumeLayout(false);
			this->pnl_StartOptions->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_MomentumFactor))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_LearningRate))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->nud_HiddenLayers))->EndInit();
			this->pnl_StatInfo->ResumeLayout(false);
			this->pnl_StatInfo->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	void SetCreateVisibility(bool _value);
	void UpdateStatus(Status status);
	void UpdateResults(int output);
	private: System::Void pnl_GameCanvas_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
	private: System::Void pnl_GameCanvas_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void pnl_GameCanvas_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void pnl_GameCanvas_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e);
	private: System::Void btn_ClearPanel_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbx_Quality_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbx_ProjectType_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void nud_HiddenLayers_ValueChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbx_Output_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tbx_NewName_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void tbx_ExistName_TextChanged(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn_Load_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void btn_Create_Click(System::Object^  sender, System::EventArgs^  e);
	private: System::Void cbx_TrainingValue_Click(System::Object^  sender, System::EventArgs^  e);
};
}

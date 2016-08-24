#pragma once
#include "calculator.h"
#include "HelpForm.h"
#include <msclr\marshal_cppstd.h>

Calculator calculator;

namespace calculator_windows {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// MyForm 摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  帮助ToolStripMenuItem;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Button^  button_sin;
	private: System::Windows::Forms::Button^  button_divide;
	private: System::Windows::Forms::Button^  button_multiply;
	private: System::Windows::Forms::Button^  button_6;
	private: System::Windows::Forms::Button^  button_5;
	private: System::Windows::Forms::Button^  button_0;
	private: System::Windows::Forms::Button^  button_sqrt;
	private: System::Windows::Forms::Button^  button_root;
	private: System::Windows::Forms::Button^  button_power;
	private: System::Windows::Forms::Button^  button_rightbracket;
	private: System::Windows::Forms::Button^  button_leftbracket;
	private: System::Windows::Forms::Button^  button_9;
	private: System::Windows::Forms::Button^  button_8;
	private: System::Windows::Forms::Button^  button_1;
	private: System::Windows::Forms::Button^  button_ln;
	private: System::Windows::Forms::Button^  button_log;
	private: System::Windows::Forms::Button^  button_factorial;
	private: System::Windows::Forms::Button^  button_equal;
	private: System::Windows::Forms::Button^  button_mod;
	private: System::Windows::Forms::Button^  button_2;
	private: System::Windows::Forms::Button^  button_4;
	private: System::Windows::Forms::Button^  button_atan;
	private: System::Windows::Forms::Button^  button_acos;
	private: System::Windows::Forms::Button^  button_asin;
	private: System::Windows::Forms::Button^  button_minus;
	private: System::Windows::Forms::Button^  button_plus;
	private: System::Windows::Forms::Button^  button_3;
	private: System::Windows::Forms::Button^  button_point;
	private: System::Windows::Forms::Button^  button_7;
	private: System::Windows::Forms::Button^  button_tan;
	private: System::Windows::Forms::Button^  button_cos;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  radioButton_g;
	private: System::Windows::Forms::RadioButton^  radioButton_r;
	private: System::Windows::Forms::RadioButton^  radioButton_d;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button_allclear;
	private: System::Windows::Forms::Button^  button_backspace;
	private: System::Windows::Forms::Button^  button_pi;
	private: System::Windows::Forms::Button^  button_e;
	private: System::Windows::Forms::Button^  button_Ans;

	protected:

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要修改
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->帮助ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button_pi = (gcnew System::Windows::Forms::Button());
			this->button_e = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button_divide = (gcnew System::Windows::Forms::Button());
			this->button_multiply = (gcnew System::Windows::Forms::Button());
			this->button_6 = (gcnew System::Windows::Forms::Button());
			this->button_5 = (gcnew System::Windows::Forms::Button());
			this->button_rightbracket = (gcnew System::Windows::Forms::Button());
			this->button_leftbracket = (gcnew System::Windows::Forms::Button());
			this->button_9 = (gcnew System::Windows::Forms::Button());
			this->button_8 = (gcnew System::Windows::Forms::Button());
			this->button_power = (gcnew System::Windows::Forms::Button());
			this->button_factorial = (gcnew System::Windows::Forms::Button());
			this->button_asin = (gcnew System::Windows::Forms::Button());
			this->button_sin = (gcnew System::Windows::Forms::Button());
			this->button_root = (gcnew System::Windows::Forms::Button());
			this->button_log = (gcnew System::Windows::Forms::Button());
			this->button_acos = (gcnew System::Windows::Forms::Button());
			this->button_cos = (gcnew System::Windows::Forms::Button());
			this->button_sqrt = (gcnew System::Windows::Forms::Button());
			this->button_ln = (gcnew System::Windows::Forms::Button());
			this->button_atan = (gcnew System::Windows::Forms::Button());
			this->button_tan = (gcnew System::Windows::Forms::Button());
			this->button_0 = (gcnew System::Windows::Forms::Button());
			this->button_1 = (gcnew System::Windows::Forms::Button());
			this->button_4 = (gcnew System::Windows::Forms::Button());
			this->button_7 = (gcnew System::Windows::Forms::Button());
			this->button_2 = (gcnew System::Windows::Forms::Button());
			this->button_3 = (gcnew System::Windows::Forms::Button());
			this->button_plus = (gcnew System::Windows::Forms::Button());
			this->button_mod = (gcnew System::Windows::Forms::Button());
			this->button_minus = (gcnew System::Windows::Forms::Button());
			this->button_equal = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton_g = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_r = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_d = (gcnew System::Windows::Forms::RadioButton());
			this->button_point = (gcnew System::Windows::Forms::Button());
			this->button_backspace = (gcnew System::Windows::Forms::Button());
			this->button_allclear = (gcnew System::Windows::Forms::Button());
			this->button_Ans = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->帮助ToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1022, 25);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MyForm::menuStrip1_ItemClicked);
			// 
			// 帮助ToolStripMenuItem
			// 
			this->帮助ToolStripMenuItem->Name = L"帮助ToolStripMenuItem";
			this->帮助ToolStripMenuItem->Size = System::Drawing::Size(68, 21);
			this->帮助ToolStripMenuItem->Text = L"使用说明";
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->ColumnCount = 8;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.5F)));
			this->tableLayoutPanel1->Controls->Add(this->button_pi, 5, 1);
			this->tableLayoutPanel1->Controls->Add(this->button_e, 4, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->button_divide, 7, 3);
			this->tableLayoutPanel1->Controls->Add(this->button_multiply, 6, 3);
			this->tableLayoutPanel1->Controls->Add(this->button_6, 5, 3);
			this->tableLayoutPanel1->Controls->Add(this->button_5, 4, 3);
			this->tableLayoutPanel1->Controls->Add(this->button_rightbracket, 7, 2);
			this->tableLayoutPanel1->Controls->Add(this->button_leftbracket, 6, 2);
			this->tableLayoutPanel1->Controls->Add(this->button_9, 5, 2);
			this->tableLayoutPanel1->Controls->Add(this->button_8, 4, 2);
			this->tableLayoutPanel1->Controls->Add(this->button_power, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->button_factorial, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->button_asin, 0, 3);
			this->tableLayoutPanel1->Controls->Add(this->button_sin, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->button_root, 1, 5);
			this->tableLayoutPanel1->Controls->Add(this->button_log, 1, 4);
			this->tableLayoutPanel1->Controls->Add(this->button_acos, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->button_cos, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->button_sqrt, 2, 5);
			this->tableLayoutPanel1->Controls->Add(this->button_ln, 2, 4);
			this->tableLayoutPanel1->Controls->Add(this->button_atan, 2, 3);
			this->tableLayoutPanel1->Controls->Add(this->button_tan, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->button_0, 3, 5);
			this->tableLayoutPanel1->Controls->Add(this->button_1, 3, 4);
			this->tableLayoutPanel1->Controls->Add(this->button_4, 3, 3);
			this->tableLayoutPanel1->Controls->Add(this->button_7, 3, 2);
			this->tableLayoutPanel1->Controls->Add(this->button_2, 4, 4);
			this->tableLayoutPanel1->Controls->Add(this->button_3, 5, 4);
			this->tableLayoutPanel1->Controls->Add(this->button_plus, 6, 4);
			this->tableLayoutPanel1->Controls->Add(this->button_mod, 6, 5);
			this->tableLayoutPanel1->Controls->Add(this->button_minus, 7, 4);
			this->tableLayoutPanel1->Controls->Add(this->button_equal, 7, 5);
			this->tableLayoutPanel1->Controls->Add(this->groupBox1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->button_point, 5, 5);
			this->tableLayoutPanel1->Controls->Add(this->button_backspace, 7, 1);
			this->tableLayoutPanel1->Controls->Add(this->button_allclear, 6, 1);
			this->tableLayoutPanel1->Controls->Add(this->button_Ans, 3, 1);
			this->tableLayoutPanel1->Location = System::Drawing::Point(12, 30);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 6;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 16.66667F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 22)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(998, 405);
			this->tableLayoutPanel1->TabIndex = 4;
			// 
			// button_pi
			// 
			this->button_pi->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_pi->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_pi->Location = System::Drawing::Point(623, 70);
			this->button_pi->Name = L"button_pi";
			this->button_pi->Size = System::Drawing::Size(118, 61);
			this->button_pi->TabIndex = 2;
			this->button_pi->TabStop = false;
			this->button_pi->Text = L"pi";
			this->button_pi->UseVisualStyleBackColor = true;
			this->button_pi->Click += gcnew System::EventHandler(this, &MyForm::button_pi_Click);
			// 
			// button_e
			// 
			this->button_e->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_e->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_e->Location = System::Drawing::Point(499, 70);
			this->button_e->Name = L"button_e";
			this->button_e->Size = System::Drawing::Size(118, 61);
			this->button_e->TabIndex = 1;
			this->button_e->TabStop = false;
			this->button_e->Text = L"e";
			this->button_e->UseVisualStyleBackColor = true;
			this->button_e->Click += gcnew System::EventHandler(this, &MyForm::button_e_Click);
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel3->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel1->SetColumnSpan(this->tableLayoutPanel3, 8);
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->textBox2, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->textBox1, 0, 0);
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 2;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(992, 61);
			this->tableLayoutPanel3->TabIndex = 7;
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->textBox2->Location = System::Drawing::Point(3, 33);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(986, 22);
			this->textBox2->TabIndex = 1;
			this->textBox2->TabStop = false;
			this->textBox2->Text = L"0";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->textBox1->Location = System::Drawing::Point(3, 3);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(986, 22);
			this->textBox1->TabIndex = 0;
			this->textBox1->TabStop = false;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// button_divide
			// 
			this->button_divide->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_divide->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_divide->Location = System::Drawing::Point(871, 204);
			this->button_divide->Name = L"button_divide";
			this->button_divide->Size = System::Drawing::Size(124, 61);
			this->button_divide->TabIndex = 20;
			this->button_divide->TabStop = false;
			this->button_divide->Text = L"/";
			this->button_divide->UseVisualStyleBackColor = true;
			this->button_divide->Click += gcnew System::EventHandler(this, &MyForm::button_divide_Click);
			// 
			// button_multiply
			// 
			this->button_multiply->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_multiply->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_multiply->Location = System::Drawing::Point(747, 204);
			this->button_multiply->Name = L"button_multiply";
			this->button_multiply->Size = System::Drawing::Size(118, 61);
			this->button_multiply->TabIndex = 19;
			this->button_multiply->TabStop = false;
			this->button_multiply->Text = L"*";
			this->button_multiply->UseVisualStyleBackColor = true;
			this->button_multiply->Click += gcnew System::EventHandler(this, &MyForm::button_multiply_Click);
			// 
			// button_6
			// 
			this->button_6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_6->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_6->Location = System::Drawing::Point(623, 204);
			this->button_6->Name = L"button_6";
			this->button_6->Size = System::Drawing::Size(118, 61);
			this->button_6->TabIndex = 18;
			this->button_6->TabStop = false;
			this->button_6->Text = L"6";
			this->button_6->UseVisualStyleBackColor = true;
			this->button_6->Click += gcnew System::EventHandler(this, &MyForm::button_6_Click);
			// 
			// button_5
			// 
			this->button_5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_5->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_5->Location = System::Drawing::Point(499, 204);
			this->button_5->Name = L"button_5";
			this->button_5->Size = System::Drawing::Size(118, 61);
			this->button_5->TabIndex = 17;
			this->button_5->TabStop = false;
			this->button_5->Text = L"5";
			this->button_5->UseVisualStyleBackColor = true;
			this->button_5->Click += gcnew System::EventHandler(this, &MyForm::button_5_Click);
			// 
			// button_rightbracket
			// 
			this->button_rightbracket->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_rightbracket->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_rightbracket->Location = System::Drawing::Point(871, 137);
			this->button_rightbracket->Name = L"button_rightbracket";
			this->button_rightbracket->Size = System::Drawing::Size(124, 61);
			this->button_rightbracket->TabIndex = 12;
			this->button_rightbracket->TabStop = false;
			this->button_rightbracket->Text = L")";
			this->button_rightbracket->UseVisualStyleBackColor = true;
			this->button_rightbracket->Click += gcnew System::EventHandler(this, &MyForm::button_rightbracket_Click);
			// 
			// button_leftbracket
			// 
			this->button_leftbracket->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_leftbracket->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_leftbracket->Location = System::Drawing::Point(747, 137);
			this->button_leftbracket->Name = L"button_leftbracket";
			this->button_leftbracket->Size = System::Drawing::Size(118, 61);
			this->button_leftbracket->TabIndex = 11;
			this->button_leftbracket->TabStop = false;
			this->button_leftbracket->Text = L"(";
			this->button_leftbracket->UseVisualStyleBackColor = true;
			this->button_leftbracket->Click += gcnew System::EventHandler(this, &MyForm::button_leftbracket_Click);
			// 
			// button_9
			// 
			this->button_9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_9->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_9->Location = System::Drawing::Point(623, 137);
			this->button_9->Name = L"button_9";
			this->button_9->Size = System::Drawing::Size(118, 61);
			this->button_9->TabIndex = 10;
			this->button_9->TabStop = false;
			this->button_9->Text = L"9";
			this->button_9->UseVisualStyleBackColor = true;
			this->button_9->Click += gcnew System::EventHandler(this, &MyForm::button_9_Click);
			// 
			// button_8
			// 
			this->button_8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_8->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_8->Location = System::Drawing::Point(499, 137);
			this->button_8->Name = L"button_8";
			this->button_8->Size = System::Drawing::Size(118, 61);
			this->button_8->TabIndex = 9;
			this->button_8->TabStop = false;
			this->button_8->Text = L"8";
			this->button_8->UseVisualStyleBackColor = true;
			this->button_8->Click += gcnew System::EventHandler(this, &MyForm::button_8_Click);
			// 
			// button_power
			// 
			this->button_power->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_power->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_power->Location = System::Drawing::Point(3, 338);
			this->button_power->Name = L"button_power";
			this->button_power->Size = System::Drawing::Size(118, 64);
			this->button_power->TabIndex = 29;
			this->button_power->TabStop = false;
			this->button_power->Text = L"^";
			this->button_power->UseVisualStyleBackColor = true;
			this->button_power->Click += gcnew System::EventHandler(this, &MyForm::button_power_Click);
			// 
			// button_factorial
			// 
			this->button_factorial->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_factorial->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_factorial->Location = System::Drawing::Point(3, 271);
			this->button_factorial->Name = L"button_factorial";
			this->button_factorial->Size = System::Drawing::Size(118, 61);
			this->button_factorial->TabIndex = 21;
			this->button_factorial->TabStop = false;
			this->button_factorial->Text = L"!";
			this->button_factorial->UseVisualStyleBackColor = true;
			this->button_factorial->Click += gcnew System::EventHandler(this, &MyForm::button_factorial_Click);
			// 
			// button_asin
			// 
			this->button_asin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_asin->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_asin->Location = System::Drawing::Point(3, 204);
			this->button_asin->Name = L"button_asin";
			this->button_asin->Size = System::Drawing::Size(118, 61);
			this->button_asin->TabIndex = 13;
			this->button_asin->TabStop = false;
			this->button_asin->Text = L"arcsin";
			this->button_asin->UseVisualStyleBackColor = true;
			this->button_asin->Click += gcnew System::EventHandler(this, &MyForm::button_asin_Click);
			// 
			// button_sin
			// 
			this->button_sin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_sin->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_sin->Location = System::Drawing::Point(3, 137);
			this->button_sin->Name = L"button_sin";
			this->button_sin->Size = System::Drawing::Size(118, 61);
			this->button_sin->TabIndex = 5;
			this->button_sin->TabStop = false;
			this->button_sin->Text = L"sin";
			this->button_sin->UseVisualStyleBackColor = true;
			this->button_sin->Click += gcnew System::EventHandler(this, &MyForm::button_sin_Click);
			// 
			// button_root
			// 
			this->button_root->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_root->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_root->Location = System::Drawing::Point(127, 338);
			this->button_root->Name = L"button_root";
			this->button_root->Size = System::Drawing::Size(118, 64);
			this->button_root->TabIndex = 30;
			this->button_root->TabStop = false;
			this->button_root->Text = L"root";
			this->button_root->UseVisualStyleBackColor = true;
			this->button_root->Click += gcnew System::EventHandler(this, &MyForm::button_root_Click);
			// 
			// button_log
			// 
			this->button_log->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_log->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_log->Location = System::Drawing::Point(127, 271);
			this->button_log->Name = L"button_log";
			this->button_log->Size = System::Drawing::Size(118, 61);
			this->button_log->TabIndex = 22;
			this->button_log->TabStop = false;
			this->button_log->Text = L"log";
			this->button_log->UseVisualStyleBackColor = true;
			this->button_log->Click += gcnew System::EventHandler(this, &MyForm::button_log_Click);
			// 
			// button_acos
			// 
			this->button_acos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_acos->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_acos->Location = System::Drawing::Point(127, 204);
			this->button_acos->Name = L"button_acos";
			this->button_acos->Size = System::Drawing::Size(118, 61);
			this->button_acos->TabIndex = 14;
			this->button_acos->TabStop = false;
			this->button_acos->Text = L"arccos";
			this->button_acos->UseVisualStyleBackColor = true;
			this->button_acos->Click += gcnew System::EventHandler(this, &MyForm::button_acos_Click);
			// 
			// button_cos
			// 
			this->button_cos->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_cos->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_cos->Location = System::Drawing::Point(127, 137);
			this->button_cos->Name = L"button_cos";
			this->button_cos->Size = System::Drawing::Size(118, 61);
			this->button_cos->TabIndex = 6;
			this->button_cos->TabStop = false;
			this->button_cos->Text = L"cos";
			this->button_cos->UseVisualStyleBackColor = true;
			this->button_cos->Click += gcnew System::EventHandler(this, &MyForm::button_cos_Click);
			// 
			// button_sqrt
			// 
			this->button_sqrt->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_sqrt->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_sqrt->Location = System::Drawing::Point(251, 338);
			this->button_sqrt->Name = L"button_sqrt";
			this->button_sqrt->Size = System::Drawing::Size(118, 64);
			this->button_sqrt->TabIndex = 31;
			this->button_sqrt->TabStop = false;
			this->button_sqrt->Text = L"sqrt";
			this->button_sqrt->UseVisualStyleBackColor = true;
			this->button_sqrt->Click += gcnew System::EventHandler(this, &MyForm::button_sqrt_Click);
			// 
			// button_ln
			// 
			this->button_ln->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_ln->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_ln->Location = System::Drawing::Point(251, 271);
			this->button_ln->Name = L"button_ln";
			this->button_ln->Size = System::Drawing::Size(118, 61);
			this->button_ln->TabIndex = 23;
			this->button_ln->TabStop = false;
			this->button_ln->Text = L"ln";
			this->button_ln->UseVisualStyleBackColor = true;
			this->button_ln->Click += gcnew System::EventHandler(this, &MyForm::button_ln_Click);
			// 
			// button_atan
			// 
			this->button_atan->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_atan->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_atan->Location = System::Drawing::Point(251, 204);
			this->button_atan->Name = L"button_atan";
			this->button_atan->Size = System::Drawing::Size(118, 61);
			this->button_atan->TabIndex = 15;
			this->button_atan->TabStop = false;
			this->button_atan->Text = L"tan";
			this->button_atan->UseVisualStyleBackColor = true;
			this->button_atan->Click += gcnew System::EventHandler(this, &MyForm::button_atan_Click);
			// 
			// button_tan
			// 
			this->button_tan->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_tan->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_tan->Location = System::Drawing::Point(251, 137);
			this->button_tan->Name = L"button_tan";
			this->button_tan->Size = System::Drawing::Size(118, 61);
			this->button_tan->TabIndex = 7;
			this->button_tan->TabStop = false;
			this->button_tan->Text = L"tan";
			this->button_tan->UseVisualStyleBackColor = true;
			this->button_tan->Click += gcnew System::EventHandler(this, &MyForm::button_tan_Click);
			// 
			// button_0
			// 
			this->button_0->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->SetColumnSpan(this->button_0, 2);
			this->button_0->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_0->Location = System::Drawing::Point(375, 338);
			this->button_0->Name = L"button_0";
			this->button_0->Size = System::Drawing::Size(242, 64);
			this->button_0->TabIndex = 32;
			this->button_0->TabStop = false;
			this->button_0->Text = L"0";
			this->button_0->UseVisualStyleBackColor = true;
			this->button_0->Click += gcnew System::EventHandler(this, &MyForm::button_0_Click);
			// 
			// button_1
			// 
			this->button_1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_1->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_1->Location = System::Drawing::Point(375, 271);
			this->button_1->Name = L"button_1";
			this->button_1->Size = System::Drawing::Size(118, 61);
			this->button_1->TabIndex = 24;
			this->button_1->TabStop = false;
			this->button_1->Text = L"1";
			this->button_1->UseVisualStyleBackColor = true;
			this->button_1->Click += gcnew System::EventHandler(this, &MyForm::button_1_Click);
			// 
			// button_4
			// 
			this->button_4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_4->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_4->Location = System::Drawing::Point(375, 204);
			this->button_4->Name = L"button_4";
			this->button_4->Size = System::Drawing::Size(118, 61);
			this->button_4->TabIndex = 16;
			this->button_4->TabStop = false;
			this->button_4->Text = L"4";
			this->button_4->UseVisualStyleBackColor = true;
			this->button_4->Click += gcnew System::EventHandler(this, &MyForm::button_4_Click);
			// 
			// button_7
			// 
			this->button_7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_7->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_7->Location = System::Drawing::Point(375, 137);
			this->button_7->Name = L"button_7";
			this->button_7->Size = System::Drawing::Size(118, 61);
			this->button_7->TabIndex = 8;
			this->button_7->TabStop = false;
			this->button_7->Text = L"7";
			this->button_7->UseVisualStyleBackColor = true;
			this->button_7->Click += gcnew System::EventHandler(this, &MyForm::button_7_Click);
			// 
			// button_2
			// 
			this->button_2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_2->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_2->Location = System::Drawing::Point(499, 271);
			this->button_2->Name = L"button_2";
			this->button_2->Size = System::Drawing::Size(118, 61);
			this->button_2->TabIndex = 25;
			this->button_2->TabStop = false;
			this->button_2->Text = L"2";
			this->button_2->UseVisualStyleBackColor = true;
			this->button_2->Click += gcnew System::EventHandler(this, &MyForm::button_2_Click);
			// 
			// button_3
			// 
			this->button_3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_3->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_3->Location = System::Drawing::Point(623, 271);
			this->button_3->Name = L"button_3";
			this->button_3->Size = System::Drawing::Size(118, 61);
			this->button_3->TabIndex = 26;
			this->button_3->TabStop = false;
			this->button_3->Text = L"3";
			this->button_3->UseVisualStyleBackColor = true;
			this->button_3->Click += gcnew System::EventHandler(this, &MyForm::button_3_Click);
			// 
			// button_plus
			// 
			this->button_plus->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_plus->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_plus->Location = System::Drawing::Point(747, 271);
			this->button_plus->Name = L"button_plus";
			this->button_plus->Size = System::Drawing::Size(118, 61);
			this->button_plus->TabIndex = 27;
			this->button_plus->TabStop = false;
			this->button_plus->Text = L"+";
			this->button_plus->UseVisualStyleBackColor = true;
			this->button_plus->Click += gcnew System::EventHandler(this, &MyForm::button_plus_Click);
			// 
			// button_mod
			// 
			this->button_mod->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_mod->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_mod->Location = System::Drawing::Point(747, 338);
			this->button_mod->Name = L"button_mod";
			this->button_mod->Size = System::Drawing::Size(118, 64);
			this->button_mod->TabIndex = 34;
			this->button_mod->TabStop = false;
			this->button_mod->Text = L"%";
			this->button_mod->UseVisualStyleBackColor = true;
			this->button_mod->Click += gcnew System::EventHandler(this, &MyForm::button_mod_Click);
			// 
			// button_minus
			// 
			this->button_minus->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_minus->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_minus->Location = System::Drawing::Point(871, 271);
			this->button_minus->Name = L"button_minus";
			this->button_minus->Size = System::Drawing::Size(124, 61);
			this->button_minus->TabIndex = 28;
			this->button_minus->TabStop = false;
			this->button_minus->Text = L"-";
			this->button_minus->UseVisualStyleBackColor = true;
			this->button_minus->Click += gcnew System::EventHandler(this, &MyForm::button_minus_Click);
			// 
			// button_equal
			// 
			this->button_equal->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_equal->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_equal->Location = System::Drawing::Point(871, 338);
			this->button_equal->Name = L"button_equal";
			this->button_equal->Size = System::Drawing::Size(124, 64);
			this->button_equal->TabIndex = 35;
			this->button_equal->TabStop = false;
			this->button_equal->Text = L"=";
			this->button_equal->UseVisualStyleBackColor = true;
			this->button_equal->Click += gcnew System::EventHandler(this, &MyForm::button_equal_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tableLayoutPanel1->SetColumnSpan(this->groupBox1, 3);
			this->groupBox1->Controls->Add(this->radioButton_g);
			this->groupBox1->Controls->Add(this->radioButton_r);
			this->groupBox1->Controls->Add(this->radioButton_d);
			this->groupBox1->Location = System::Drawing::Point(3, 70);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(366, 61);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			// 
			// radioButton_g
			// 
			this->radioButton_g->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->radioButton_g->AutoSize = true;
			this->radioButton_g->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->radioButton_g->Location = System::Drawing::Point(248, 22);
			this->radioButton_g->Name = L"radioButton_g";
			this->radioButton_g->Size = System::Drawing::Size(65, 23);
			this->radioButton_g->TabIndex = 2;
			this->radioButton_g->Text = L"梯度";
			this->radioButton_g->UseVisualStyleBackColor = true;
			this->radioButton_g->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton_g_CheckedChanged);
			// 
			// radioButton_r
			// 
			this->radioButton_r->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->radioButton_r->AutoSize = true;
			this->radioButton_r->Checked = true;
			this->radioButton_r->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->radioButton_r->Location = System::Drawing::Point(124, 22);
			this->radioButton_r->Name = L"radioButton_r";
			this->radioButton_r->Size = System::Drawing::Size(65, 23);
			this->radioButton_r->TabIndex = 1;
			this->radioButton_r->TabStop = true;
			this->radioButton_r->Text = L"弧度";
			this->radioButton_r->UseVisualStyleBackColor = true;
			this->radioButton_r->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton_r_CheckedChanged);
			// 
			// radioButton_d
			// 
			this->radioButton_d->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->radioButton_d->AutoSize = true;
			this->radioButton_d->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->radioButton_d->Location = System::Drawing::Point(0, 22);
			this->radioButton_d->Name = L"radioButton_d";
			this->radioButton_d->Size = System::Drawing::Size(65, 23);
			this->radioButton_d->TabIndex = 0;
			this->radioButton_d->Text = L"角度";
			this->radioButton_d->UseVisualStyleBackColor = true;
			this->radioButton_d->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton_d_CheckedChanged);
			// 
			// button_point
			// 
			this->button_point->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_point->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_point->Location = System::Drawing::Point(623, 338);
			this->button_point->Name = L"button_point";
			this->button_point->Size = System::Drawing::Size(118, 64);
			this->button_point->TabIndex = 33;
			this->button_point->TabStop = false;
			this->button_point->Text = L".";
			this->button_point->UseVisualStyleBackColor = true;
			this->button_point->Click += gcnew System::EventHandler(this, &MyForm::button_point_Click);
			// 
			// button_backspace
			// 
			this->button_backspace->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_backspace->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_backspace->Location = System::Drawing::Point(871, 70);
			this->button_backspace->Name = L"button_backspace";
			this->button_backspace->Size = System::Drawing::Size(124, 61);
			this->button_backspace->TabIndex = 4;
			this->button_backspace->TabStop = false;
			this->button_backspace->Text = L"←";
			this->button_backspace->UseVisualStyleBackColor = true;
			this->button_backspace->Click += gcnew System::EventHandler(this, &MyForm::button_backspace_Click);
			// 
			// button_allclear
			// 
			this->button_allclear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_allclear->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_allclear->Location = System::Drawing::Point(747, 70);
			this->button_allclear->Name = L"button_allclear";
			this->button_allclear->Size = System::Drawing::Size(118, 61);
			this->button_allclear->TabIndex = 3;
			this->button_allclear->TabStop = false;
			this->button_allclear->Text = L"AC";
			this->button_allclear->UseVisualStyleBackColor = true;
			this->button_allclear->Click += gcnew System::EventHandler(this, &MyForm::button_allclear_Click);
			// 
			// button_Ans
			// 
			this->button_Ans->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button_Ans->Font = (gcnew System::Drawing::Font(L"宋体", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(134)));
			this->button_Ans->Location = System::Drawing::Point(375, 70);
			this->button_Ans->Name = L"button_Ans";
			this->button_Ans->Size = System::Drawing::Size(118, 61);
			this->button_Ans->TabIndex = 0;
			this->button_Ans->TabStop = false;
			this->button_Ans->Text = L"Ans";
			this->button_Ans->UseVisualStyleBackColor = true;
			this->button_Ans->Click += gcnew System::EventHandler(this, &MyForm::button_Ans_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1022, 443);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"科学型计算器";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: System::Void button_sin_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "sin ";
}
private: System::Void button_cos_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "cos ";
}
private: System::Void button_tan_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "tan ";
}
private: System::Void button_asin_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "arcsin ";
}
private: System::Void button_acos_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "arccos ";
}
private: System::Void button_atan_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "arctan ";
}
private: System::Void button_factorial_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "!";
}
private: System::Void button_log_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "log ";
}
private: System::Void button_ln_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "ln ";
}
private: System::Void button_power_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "^";
}
private: System::Void button_root_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "root ";
}
private: System::Void button_sqrt_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "sqrt ";
}
private: System::Void button_Ans_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "Ans ";
}
private: System::Void button_e_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "e";
}
private: System::Void button_pi_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "pi ";
}
private: System::Void button_7_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "7";
}
private: System::Void button_8_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "8";
}
private: System::Void button_9_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "9";
}
private: System::Void button_4_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "4";
}
private: System::Void button_5_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "5";
}
private: System::Void button_6_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "6";
}
private: System::Void button_1_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "1";
}
private: System::Void button_2_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "2";
}
private: System::Void button_3_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "3";
}
private: System::Void button_0_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "0";
}
private: System::Void button_point_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += ".";
}
private: System::Void button_allclear_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text = "";
	textBox2->Text = "0";
}
private: System::Void button_backspace_Click(System::Object^  sender, System::EventArgs^  e) {
	if (textBox1->Text != "")
	{
		textBox1->Text = textBox1->Text->Remove(textBox1->Text->Length - 1);
	}
}
private: System::Void button_leftbracket_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "(";
}
private: System::Void button_rightbracket_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += ")";
}
private: System::Void button_multiply_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "*";
}
private: System::Void button_divide_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "/";
}
private: System::Void button_plus_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "+";
}
private: System::Void button_minus_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "-";
}
private: System::Void button_mod_Click(System::Object^  sender, System::EventArgs^  e) {
	textBox1->Text += "%";
}
private: System::Void radioButton_d_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	calculator.setDegree();
}
private: System::Void radioButton_r_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	calculator.setRadian();
}
private: System::Void radioButton_g_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	calculator.setGradient();
}
private: System::Void menuStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
	HelpForm^ helpform = gcnew HelpForm();
	helpform->Show();
}
private: System::Void button_equal_Click(System::Object^  sender, System::EventArgs^  e) {
	if (textBox1->Text != "")
	{
		textBox2->Text = marshal_as<String^>(
			calculator.calculate_exp(marshal_as<std::string>(textBox1->Text))
			);
	}
}
};
}

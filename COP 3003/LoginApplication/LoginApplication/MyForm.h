#pragma once
#include "User.h"

namespace LoginApplication
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			dashboardPanel->Hide();
			registerPanel->Hide();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ loginPanel;
	protected:

	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ usernameTxtBox;

	private: System::Windows::Forms::Button^ loginBtn;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ passwordTxtBox;
	private: System::Windows::Forms::Button^ registerBtnLoginPage;


	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Panel^ dashboardPanel;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ userNameDashboard;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Panel^ registerPanel;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::LinkLabel^ loginLink;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ registerBTN;
	private: System::Windows::Forms::TextBox^ registerPassword;


	private: System::Windows::Forms::TextBox^ registerUsername;



	private: System::Windows::Forms::TextBox^ registerEmail;

	private: System::Windows::Forms::TextBox^ registerLastName;

	private: System::Windows::Forms::TextBox^ registerFirstName;

	private: System::Windows::Forms::Label^ label4;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->loginPanel = (gcnew System::Windows::Forms::Panel());
			this->dashboardPanel = (gcnew System::Windows::Forms::Panel());
			this->registerPanel = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->loginLink = (gcnew System::Windows::Forms::LinkLabel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->registerBTN = (gcnew System::Windows::Forms::Button());
			this->registerPassword = (gcnew System::Windows::Forms::TextBox());
			this->registerUsername = (gcnew System::Windows::Forms::TextBox());
			this->registerEmail = (gcnew System::Windows::Forms::TextBox());
			this->registerLastName = (gcnew System::Windows::Forms::TextBox());
			this->registerFirstName = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->userNameDashboard = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->registerBtnLoginPage = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->passwordTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->loginBtn = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->usernameTxtBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->loginPanel->SuspendLayout();
			this->dashboardPanel->SuspendLayout();
			this->registerPanel->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// loginPanel
			// 
			this->loginPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"loginPanel.BackgroundImage")));
			this->loginPanel->Controls->Add(this->dashboardPanel);
			this->loginPanel->Controls->Add(this->pictureBox1);
			this->loginPanel->Controls->Add(this->registerBtnLoginPage);
			this->loginPanel->Controls->Add(this->label3);
			this->loginPanel->Controls->Add(this->panel2);
			this->loginPanel->ForeColor = System::Drawing::Color::Transparent;
			this->loginPanel->Location = System::Drawing::Point(0, 0);
			this->loginPanel->Name = L"loginPanel";
			this->loginPanel->Size = System::Drawing::Size(1188, 681);
			this->loginPanel->TabIndex = 0;
			// 
			// dashboardPanel
			// 
			this->dashboardPanel->BackColor = System::Drawing::Color::Transparent;
			this->dashboardPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"dashboardPanel.BackgroundImage")));
			this->dashboardPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->dashboardPanel->Controls->Add(this->registerPanel);
			this->dashboardPanel->Controls->Add(this->button2);
			this->dashboardPanel->Controls->Add(this->pictureBox3);
			this->dashboardPanel->Controls->Add(this->userNameDashboard);
			this->dashboardPanel->Controls->Add(this->pictureBox2);
			this->dashboardPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dashboardPanel->Location = System::Drawing::Point(0, 0);
			this->dashboardPanel->Name = L"dashboardPanel";
			this->dashboardPanel->Size = System::Drawing::Size(1188, 681);
			this->dashboardPanel->TabIndex = 1;
			this->dashboardPanel->Click += gcnew System::EventHandler(this, &MyForm::dashboardPanel_Click);
			// 
			// registerPanel
			// 
			this->registerPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"registerPanel.BackgroundImage")));
			this->registerPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->registerPanel->Controls->Add(this->panel1);
			this->registerPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->registerPanel->Location = System::Drawing::Point(0, 0);
			this->registerPanel->Name = L"registerPanel";
			this->registerPanel->Size = System::Drawing::Size(1188, 681);
			this->registerPanel->TabIndex = 4;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel1->Controls->Add(this->loginLink);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->registerBTN);
			this->panel1->Controls->Add(this->registerPassword);
			this->panel1->Controls->Add(this->registerUsername);
			this->panel1->Controls->Add(this->registerEmail);
			this->panel1->Controls->Add(this->registerLastName);
			this->panel1->Controls->Add(this->registerFirstName);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Location = System::Drawing::Point(369, 51);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(470, 594);
			this->panel1->TabIndex = 0;
			// 
			// loginLink
			// 
			this->loginLink->AutoSize = true;
			this->loginLink->LinkColor = System::Drawing::Color::Black;
			this->loginLink->Location = System::Drawing::Point(238, 543);
			this->loginLink->Name = L"loginLink";
			this->loginLink->Size = System::Drawing::Size(67, 11);
			this->loginLink->TabIndex = 8;
			this->loginLink->TabStop = true;
			this->loginLink->Text = L"Login Here";
			this->loginLink->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::loginLink_LinkClicked);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"IBM Plex Sans", 8.249999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(132, 540);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(100, 14);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Have an account\?";
			// 
			// registerBTN
			// 
			this->registerBTN->BackColor = System::Drawing::Color::Transparent;
			this->registerBTN->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"registerBTN.BackgroundImage")));
			this->registerBTN->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->registerBTN->FlatAppearance->BorderSize = 0;
			this->registerBTN->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->registerBTN->Location = System::Drawing::Point(110, 450);
			this->registerBTN->Name = L"registerBTN";
			this->registerBTN->Size = System::Drawing::Size(217, 71);
			this->registerBTN->TabIndex = 6;
			this->registerBTN->UseVisualStyleBackColor = false;
			this->registerBTN->Click += gcnew System::EventHandler(this, &MyForm::registerBTN_Click);
			// 
			// registerPassword
			// 
			this->registerPassword->Font = (gcnew System::Drawing::Font(L"IBM Plex Sans", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->registerPassword->ForeColor = System::Drawing::Color::Gainsboro;
			this->registerPassword->Location = System::Drawing::Point(74, 377);
			this->registerPassword->Multiline = true;
			this->registerPassword->Name = L"registerPassword";
			this->registerPassword->PasswordChar = '*';
			this->registerPassword->Size = System::Drawing::Size(297, 45);
			this->registerPassword->TabIndex = 5;
			this->registerPassword->Text = L"Enter Password";
			this->registerPassword->UseSystemPasswordChar = true;
			this->registerPassword->Click += gcnew System::EventHandler(this, &MyForm::registerPassword_Click);
			// 
			// registerUsername
			// 
			this->registerUsername->Font = (gcnew System::Drawing::Font(L"IBM Plex Sans", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->registerUsername->ForeColor = System::Drawing::Color::Gainsboro;
			this->registerUsername->Location = System::Drawing::Point(74, 306);
			this->registerUsername->Multiline = true;
			this->registerUsername->Name = L"registerUsername";
			this->registerUsername->PasswordChar = '*';
			this->registerUsername->Size = System::Drawing::Size(297, 45);
			this->registerUsername->TabIndex = 4;
			this->registerUsername->Text = L"Enter Username";
			this->registerUsername->UseSystemPasswordChar = true;
			this->registerUsername->Click += gcnew System::EventHandler(this, &MyForm::registerUsername_Click);
			// 
			// registerEmail
			// 
			this->registerEmail->Font = (gcnew System::Drawing::Font(L"IBM Plex Sans", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->registerEmail->ForeColor = System::Drawing::Color::Gainsboro;
			this->registerEmail->Location = System::Drawing::Point(74, 228);
			this->registerEmail->Multiline = true;
			this->registerEmail->Name = L"registerEmail";
			this->registerEmail->Size = System::Drawing::Size(297, 45);
			this->registerEmail->TabIndex = 3;
			this->registerEmail->Text = L"Enter Email";
			this->registerEmail->Click += gcnew System::EventHandler(this, &MyForm::registerEmail_Click);
			// 
			// registerLastName
			// 
			this->registerLastName->Font = (gcnew System::Drawing::Font(L"IBM Plex Sans", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->registerLastName->ForeColor = System::Drawing::Color::Gainsboro;
			this->registerLastName->Location = System::Drawing::Point(74, 152);
			this->registerLastName->Multiline = true;
			this->registerLastName->Name = L"registerLastName";
			this->registerLastName->Size = System::Drawing::Size(297, 45);
			this->registerLastName->TabIndex = 2;
			this->registerLastName->Text = L"Enter Last Name";
			this->registerLastName->Click += gcnew System::EventHandler(this, &MyForm::registerLastName_Click);
			// 
			// registerFirstName
			// 
			this->registerFirstName->Font = (gcnew System::Drawing::Font(L"IBM Plex Sans", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->registerFirstName->ForeColor = System::Drawing::Color::Gainsboro;
			this->registerFirstName->Location = System::Drawing::Point(74, 84);
			this->registerFirstName->Multiline = true;
			this->registerFirstName->Name = L"registerFirstName";
			this->registerFirstName->Size = System::Drawing::Size(297, 39);
			this->registerFirstName->TabIndex = 1;
			this->registerFirstName->Text = L"Enter First Name";
			this->registerFirstName->Click += gcnew System::EventHandler(this, &MyForm::registerFirstName_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"IBM Plex Sans", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(129, 24);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(186, 32);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Create Account";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Location = System::Drawing::Point(1072, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(83, 79);
			this->button2->TabIndex = 3;
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Location = System::Drawing::Point(515, 95);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(142, 105);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// userNameDashboard
			// 
			this->userNameDashboard->BackColor = System::Drawing::Color::Transparent;
			this->userNameDashboard->Font = (gcnew System::Drawing::Font(L"IBM Plex Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->userNameDashboard->Location = System::Drawing::Point(492, 425);
			this->userNameDashboard->Name = L"userNameDashboard";
			this->userNameDashboard->Size = System::Drawing::Size(195, 20);
			this->userNameDashboard->TabIndex = 1;
			this->userNameDashboard->Text = L"Default User";
			this->userNameDashboard->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox2->Location = System::Drawing::Point(443, 189);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(293, 233);
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(492, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(169, 117);
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// registerBtnLoginPage
			// 
			this->registerBtnLoginPage->BackColor = System::Drawing::Color::Transparent;
			this->registerBtnLoginPage->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->registerBtnLoginPage->Font = (gcnew System::Drawing::Font(L"IBM Plex Sans SemiBold", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->registerBtnLoginPage->ForeColor = System::Drawing::Color::White;
			this->registerBtnLoginPage->Location = System::Drawing::Point(495, 608);
			this->registerBtnLoginPage->Name = L"registerBtnLoginPage";
			this->registerBtnLoginPage->Size = System::Drawing::Size(162, 37);
			this->registerBtnLoginPage->TabIndex = 5;
			this->registerBtnLoginPage->Text = L"Tap to Register";
			this->registerBtnLoginPage->UseVisualStyleBackColor = false;
			this->registerBtnLoginPage->Click += gcnew System::EventHandler(this, &MyForm::registerBtnLoginPage_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"IBM Plex Sans SemiBold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(519, 575);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(115, 20);
			this->label3->TabIndex = 1;
			this->label3->Text = L"New to FGCU\?";
			this->label3->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->passwordTxtBox);
			this->panel2->Controls->Add(this->linkLabel1);
			this->panel2->Controls->Add(this->loginBtn);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->usernameTxtBox);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Location = System::Drawing::Point(324, 135);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(505, 393);
			this->panel2->TabIndex = 0;
			// 
			// passwordTxtBox
			// 
			this->passwordTxtBox->AllowDrop = true;
			this->passwordTxtBox->Font = (gcnew System::Drawing::Font(L"IBM Plex Sans SemiBold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordTxtBox->ForeColor = System::Drawing::Color::Gainsboro;
			this->passwordTxtBox->Location = System::Drawing::Point(45, 183);
			this->passwordTxtBox->Multiline = true;
			this->passwordTxtBox->Name = L"passwordTxtBox";
			this->passwordTxtBox->PasswordChar = '*';
			this->passwordTxtBox->Size = System::Drawing::Size(378, 40);
			this->passwordTxtBox->TabIndex = 2;
			this->passwordTxtBox->Text = L"Enter Password";
			this->passwordTxtBox->UseSystemPasswordChar = true;
			this->passwordTxtBox->Click += gcnew System::EventHandler(this, &MyForm::passwordTxtBox_Click);
			this->passwordTxtBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::passwordTxtBox_KeyPress);
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Font = (gcnew System::Drawing::Font(L"IBM Plex Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->linkLabel1->LinkColor = System::Drawing::Color::LightGray;
			this->linkLabel1->Location = System::Drawing::Point(168, 343);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(142, 20);
			this->linkLabel1->TabIndex = 4;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Forgot Password\?";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MyForm::linkLabel1_LinkClicked);
			// 
			// loginBtn
			// 
			this->loginBtn->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->loginBtn->BackColor = System::Drawing::Color::Transparent;
			this->loginBtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->loginBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->loginBtn->ForeColor = System::Drawing::Color::Transparent;
			this->loginBtn->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"loginBtn.Image")));
			this->loginBtn->Location = System::Drawing::Point(126, 269);
			this->loginBtn->Name = L"loginBtn";
			this->loginBtn->Size = System::Drawing::Size(237, 53);
			this->loginBtn->TabIndex = 3;
			this->loginBtn->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->loginBtn->UseVisualStyleBackColor = false;
			this->loginBtn->Click += gcnew System::EventHandler(this, &MyForm::loginBtn_Click);
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"IBM Plex Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(41, 147);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(192, 23);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Password:";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// usernameTxtBox
			// 
			this->usernameTxtBox->AllowDrop = true;
			this->usernameTxtBox->Font = (gcnew System::Drawing::Font(L"IBM Plex Sans SemiBold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->usernameTxtBox->ForeColor = System::Drawing::Color::Gainsboro;
			this->usernameTxtBox->Location = System::Drawing::Point(45, 77);
			this->usernameTxtBox->Multiline = true;
			this->usernameTxtBox->Name = L"usernameTxtBox";
			this->usernameTxtBox->Size = System::Drawing::Size(378, 40);
			this->usernameTxtBox->TabIndex = 1;
			this->usernameTxtBox->Text = L"Enter Username";
			this->usernameTxtBox->Click += gcnew System::EventHandler(this, &MyForm::userNameTxtBox_Click);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"IBM Plex Sans", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(41, 42);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(192, 23);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Username:";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 11);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1188, 681);
			this->Controls->Add(this->loginPanel);
			this->Font = (gcnew System::Drawing::Font(L"Objectivity Super", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ForeColor = System::Drawing::Color::White;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Login Form";
			this->loginPanel->ResumeLayout(false);
			this->loginPanel->PerformLayout();
			this->dashboardPanel->ResumeLayout(false);
			this->registerPanel->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	public: User^ user = nullptr;
	private: System::Void loginBtn_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ username = this->usernameTxtBox->Text;
		String^ password = this->passwordTxtBox->Text;

		if (username->Length == 0 || password->Length == 0)
		{
			MessageBox::Show("Please enter username and password",
				"Username or Password Empty", MessageBoxButtons::OK);
			return;
		}

		try
		{

			String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=newStudent;Integrated Security=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			String^ sqlQuery = "SELECT * FROM users WHERE username=@username AND password=@password;";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@username", username);
			command.Parameters->AddWithValue("@password", password);

			SqlDataReader^ reader = command.ExecuteReader();
			if (reader->Read())
			{

				user = gcnew User;
				user->id = reader->GetInt32(0);
				user->firstName = reader->GetString(1);
				user->lastName = reader->GetString(2);
				user->email = reader->GetString(3);
				user->phone = reader->GetString(4);
				user->username = reader->GetString(5);
				user->password = reader->GetString(6);

				this->Close();


			}
			else
			{
				MessageBox::Show("Email or password is incorrect",
					"Email or Password Error", MessageBoxButtons::OK);
			}

			loginPanel->Hide();
			registerPanel->Hide();
			dashboardPanel->Show();


		}
		catch (Exception^ e)
		{
			dashboardPanel->Show();
			registerPanel->Hide();
			userNameDashboard->Text = "" + user->firstName + " " + user->lastName;
		}

	}
	private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void userNameTxtBox_Click(System::Object^ sender, System::EventArgs^ e) {

		if (usernameTxtBox->Text == "Enter Username")
		{
			usernameTxtBox->Text = "";
		}

		usernameTxtBox->ForeColor = System::Drawing::Color::Black;
	}
	private: System::Void passwordTxtBox_Click(System::Object^ sender, System::EventArgs^ e) {

		if (passwordTxtBox->Text == "Enter Password")
		{
			passwordTxtBox->Text = "";
		}

		if (passwordTxtBox->UseSystemPasswordChar == true)
		{
			passwordTxtBox->UseSystemPasswordChar = false;
		}

		passwordTxtBox->ForeColor = System::Drawing::Color::Black;

	}
	private: System::Void dashboardPanel_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		dashboardPanel->Hide();
		loginPanel->Show();
		usernameTxtBox->Text == "Enter Username";
		usernameTxtBox->ForeColor = System::Drawing::Color::Gainsboro;
		passwordTxtBox->Text == "Enter Password";
		passwordTxtBox->ForeColor = System::Drawing::Color::Gainsboro;
	}
	private: System::Void registerFirstName_Click(System::Object^ sender, System::EventArgs^ e) {

		if (registerFirstName->Text == "Enter First Name")
		{
			registerFirstName->Text = "";
		}

		registerFirstName->ForeColor = System::Drawing::Color::Black;

	}
	private: System::Void registerLastName_Click(System::Object^ sender, System::EventArgs^ e) {


		if (registerLastName->Text == "Enter Last Name")
		{
			registerLastName->Text = "";
		}

		registerLastName->ForeColor = System::Drawing::Color::Black;
	}
	private: System::Void registerEmail_Click(System::Object^ sender, System::EventArgs^ e) {

		if (registerEmail->Text == "Enter Email")
		{
			registerEmail->Text = "";
		}

		registerEmail->ForeColor = System::Drawing::Color::Black;

	}
	private: System::Void registerUsername_Click(System::Object^ sender, System::EventArgs^ e) {
		if (registerUsername->Text == "Enter Username")
		{
			registerUsername->Text = "";
		}

		registerUsername->ForeColor = System::Drawing::Color::Black;

	}
	private: System::Void registerPassword_Click(System::Object^ sender, System::EventArgs^ e) {

		if (registerPassword->Text == "Enter Password")
		{
			registerPassword->Text = "";
		}

		if (registerPassword->UseSystemPasswordChar == true)
		{
			registerPassword->UseSystemPasswordChar = false;
		}

		registerPassword->ForeColor = System::Drawing::Color::Black;
	}
	private: System::Void registerBtnLoginPage_Click(System::Object^ sender, System::EventArgs^ e) {

		dashboardPanel->Show();
		registerPanel->Show();

	}
	private: System::Void loginLink_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {

		dashboardPanel->Hide();

	}
private: System::Void registerBTN_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ firstName = registerFirstName->Text;
	String^ lastName = registerLastName->Text;
	String^ email = registerEmail->Text;
	String^ username = registerUsername->Text;
	String^ password = registerPassword->Text;

	if(firstName->Length == 0 || registerFirstName->Text == "Enter First Name" || 
		lastName->Length == 0 || registerLastName->Text == "Enter Last Name" || 
		email->Length == 0 || registerEmail->Text == "Enter Email" ||
		username->Length == 0 || registerUsername->Text == "Enter Username" ||
		password->Length == 0 || registerPassword->Text == "Enter Password")
	{
		MessageBox::Show("Please enter all fields",
			"One or more fields are empty!", MessageBoxButtons::OK);

		return;
	}

	try
	{

		String^ connString = "Data Source=localhost\\sqlexpress;Initial Catalog=newStudent;Integrated Security=True";
		SqlConnection sqlConn(connString);
		sqlConn.Open();

		String^ sqlQuery = "INSERT INTO users " +
			"(firstName, lastName, email, username, password) VALUES" +
			"(@firstName, @lastName, @email, @username, @password);";


		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@firstName", firstName);
		command.Parameters->AddWithValue("lastName", lastName);
		command.Parameters->AddWithValue("@email", email);
		command.Parameters->AddWithValue("@username", username);
		command.Parameters->AddWithValue("@password", password);

		SqlDataReader^ reader = command.ExecuteReader();

		user = gcnew User;
		user->firstName = firstName;
		user->lastName = lastName;
		user->email = email;
		user->username = username;
		user->password = password;

		MessageBox::Show("Success!", "New User has been added!",
			MessageBoxButtons::OK);

		dashboardPanel->Hide();
		loginPanel->Show();


	}
	catch (Exception^ ex)
	{
		MessageBox::Show("Failed!", "Failed to register new user.",
			MessageBoxButtons::OK);
	}
}

private: System::Void passwordTxtBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {

	

}
};
}


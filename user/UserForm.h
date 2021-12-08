#pragma once
#include <Windows.h>
#include <msclr\marshal_cppstd.h>
#include <msclr/auto_gcroot.h>

#include <fstream>
#include <thread>
#include "user.h"
#define PUTH_F "C:\\Users\\Saddie\\source\\repos\\lab11OS\\files\\"

namespace user {
	using msclr::auto_gcroot;
	ref class UserForm;
	class cHelper {
	public: auto_gcroot<UserForm^> pUser;
	public: void Reload();
	};
	DWORD WINAPI ReloadT(LPVOID pThreadParam) {
		cHelper* a = (cHelper*)(pThreadParam);
		a->Reload();
		return 0;
	}
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UserForm
	/// </summary>
	public ref class UserForm : public System::Windows::Forms::Form
	{
	public:
		UserForm(string name, int id)
		{
			InitializeComponent();
			pUser = new cUser(id);
			Text = gcnew String(name.c_str());
			errorMes = false;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UserForm()
		{
			if (components)
			{
				delete components;
			}
			delete pUser;
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::TextBox^ textBoxMes;

	private: System::Windows::Forms::Button^ button1;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UserForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBoxMes = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(815, 46);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Dialog:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->textBox->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox->Location = System::Drawing::Point(3, 49);
			this->textBox->Multiline = true;
			this->textBox->Name = L"textBox";
			this->textBox->ReadOnly = true;
			this->textBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox->ShortcutsEnabled = false;
			this->textBox->Size = System::Drawing::Size(815, 299);
			this->textBox->TabIndex = 2;
			this->textBox->WordWrap = false;
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->textBox, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 4;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 13.24042)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 86.75958)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 38)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 8)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(821, 398);
			this->tableLayoutPanel1->TabIndex = 3;
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				87.03704)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				12.96296)));
			this->tableLayoutPanel2->Controls->Add(this->textBoxMes, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->button1, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 354);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(815, 32);
			this->tableLayoutPanel2->TabIndex = 0;
			this->textBoxMes->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->textBoxMes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBoxMes->Location = System::Drawing::Point(3, 4);
			this->textBoxMes->MaxLength = 95;
			this->textBoxMes->Name = L"textBoxMes";
			this->textBoxMes->Size = System::Drawing::Size(703, 24);
			this->textBoxMes->TabIndex = 0;
			this->textBoxMes->TextChanged += gcnew System::EventHandler(this, &UserForm::textBoxMes_TextChanged);
			this->textBoxMes->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &UserForm::textBoxMes_Validating);
			this->textBoxMes->Validated += gcnew System::EventHandler(this, &UserForm::textBoxMes_Validated);
			this->button1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button1->Location = System::Drawing::Point(712, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 26);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Send";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UserForm::button1_Click_1);
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(821, 398);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximumSize = System::Drawing::Size(837, 437);
			this->MinimumSize = System::Drawing::Size(465, 385);
			this->Name = L"UserForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"User";
			this->Load += gcnew System::EventHandler(this, &UserForm::UserForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: HANDLE hEventReload;
	public: void Reload() { //метод оновлення діалогу
		hEventReload = OpenEventA(EVENT_ALL_ACCESS, false, "$MyEventReload$");
		textBox->Text = "";
		string fileName = (string)(PUTH_F)+"DialogFile";
		fstream in(fileName);
		string curName;
		char curStr[100];
		while (!in.eof())
		{
			in.getline(curStr, 100, '\n');
			string temp(curStr);
			textBox->Text = textBox->Text + gcnew System::String(temp.c_str()) + "\r\n";
		}
		in.close();
		while (1) {
			DWORD dwCode = WaitForSingleObject(hEventReload, INFINITE);
			if (dwCode == WAIT_OBJECT_0) {
				textBox->Text = "";
				std::fstream in(fileName);
				std::string curName;
				char curStr[100];
				while (!in.eof())
				{
					in.getline(curStr, 100, '\n');
					string temp(curStr);
					textBox->Text = textBox->Text  + gcnew System::String(temp.c_str()) + "\r\n";
				}
				in.close();
			}
			
		}
	}
	
	private: cUser *pUser;
	private: cHelper *pHelper;
	private: HANDLE hReload;
	private: System::Void UserForm_Load(System::Object^ sender, System::EventArgs^ e) {
		pHelper = new cHelper();
		pHelper->pUser = this;
		DWORD id;
		hReload = CreateThread(NULL, 0, ReloadT, pHelper, 0, &id);
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {//метод надіслання повідомлення
		if (errorMes) return;
		string temp = msclr::interop::marshal_as<std::string>(Text + ": " +textBoxMes->Text);
		int a = pUser->Send(temp);
		if (a == 1) {
			System::Windows::Forms::MessageBox::Show("Too many forbidden words!\nMessage not sent.", "Error!", System::Windows::Forms::MessageBoxButtons::OK);
		}
		textBoxMes->Text = "";
	}
	private: bool errorMes;
	
	private: System::Void textBoxMes_Validating(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) { //перевірка на правильність повідослення
		if (String::IsNullOrEmpty(textBoxMes->Text) || String::IsNullOrWhiteSpace(textBoxMes->Text)) errorMes = true;
		else errorMes = false;
		if (errorMes) button1->Enabled = false;
		else button1->Enabled = true;
	}
private: System::Void textBoxMes_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	errorMes = false;
	button1->Enabled = true;
}
private: System::Void textBoxMes_Validated(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrEmpty(textBoxMes->Text) || String::IsNullOrWhiteSpace(textBoxMes->Text)) errorMes = true;
	else errorMes = false;
	if (errorMes) button1->Enabled = false;
	else button1->Enabled = true;
}
};
	void cHelper::Reload() {
		this->pUser->Reload();
	}
	
}

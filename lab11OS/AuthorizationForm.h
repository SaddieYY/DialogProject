#pragma once
#include <Windows.h>
#include <string>
#include <list>
#include <fstream>
#include <msclr\marshal_cppstd.h>
#define PUTH_F "C:\\Users\\Saddie\\source\\repos\\lab11OS\\files\\"
using namespace std;
namespace lab11OS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AuthorizationForm
	/// </summary>
	public ref class AuthorizationForm : public System::Windows::Forms::Form
	{
	public:
		AuthorizationForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AuthorizationForm()
		{
			if (components)
			{
				delete components;
			}
			SetEvent(hEventTermination);
			CloseHandle(hEventCreateClient);
			CloseHandle(hEventCreatedClient);
			CloseHandle(hCreateMail);
		}
	private: System::Windows::Forms::TextBox^ textBoxName;
	private: System::Windows::Forms::Button^ buttonAccept;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ErrorProvider^ errorProvider1;
	private: System::ComponentModel::IContainer^ components;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AuthorizationForm::typeid));
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->buttonAccept = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBoxName
			// 
			this->textBoxName->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->textBoxName->Location = System::Drawing::Point(79, 3);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(148, 20);
			this->textBoxName->TabIndex = 0;
			this->textBoxName->TextChanged += gcnew System::EventHandler(this, &AuthorizationForm::textBoxName_TextChanged);
			this->textBoxName->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &AuthorizationForm::textBoxName_Validating);
			this->textBoxName->Validated += gcnew System::EventHandler(this, &AuthorizationForm::textBoxName_Validated);
			// 
			// buttonAccept
			// 
			this->buttonAccept->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->buttonAccept->Location = System::Drawing::Point(116, 63);
			this->buttonAccept->Name = L"buttonAccept";
			this->buttonAccept->Size = System::Drawing::Size(75, 23);
			this->buttonAccept->TabIndex = 1;
			this->buttonAccept->Text = L"Accept";
			this->buttonAccept->UseVisualStyleBackColor = true;
			this->buttonAccept->Click += gcnew System::EventHandler(this, &AuthorizationForm::buttonAccept_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.48624F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 66.51376F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(313, 208);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->textBoxName, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->buttonAccept, 0, 1);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 72);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 45.76271F)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 54.23729F)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(307, 133);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(3, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(307, 69);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Registration";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// errorProvider1
			// 
			this->errorProvider1->BlinkStyle = System::Windows::Forms::ErrorBlinkStyle::NeverBlink;
			this->errorProvider1->ContainerControl = this;
			// 
			// AuthorizationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(313, 208);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AuthorizationForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Registration";
			this->Load += gcnew System::EventHandler(this, &AuthorizationForm::AuthorizationForm_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: HANDLE hCreateMail;
	private: HANDLE hEventCreateClient;
	private: HANDLE hEventCreatedClient;
	private: HANDLE hEventTermination;
	private: bool findUser(string userName) {
		string fileName = (string)(PUTH_F) + "UserList";
		std::fstream in(fileName);
		if (!in.is_open()) {
			return false;
		}
		std::string curName;
		curName.reserve(100);
		char curStr[100];
		int count = 0;
		while (!in.eof())
		{
			in.getline(curStr, 100, '\n');
			curName.assign(curStr);
			if (curName == userName) {
				in.close();
				return true;
			}

		}
		in.close();
		return false;
	}
	private: void writeUser(string userName) { //запис користувача в файл
		string fileName = (string)(PUTH_F) + "UserList";
		ofstream out(fileName, std::ofstream::ate | std::ofstream::app);
		string curName;
		int count = 0;
		out.write((userName + '\n').data(), userName.size() + 1);
		out.close();
	}
	private: System::Void buttonAccept_Click(System::Object^ sender, System::EventArgs^ e) {//метод додавання користувача
		if (errorName) return;
		string temp = msclr::interop::marshal_as<std::string>(textBoxName->Text);
		if (!findUser(temp)) {
			writeUser(temp);
		}
		else {
			System::Windows::Forms::MessageBox::Show("Name is already used!", "Warning!", System::Windows::Forms::MessageBoxButtons::OK);
			textBoxName->Text = "";
			return;
		}
		const char* buf = temp.c_str();
		WriteFile(hCreateMail, buf, strlen(buf) + 1, NULL, NULL);
		SetEvent(hEventCreateClient);
		WaitForSingleObject(hEventCreatedClient, INFINITE);
		textBoxName->Text = "";
	}
	private: System::Void AuthorizationForm_Load(System::Object^ sender, System::EventArgs^ e) {
		 
		HANDLE serverCreate = OpenEventA(EVENT_ALL_ACCESS, true, "$MyEventCreateServer$");
		if (!serverCreate) {
			PROCESS_INFORMATION* pi = new PROCESS_INFORMATION;
			STARTUPINFOA *si = new STARTUPINFOA;
			ZeroMemory(si, sizeof(*si));
			si->cb = sizeof(*si);
			ZeroMemory(pi, sizeof(*pi));
			CreateProcessA(NULL, "server.exe ", NULL, NULL, FALSE, CREATE_NO_WINDOW, NULL, NULL, si, pi);
			serverCreate = OpenEventA(EVENT_ALL_ACCESS, false, "$MyEventCreateServer$");
			while(!serverCreate) serverCreate = OpenEventA(EVENT_ALL_ACCESS, false, "$MyEventCreateServer$");
		}
		 DWORD dwCode = WaitForSingleObject(serverCreate, INFINITE);
		 if (dwCode == WAIT_OBJECT_0) {
			 hEventCreateClient = OpenEventA(EVENT_ALL_ACCESS, false, "$MyEventCreateUser$");
			 hEventCreatedClient = OpenEventA(EVENT_ALL_ACCESS, false, "$MyEventCreated$");
			 hEventTermination = OpenEventA(EVENT_ALL_ACCESS, false, "$MyEventTerminated$");
			 hCreateMail = CreateFileA("\\\\.\\mailslot\\$createmail$", GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			 
		 }
	}
	private: bool errorName;
	private: System::Void textBoxName_Validating(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {//перевірка на правильність імені
		if (String::IsNullOrEmpty(textBoxName->Text) || String::IsNullOrWhiteSpace(textBoxName->Text)) {
			errorProvider1->SetError(textBoxName, "Invalid name!");
			errorName = true;
		}
		else {
			errorProvider1->Clear();
			errorName = false;
		}
		if (errorName) buttonAccept->Enabled = false;
		else buttonAccept->Enabled = true;
	}
	private: System::Void textBoxName_Validated(System::Object^ sender, System::EventArgs^ e) {
	if (String::IsNullOrEmpty(textBoxName->Text) || String::IsNullOrWhiteSpace(textBoxName->Text)) {
			errorProvider1->SetError(textBoxName, "Invalid name!");
			errorName = true;
	}
	else {
		errorProvider1->Clear();
		errorName = false;
	}
	if (errorName) buttonAccept->Enabled = false;
	else buttonAccept->Enabled = true;
	}
	private: System::Void textBoxName_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		errorName = false;
		errorProvider1->Clear();
		buttonAccept->Enabled = true;
	}
};
}

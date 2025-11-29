#pragma once
#include "MyForm3.h"
#include "MyForm4.h"

namespace WinForms {
	ref class MyForm1;
	ref class MyForm3;
	ref class MyForm4;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	private:
		MyForm1^ form1;
		String^ formMode;

		void CenterForm();
		void ApplyVisualMode();
		void ApplyAdminStyle();
		void ApplyDefaultStyle();

	public:
		MyForm2(void);
		MyForm2(MyForm1^ parentForm);
		MyForm2(MyForm1^ parentForm, String^ mode);
		MyForm2(MyForm1^ parentForm, bool isAdminMode);

	protected:
		~MyForm2();

	private:
		System::Windows::Forms::Button^ buttonBenefits;
		System::Windows::Forms::Button^ buttonNoBenefits;
		System::Windows::Forms::Button^ buttonExit;
		System::Windows::Forms::Label^ labelTitle;
		System::Windows::Forms::Button^ buttonAdminMode;
		System::Windows::Forms::Button^ buttonStandardMode;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm2::typeid));
			this->buttonBenefits = (gcnew System::Windows::Forms::Button());
			this->buttonNoBenefits = (gcnew System::Windows::Forms::Button());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->labelTitle = (gcnew System::Windows::Forms::Label());
			this->buttonAdminMode = (gcnew System::Windows::Forms::Button());
			this->buttonStandardMode = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonBenefits
			// 
			this->buttonBenefits->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->buttonBenefits->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonBenefits->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 28.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonBenefits->ForeColor = System::Drawing::Color::ForestGreen;
			this->buttonBenefits->Location = System::Drawing::Point(12, 222);
			this->buttonBenefits->Name = L"buttonBenefits";
			this->buttonBenefits->Size = System::Drawing::Size(766, 76);
			this->buttonBenefits->TabIndex = 0;
			this->buttonBenefits->Text = L"Добавить жильца со льготой";
			this->buttonBenefits->UseVisualStyleBackColor = false;
			this->buttonBenefits->Click += gcnew System::EventHandler(this, &MyForm2::buttonBenefits_Click);
			// 
			// buttonNoBenefits
			// 
			this->buttonNoBenefits->BackColor = System::Drawing::Color::Teal;
			this->buttonNoBenefits->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonNoBenefits->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 28.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonNoBenefits->ForeColor = System::Drawing::Color::DarkOrchid;
			this->buttonNoBenefits->Location = System::Drawing::Point(899, 222);
			this->buttonNoBenefits->Name = L"buttonNoBenefits";
			this->buttonNoBenefits->Size = System::Drawing::Size(704, 76);
			this->buttonNoBenefits->TabIndex = 1;
			this->buttonNoBenefits->Text = L"Добавить жильца без льготы";
			this->buttonNoBenefits->UseVisualStyleBackColor = false;
			this->buttonNoBenefits->Click += gcnew System::EventHandler(this, &MyForm2::buttonNoBenefits_Click);
			// 
			// buttonExit
			// 
			this->buttonExit->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->buttonExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonExit->Location = System::Drawing::Point(12, 12);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(149, 45);
			this->buttonExit->TabIndex = 2;
			this->buttonExit->Text = L"Назад";
			this->buttonExit->UseVisualStyleBackColor = false;
			this->buttonExit->Click += gcnew System::EventHandler(this, &MyForm2::buttonExit_Click);
			// 
			// labelTitle
			// 
			this->labelTitle->AutoSize = true;
			this->labelTitle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelTitle->Location = System::Drawing::Point(600, 100);
			this->labelTitle->Name = L"labelTitle";
			this->labelTitle->Size = System::Drawing::Size(308, 36);
			this->labelTitle->TabIndex = 3;
			this->labelTitle->Text = L"Выбор типа жильца";
			this->labelTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// buttonAdminMode
			// 
			this->buttonAdminMode->BackColor = System::Drawing::Color::LightGray;
			this->buttonAdminMode->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonAdminMode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonAdminMode->ForeColor = System::Drawing::Color::DarkBlue;
			this->buttonAdminMode->Location = System::Drawing::Point(1200, 12);
			this->buttonAdminMode->Name = L"buttonAdminMode";
			this->buttonAdminMode->Size = System::Drawing::Size(180, 45);
			this->buttonAdminMode->TabIndex = 4;
			this->buttonAdminMode->Text = L"Админ";
			this->buttonAdminMode->UseVisualStyleBackColor = false;
			this->buttonAdminMode->Click += gcnew System::EventHandler(this, &MyForm2::buttonAdminMode_Click);
			// 
			// buttonStandardMode
			// 
			this->buttonStandardMode->BackColor = System::Drawing::Color::LightGreen;
			this->buttonStandardMode->Enabled = false;
			this->buttonStandardMode->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonStandardMode->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonStandardMode->ForeColor = System::Drawing::Color::DarkGreen;
			this->buttonStandardMode->Location = System::Drawing::Point(1400, 12);
			this->buttonStandardMode->Name = L"buttonStandardMode";
			this->buttonStandardMode->Size = System::Drawing::Size(200, 45);
			this->buttonStandardMode->TabIndex = 5;
			this->buttonStandardMode->Text = L"Стандарт";
			this->buttonStandardMode->UseVisualStyleBackColor = false;
			this->buttonStandardMode->Click += gcnew System::EventHandler(this, &MyForm2::buttonStandardMode_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1617, 859);
			this->Controls->Add(this->buttonStandardMode);
			this->Controls->Add(this->buttonAdminMode);
			this->Controls->Add(this->labelTitle);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->buttonNoBenefits);
			this->Controls->Add(this->buttonBenefits);
			this->Name = L"MyForm2";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Хайп";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonBenefits_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonNoBenefits_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonAdminMode_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonStandardMode_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
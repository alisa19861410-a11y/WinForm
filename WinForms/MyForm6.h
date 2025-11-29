#pragma once

#include <fstream>
#include "MyForm3.h"

namespace WinForms {
	ref class MyForm1;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Сводка для MyForm6
	/// </summary>
	public ref class MyForm6 : public System::Windows::Forms::Form
	{
	private:
		MyForm1^ form1;
		String^ formMode;

		void CenterForm();
		array<String^>^ ReadDataFromFile();
		array<String^>^ ParseDataLine(String^ dataLine);
		void CalculateTotalCost();

	public:
		MyForm6(MyForm1^ parentForm);

	protected:
		~MyForm6();

	private:
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Button^ buttonExit;
		System::Windows::Forms::Label^ labelTotalCost;
		System::Windows::Forms::Label^ labelCostWithBenefits;
		System::Windows::Forms::Label^ labelDiscount;
		System::Windows::Forms::Label^ labelResidentsCount;
		System::Windows::Forms::Label^ labelResidentsWithBenefits;
		System::Windows::Forms::Button^ buttonRefresh;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm6::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->labelTotalCost = (gcnew System::Windows::Forms::Label());
			this->labelCostWithBenefits = (gcnew System::Windows::Forms::Label());
			this->labelDiscount = (gcnew System::Windows::Forms::Label());
			this->labelResidentsCount = (gcnew System::Windows::Forms::Label());
			this->labelResidentsWithBenefits = (gcnew System::Windows::Forms::Label());
			this->buttonRefresh = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 25.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->label1->Location = System::Drawing::Point(441, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(666, 52);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Общая стоимость всех оказанных услуг";
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
			this->buttonExit->TabIndex = 4;
			this->buttonExit->Text = L"Назад";
			this->buttonExit->UseVisualStyleBackColor = false;
			this->buttonExit->Click += gcnew System::EventHandler(this, &MyForm6::buttonExit_Click);
			// 
			// labelTotalCost
			// 
			this->labelTotalCost->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->labelTotalCost->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->labelTotalCost->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelTotalCost->ForeColor = System::Drawing::Color::DarkRed;
			this->labelTotalCost->Location = System::Drawing::Point(100, 100);
			this->labelTotalCost->Name = L"labelTotalCost";
			this->labelTotalCost->Size = System::Drawing::Size(1400, 50);
			this->labelTotalCost->TabIndex = 5;
			this->labelTotalCost->Text = L"Общая стоимость: рассчитывается";
			this->labelTotalCost->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelCostWithBenefits
			// 
			this->labelCostWithBenefits->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->labelCostWithBenefits->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->labelCostWithBenefits->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->labelCostWithBenefits->Location = System::Drawing::Point(100, 170);
			this->labelCostWithBenefits->Name = L"labelCostWithBenefits";
			this->labelCostWithBenefits->Size = System::Drawing::Size(1400, 40);
			this->labelCostWithBenefits->TabIndex = 6;
			this->labelCostWithBenefits->Text = L"Стоимость с учетом льгот: рассчитывается";
			this->labelCostWithBenefits->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelDiscount
			// 
			this->labelDiscount->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->labelDiscount->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->labelDiscount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelDiscount->Location = System::Drawing::Point(100, 220);
			this->labelDiscount->Name = L"labelDiscount";
			this->labelDiscount->Size = System::Drawing::Size(1400, 40);
			this->labelDiscount->TabIndex = 7;
			this->labelDiscount->Text = L"Общая сумма льгот: рассчитывается";
			this->labelDiscount->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// labelResidentsCount
			// 
			this->labelResidentsCount->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->labelResidentsCount->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->labelResidentsCount->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->labelResidentsCount->Location = System::Drawing::Point(100, 280);
			this->labelResidentsCount->Name = L"labelResidentsCount";
			this->labelResidentsCount->Size = System::Drawing::Size(700, 35);
			this->labelResidentsCount->TabIndex = 8;
			this->labelResidentsCount->Text = L"Количество жильцов: рассчитывается";
			this->labelResidentsCount->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// labelResidentsWithBenefits
			// 
			this->labelResidentsWithBenefits->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->labelResidentsWithBenefits->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->labelResidentsWithBenefits->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->labelResidentsWithBenefits->Location = System::Drawing::Point(800, 280);
			this->labelResidentsWithBenefits->Name = L"labelResidentsWithBenefits";
			this->labelResidentsWithBenefits->Size = System::Drawing::Size(700, 35);
			this->labelResidentsWithBenefits->TabIndex = 9;
			this->labelResidentsWithBenefits->Text = L"Из них со льготами: рассчитывается";
			this->labelResidentsWithBenefits->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// buttonRefresh
			// 
			this->buttonRefresh->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->buttonRefresh->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonRefresh->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonRefresh->Location = System::Drawing::Point(1370, 12);
			this->buttonRefresh->Name = L"buttonRefresh";
			this->buttonRefresh->Size = System::Drawing::Size(239, 65);
			this->buttonRefresh->TabIndex = 11;
			this->buttonRefresh->Text = L"Обновить";
			this->buttonRefresh->UseVisualStyleBackColor = false;
			this->buttonRefresh->Click += gcnew System::EventHandler(this, &MyForm6::buttonRefresh_Click);
			// 
			// MyForm6
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1620, 867);
			this->Controls->Add(this->buttonRefresh);
			this->Controls->Add(this->labelResidentsWithBenefits);
			this->Controls->Add(this->labelResidentsCount);
			this->Controls->Add(this->labelDiscount);
			this->Controls->Add(this->labelCostWithBenefits);
			this->Controls->Add(this->labelTotalCost);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm6";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Премиум калькулятор";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonRefresh_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
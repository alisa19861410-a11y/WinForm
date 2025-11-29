#pragma once

#include <fstream>

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
	/// Сводка для MyForm5
	/// </summary>
	public ref class MyForm5 : public System::Windows::Forms::Form
	{
	private:
		MyForm1^ form1;
		String^ formMode;
		Collections::Generic::List<array<String^>^>^ allResidents;

		void CenterForm();
		array<String^>^ ReadDataFromFile();
		void WriteDataToFile(Collections::Generic::List<array<String^>^>^ residents);
		array<String^>^ ParseDataLine(String^ dataLine);
		static int CompareByBenefitPercent(array<String^>^ x, array<String^>^ y);
		void LoadResidentsData();
		array<String^>^ GetSelectedResident();
		void DeleteResident(array<String^>^ residentToDelete);
		void EditResident(array<String^>^ residentToEdit);

	public:
		MyForm5(void);
		MyForm5(MyForm1^ parentForm, String^ mode);

	protected:
		~MyForm5();

	private:
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::Button^ buttonExit;
		System::Windows::Forms::Button^ buttonRefresh;
		System::Windows::Forms::Button^ buttonEdit;
		System::Windows::Forms::Button^ buttonDelete;
		System::Windows::Forms::DataGridView^ dataGridViewResidents;
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm5::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->buttonRefresh = (gcnew System::Windows::Forms::Button());
			this->buttonEdit = (gcnew System::Windows::Forms::Button());
			this->buttonDelete = (gcnew System::Windows::Forms::Button());
			this->dataGridViewResidents = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewResidents))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 25.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::Green;
			this->label1->Location = System::Drawing::Point(622, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(280, 52);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Список жильцов";
			// 
			// buttonExit
			// 
			this->buttonExit->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->buttonExit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonExit->Location = System::Drawing::Point(12, 9);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(149, 45);
			this->buttonExit->TabIndex = 3;
			this->buttonExit->Text = L"Назад";
			this->buttonExit->UseVisualStyleBackColor = false;
			this->buttonExit->Click += gcnew System::EventHandler(this, &MyForm5::buttonExit_Click);
			// 
			// buttonRefresh
			// 
			this->buttonRefresh->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->buttonRefresh->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonRefresh->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonRefresh->Location = System::Drawing::Point(1370, 9);
			this->buttonRefresh->Name = L"buttonRefresh";
			this->buttonRefresh->Size = System::Drawing::Size(239, 65);
			this->buttonRefresh->TabIndex = 5;
			this->buttonRefresh->Text = L"Обновить";
			this->buttonRefresh->UseVisualStyleBackColor = false;
			this->buttonRefresh->Click += gcnew System::EventHandler(this, &MyForm5::buttonRefresh_Click);
			// 
			// buttonEdit
			// 
			this->buttonEdit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->buttonEdit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonEdit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonEdit->Location = System::Drawing::Point(12, 650);
			this->buttonEdit->Name = L"buttonEdit";
			this->buttonEdit->Size = System::Drawing::Size(239, 65);
			this->buttonEdit->TabIndex = 6;
			this->buttonEdit->Text = L"Изменить";
			this->buttonEdit->UseVisualStyleBackColor = false;
			this->buttonEdit->Click += gcnew System::EventHandler(this, &MyForm5::buttonEdit_Click);
			// 
			// buttonDelete
			// 
			this->buttonDelete->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->buttonDelete->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonDelete->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonDelete->Location = System::Drawing::Point(270, 650);
			this->buttonDelete->Name = L"buttonDelete";
			this->buttonDelete->Size = System::Drawing::Size(239, 65);
			this->buttonDelete->TabIndex = 7;
			this->buttonDelete->Text = L"Удалить";
			this->buttonDelete->UseVisualStyleBackColor = false;
			this->buttonDelete->Click += gcnew System::EventHandler(this, &MyForm5::buttonDelete_Click);
			// 
			// dataGridViewResidents
			// 
			this->dataGridViewResidents->AllowUserToAddRows = false;
			this->dataGridViewResidents->AllowUserToDeleteRows = false;
			this->dataGridViewResidents->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewResidents->BackgroundColor = System::Drawing::Color::White;
			this->dataGridViewResidents->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewResidents->Location = System::Drawing::Point(12, 80);
			this->dataGridViewResidents->Name = L"dataGridViewResidents";
			this->dataGridViewResidents->ReadOnly = true;
			this->dataGridViewResidents->RowHeadersWidth = 51;
			this->dataGridViewResidents->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridViewResidents->Size = System::Drawing::Size(1597, 554);
			this->dataGridViewResidents->TabIndex = 8;
			// 
			// MyForm5
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1621, 867);
			this->Controls->Add(this->dataGridViewResidents);
			this->Controls->Add(this->buttonDelete);
			this->Controls->Add(this->buttonEdit);
			this->Controls->Add(this->buttonRefresh);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm5";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Список жильцов";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewResidents))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void buttonExit_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonRefresh_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonEdit_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void buttonDelete_Click(System::Object^ sender, System::EventArgs^ e);
	};
}
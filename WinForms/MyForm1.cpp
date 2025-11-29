#include "MyForm1.h"
#include "MyForm2.h"
#include "MyForm3.h"
#include "MyForm4.h" 
#include "MyForm5.h"
#include "MyForm6.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main() {
    Application::SetCompatibleTextRenderingDefault(false);
    Application::EnableVisualStyles();
    WinForms::MyForm1 form;
    Application::Run(% form);
    return 0;
}

namespace WinForms {

    //MyForm1
    MyForm1::MyForm1(void) {
        InitializeComponent();
        this->StartPosition = FormStartPosition::CenterScreen;
    }

    MyForm1::~MyForm1() {
        if (components) {
            delete components;
        }
    }

    //MyForm2
    MyForm2::MyForm2(void) {
        formMode = "Default";
        InitializeComponent();
        ApplyVisualMode();
        CenterForm();
    }

    MyForm2::MyForm2(MyForm1^ parentForm) {
        form1 = parentForm;
        formMode = "Normal";
        InitializeComponent();
        ApplyVisualMode();
        CenterForm();
    }

    MyForm2::MyForm2(MyForm1^ parentForm, String^ mode) {
        form1 = parentForm;
        formMode = mode;
        InitializeComponent();
        ApplyVisualMode();
        CenterForm();
    }

    MyForm2::MyForm2(MyForm1^ parentForm, bool isAdminMode) {
        form1 = parentForm;
        formMode = isAdminMode ? "Admin" : "User";
        InitializeComponent();
        ApplyVisualMode();
        CenterForm();
    }

    MyForm2::~MyForm2() {
        if (components) {
            delete components;
        }
    }

    //MyForm3
    MyForm3::MyForm3(void) {
        InitializeComponent();
        CenterForm();
        this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
        isClosing = false;
    }

    MyForm3::MyForm3(MyForm2^ parentForm) {
        form2 = parentForm;
        InitializeComponent();
        CenterForm();
        this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
        isClosing = false;
    }

    MyForm3::~MyForm3() {
        if (components) {
            delete components;
        }
    }

    //MyForm4
    MyForm4::MyForm4(void) {
        InitializeComponent();
        CenterForm();
        this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
        isClosing = false;
    }

    MyForm4::MyForm4(MyForm2^ parentForm) {
        form2 = parentForm;
        InitializeComponent();
        CenterForm();
        this->AutoValidate = System::Windows::Forms::AutoValidate::Disable;
        isClosing = false;
    }

    MyForm4::~MyForm4() {
        if (components) {
            delete components;
        }
    }

    //MyForm5
    MyForm5::MyForm5(void) {
        formMode = "Default";
        InitializeComponent();
        CenterForm();
        LoadResidentsData();
    }

    MyForm5::MyForm5(MyForm1^ parentForm, String^ mode) {
        form1 = parentForm;
        formMode = mode;
        InitializeComponent();
        CenterForm();
        LoadResidentsData();
    }

    MyForm5::~MyForm5() {
        if (components) {
            delete components;
        }
    }

    //MyForm6
    MyForm6::MyForm6(MyForm1^ parentForm) {
        form1 = parentForm;
        formMode = "Normal";
        InitializeComponent();
        CenterForm();
        CalculateTotalCost();
    }

    MyForm6::~MyForm6() {
        if (components) {
            delete components;
        }
    }
}

//методы MyForm1
namespace WinForms {
    System::Void MyForm1::buttonResident_Click(System::Object^ sender, System::EventArgs^ e) {
        MyForm2^ form2 = gcnew MyForm2(this);
        form2->Show();
        this->Hide();
    }

    System::Void MyForm1::button2_Click(System::Object^ sender, System::EventArgs^ e) {
        MyForm5^ form5 = gcnew MyForm5(this, "ViewResidents");
        form5->Show();
        this->Hide();
    }

    System::Void MyForm1::button3_Click(System::Object^ sender, System::EventArgs^ e) {
        MyForm6^ form6 = gcnew MyForm6(this);
        form6->Show();
        this->Hide();
    }
}

//методы MyForm2
namespace WinForms {
    void MyForm2::CenterForm() {
        this->StartPosition = FormStartPosition::CenterScreen;
    }

    void MyForm2::ApplyVisualMode() {
        if (formMode == "Admin") {
            ApplyAdminStyle();
        }
        else {
            ApplyDefaultStyle();
        }
    }

    void MyForm2::ApplyAdminStyle() {
        this->BackColor = Color::FromArgb(240, 240, 255);
        this->Text = "MyForm2 - Административный режим";

        if (labelTitle != nullptr) {
            labelTitle->Text = "Административный режим";
            labelTitle->ForeColor = Color::DarkBlue;
            labelTitle->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 16, FontStyle::Bold);
        }

        buttonBenefits->BackColor = Color::LightBlue;
        buttonNoBenefits->BackColor = Color::LightGreen;
        buttonExit->BackColor = Color::LightCoral;

        buttonAdminMode->BackColor = Color::Gold;
        buttonAdminMode->Enabled = false;
        buttonStandardMode->BackColor = Color::LightGray;
        buttonStandardMode->Enabled = true;
    }

    void MyForm2::ApplyDefaultStyle() {
        this->BackColor = SystemColors::ActiveCaption;
        this->Text = "MyForm2";

        if (labelTitle != nullptr) {
            labelTitle->Text = "Выбор типа жильца";
            labelTitle->ForeColor = SystemColors::ControlText;
            labelTitle->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 18, FontStyle::Regular);
        }

        buttonBenefits->BackColor = Color::FromArgb(255, 192, 128);
        buttonNoBenefits->BackColor = Color::Teal;
        buttonExit->BackColor = SystemColors::ActiveCaption;

        buttonAdminMode->BackColor = Color::LightGray;
        buttonAdminMode->Enabled = true;
        buttonStandardMode->BackColor = Color::LightGreen;
        buttonStandardMode->Enabled = false;
    }

    System::Void MyForm2::buttonExit_Click(System::Object^ sender, System::EventArgs^ e) {
        if (form1 != nullptr) {
            form1->Show();
            form1->StartPosition = FormStartPosition::CenterScreen;
        }
        this->Close();
    }

    System::Void MyForm2::buttonBenefits_Click(System::Object^ sender, System::EventArgs^ e) {
        MyForm3^ form3 = gcnew MyForm3(this);
        this->Hide();
        form3->ShowDialog();
        this->Show();
        this->StartPosition = FormStartPosition::CenterScreen;
    }

    System::Void MyForm2::buttonNoBenefits_Click(System::Object^ sender, System::EventArgs^ e) {
        MyForm4^ form4 = gcnew MyForm4(this);
        this->Hide();
        form4->ShowDialog();
        this->Show();
        this->StartPosition = FormStartPosition::CenterScreen;
    }

    System::Void MyForm2::buttonAdminMode_Click(System::Object^ sender, System::EventArgs^ e) {
        formMode = "Admin";
        ApplyVisualMode();
        MessageBox::Show("Включен административный режим!", "Режим изменен",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    System::Void MyForm2::buttonStandardMode_Click(System::Object^ sender, System::EventArgs^ e) {
        formMode = "Normal";
        ApplyVisualMode();
        MessageBox::Show("Включен стандартный режим!", "Режим изменен",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
}

//методы MyForm3
namespace WinForms {
    void MyForm3::CenterForm() {
        this->StartPosition = FormStartPosition::CenterScreen;
    }

    bool MyForm3::ContainsOnlyLettersAndSpaces(String^ text) {
        if (String::IsNullOrEmpty(text))
            return false;

        for each (wchar_t c in text) {
            if (!(IsRussianLetter(c) || IsEnglishLetter(c) || c == L' ')) {
                return false;
            }
        }
        return true;
    }

    bool MyForm3::IsRussianLetter(wchar_t c) {
        return (c >= L'А' && c <= L'я') || c == L'ё' || c == L'Ё';
    }

    bool MyForm3::IsEnglishLetter(wchar_t c) {
        return (c >= L'A' && c <= L'Z') || (c >= L'a' && c <= L'z');
    }

    bool MyForm3::IsValidAddress(String^ text) {
        if (String::IsNullOrEmpty(text))
            return false;

        array<String^>^ parts = text->Split(' ');
        if (parts->Length < 2)
            return false;

        String^ lastPart = parts[parts->Length - 1];
        int houseNumber;
        bool isNumber = Int32::TryParse(lastPart, houseNumber);

        if (!isNumber || houseNumber <= 0)
            return false;

        for (int i = 0; i < parts->Length - 1; i++) {
            if (!ContainsOnlyLettersAndSpaces(parts[i]))
                return false;
        }

        return true;
    }

    void MyForm3::ValidateNameInput() {
        if (isClosing) return;
        String^ input = textBox1->Text->Trim();

        if (String::IsNullOrEmpty(input)) {
            MessageBox::Show("Ошибка! Ввод не может быть пустым.", "Ошибка ввода",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox1->Focus();
            return;
        }

        if (!ContainsOnlyLettersAndSpaces(input)) {
            MessageBox::Show("Ошибка! Имя может содержать только буквы (русские или английские) и пробелы.",
                "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox1->Focus();
            textBox1->SelectAll();
            return;
        }

        array<String^>^ words = input->Split(' ');
        int wordCount = 0;

        for each (String ^ word in words) {
            if (!String::IsNullOrWhiteSpace(word))
                wordCount++;
        }

        if (wordCount < 2) {
            MessageBox::Show("Ошибка! Введите имя и фамилию через пробел (например: Иван Иванов).",
                "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox1->Focus();
            textBox1->SelectAll();
            return;
        }

        MessageBox::Show("Имя введено корректно!", "Успех",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    void MyForm3::ValidateAddressInput() {
        if (isClosing) return;
        String^ input = textBox2->Text->Trim();

        if (String::IsNullOrEmpty(input)) {
            MessageBox::Show("Ошибка! Адрес не может быть пустым.", "Ошибка ввода",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox2->Focus();
            return;
        }

        if (!IsValidAddress(input)) {
            MessageBox::Show("Ошибка! Адрес должен содержать название улицы и номер дома через пробел.\nПример: Пионерская 30 или Lenina 15",
                "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox2->Focus();
            textBox2->SelectAll();
            return;
        }

        MessageBox::Show("Адрес введен корректно!", "Успех",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    void MyForm3::ValidateCostInput() {
        if (isClosing) return;
        String^ input = textBox3->Text->Trim();

        if (String::IsNullOrEmpty(input)) {
            MessageBox::Show("Ошибка! Стоимость услуг не может быть пустой.", "Ошибка ввода",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox3->Focus();
            return;
        }

        input = input->Replace(",", ".");

        double cost;
        bool isNumber = Double::TryParse(input, System::Globalization::NumberStyles::Any,
            System::Globalization::CultureInfo::InvariantCulture, cost);

        if (!isNumber) {
            MessageBox::Show("Ошибка! Введите корректное число.",
                "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox3->Focus();
            textBox3->SelectAll();
            return;
        }

        if (cost <= 0) {
            MessageBox::Show("Ошибка! Стоимость услуг должна быть положительным числом.",
                "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox3->Focus();
            textBox3->SelectAll();
            return;
        }

        if (cost > 1000000) {
            MessageBox::Show("Ошибка! Стоимость услуг не может превышать 1 000 000.",
                "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox3->Focus();
            textBox3->SelectAll();
            return;
        }

        array<String^>^ parts = input->Split('.');
        if (parts->Length > 1 && parts[1]->Length > 6) {
            MessageBox::Show("Ошибка! Максимальное количество знаков после точки - 6.",
                "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox3->Focus();
            textBox3->SelectAll();
            return;
        }

        textBox3->Text = cost.ToString("F2", System::Globalization::CultureInfo::InvariantCulture);

        MessageBox::Show("Стоимость введена корректно!", "Успех",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    void MyForm3::ValidateBenefitInput() {
        if (isClosing) return;
        int benefitValue = (int)numericUpDown1->Value;

        if (benefitValue < 1 || benefitValue > 100) {
            MessageBox::Show("Ошибка! Размер льготы должен быть целым числом от 1 до 100.",
                "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            numericUpDown1->Focus();
            numericUpDown1->Select(0, numericUpDown1->Text->Length);
            return;
        }

        MessageBox::Show("Размер льготы введен корректно!", "Успех",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    void MyForm3::ValidateBenefitTypeInput() {
        if (isClosing) return;
        String^ input = maskedTextBox1->Text->Trim();

        if (String::IsNullOrEmpty(input)) {
            MessageBox::Show("Тип льготы не может быть пустым.",
                "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            maskedTextBox1->Focus();
            return;
        }

        if (!ContainsOnlyLettersAndSpaces(input)) {
            MessageBox::Show("Тип льготы может содержать только буквы и пробелы.",
                "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            maskedTextBox1->Focus();
            maskedTextBox1->SelectAll();
            return;
        }

        MessageBox::Show("Тип льготы введен корректно!", "Успех",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    bool MyForm3::ValidateAllFields() {
        String^ nameInput = textBox1->Text->Trim();
        if (String::IsNullOrEmpty(nameInput)) {
            MessageBox::Show("Пожалуйста, заполните поле 'Имя жильца'.",
                "Ошибка проверки", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox1->Focus();
            return false;
        }

        if (!ContainsOnlyLettersAndSpaces(nameInput)) {
            MessageBox::Show("Имя может содержать только буквы и пробелы.",
                "Ошибка проверки", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox1->Focus();
            textBox1->SelectAll();
            return false;
        }

        array<String^>^ nameWords = nameInput->Split(' ');
        int nameWordCount = 0;
        for each (String ^ word in nameWords) {
            if (!String::IsNullOrWhiteSpace(word))
                nameWordCount++;
        }

        if (nameWordCount < 2) {
            MessageBox::Show("Введите имя и фамилию через пробел (например: Иван Иванов).",
                "Ошибка проверки", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox1->Focus();
            textBox1->SelectAll();
            return false;
        }

        String^ addressInput = textBox2->Text->Trim();
        if (String::IsNullOrEmpty(addressInput)) {
            MessageBox::Show("Пожалуйста, заполните поле 'Адрес жильца'.",
                "Ошибка проверки", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox2->Focus();
            return false;
        }

        if (!IsValidAddress(addressInput)) {
            MessageBox::Show("Адрес должен содержать название улицы и номер дома через пробел.\nПример: Пионерская 30",
                "Ошибка проверки", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox2->Focus();
            textBox2->SelectAll();
            return false;
        }

        String^ costInput = textBox3->Text->Trim();
        if (String::IsNullOrEmpty(costInput)) {
            MessageBox::Show("Пожалуйста, заполните поле 'Стоимость услуг'.",
                "Ошибка проверки", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox3->Focus();
            return false;
        }

        double cost;
        if (!Double::TryParse(costInput->Replace(",", "."), System::Globalization::NumberStyles::Any,
            System::Globalization::CultureInfo::InvariantCulture, cost)) {
            MessageBox::Show("Введите корректное число в поле 'Стоимость услуг'.",
                "Ошибка проверки", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox3->Focus();
            textBox3->SelectAll();
            return false;
        }

        if (cost <= 0 || cost > 1000000) {
            MessageBox::Show("Стоимость услуг должна быть от 0.01 до 1 000 000.",
                "Ошибка проверки", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox3->Focus();
            textBox3->SelectAll();
            return false;
        }

        int benefitValue = (int)numericUpDown1->Value;
        if (benefitValue < 1 || benefitValue > 100) {
            MessageBox::Show("Размер льготы должен быть от 1 до 100.",
                "Ошибка проверки", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            numericUpDown1->Focus();
            return false;
        }

        String^ benefitTypeInput = maskedTextBox1->Text->Trim();
        if (String::IsNullOrEmpty(benefitTypeInput)) {
            MessageBox::Show("Пожалуйста, заполните поле 'Тип льготы'.",
                "Ошибка проверки", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            maskedTextBox1->Focus();
            return false;
        }

        if (!ContainsOnlyLettersAndSpaces(benefitTypeInput)) {
            MessageBox::Show("Тип льготы может содержать только буквы и пробелы.",
                "Ошибка проверки", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            maskedTextBox1->Focus();
            maskedTextBox1->SelectAll();
            return false;
        }

        return true;
    }

    void MyForm3::SaveDataToFile() {
        try {
            if (!ValidateAllFields()) {
                return;
            }

            String^ name = textBox1->Text->Trim();
            String^ address = textBox2->Text->Trim();
            String^ cost = textBox3->Text->Trim();
            String^ benefitPercent = numericUpDown1->Value.ToString();
            String^ benefitType = maskedTextBox1->Text->Trim();

            String^ dataLine = String::Format("{0}|{1}|{2}|{3}|{4}",
                name, address, cost, benefitPercent, benefitType);

            String^ filePath = "residents_data.txt";

            StreamWriter^ writer = gcnew StreamWriter(filePath, true);
            writer->WriteLine(dataLine);
            writer->Close();

            MessageBox::Show("Данные успешно сохранены в файл!", "Успех",
                MessageBoxButtons::OK, MessageBoxIcon::Information);

            ClearFormFields();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Ошибка при сохранении данных: " + ex->Message,
                "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    void MyForm3::ClearFormFields() {
        textBox1->Clear();
        textBox2->Clear();
        textBox3->Clear();
        numericUpDown1->Value = 1;
        maskedTextBox1->Clear();
        textBox1->Focus();
    }

    array<String^>^ MyForm3::ReadDataFromFile() {
        try {
            String^ filePath = "residents_data.txt";

            if (!File::Exists(filePath)) {
                return gcnew array<String^>(0);
            }

            array<String^>^ lines = File::ReadAllLines(filePath);
            return lines;
        }
        catch (Exception^ ex) {
            MessageBox::Show("Ошибка при чтении данных: " + ex->Message,
                "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return gcnew array<String^>(0);
        }
    }

    int MyForm3::GetRecordsCount() {
        array<String^>^ records = ReadDataFromFile();
        return records->Length;
    }

    array<String^>^ MyForm3::ParseDataLine(String^ dataLine) {
        return dataLine->Split('|');
    }


    System::Void MyForm3::MyForm3_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
        isClosing = true;
    }

    System::Void MyForm3::MyForm3_Load(System::Object^ sender, System::EventArgs^ e) {
        isClosing = false;
    }

    System::Void MyForm3::button1_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }

    System::Void MyForm3::buttonValidate_Click(System::Object^ sender, System::EventArgs^ e) {
        ValidateNameInput();
    }

    System::Void MyForm3::textBox1_Leave(System::Object^ sender, System::EventArgs^ e) {
        ValidateNameInput();
    }

    System::Void MyForm3::textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
        if (e->KeyChar == (char)8) {
            e->Handled = false;
            return;
        }

        wchar_t c = e->KeyChar;
        if (!(IsRussianLetter(c) || IsEnglishLetter(c) || c == L' ')) {
            e->Handled = true;
            System::Media::SystemSounds::Beep->Play();
        }
    }

    System::Void MyForm3::textBox2_Leave(System::Object^ sender, System::EventArgs^ e) {
        ValidateAddressInput();
    }

    System::Void MyForm3::textBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
        if (e->KeyChar == (char)8) {
            e->Handled = false;
            return;
        }

        wchar_t c = e->KeyChar;
        if (!(IsRussianLetter(c) || IsEnglishLetter(c) || c == L' ' || (c >= L'0' && c <= L'9'))) {
            e->Handled = true;
            System::Media::SystemSounds::Beep->Play();
        }
    }

    System::Void MyForm3::textBox3_Leave(System::Object^ sender, System::EventArgs^ e) {
        ValidateCostInput();
    }

    System::Void MyForm3::textBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
        if (e->KeyChar == (char)8) {
            e->Handled = false;
            return;
        }

        wchar_t c = e->KeyChar;
        bool isDigit = (c >= L'0' && c <= L'9');
        bool isDot = (c == L'.');
        bool isComma = (c == L',');

        if (!(isDigit || isDot || isComma)) {
            e->Handled = true;
            System::Media::SystemSounds::Beep->Play();
            return;
        }

        if (isDot || isComma) {
            String^ currentText = textBox3->Text;

            if (currentText->Contains(".") || currentText->Contains(",")) {
                e->Handled = true;
                System::Media::SystemSounds::Beep->Play();
                return;
            }

            if (currentText->Length == 0) {
                e->Handled = true;
                System::Media::SystemSounds::Beep->Play();
                return;
            }

            if (isComma) {
                e->KeyChar = L'.';
            }
        }

        String^ currentText = textBox3->Text;
        if (currentText->Length >= 15) {
            e->Handled = true;
            System::Media::SystemSounds::Beep->Play();
        }
    }

    System::Void MyForm3::textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        String^ text = textBox3->Text;

        if (text->Contains(",")) {
            textBox3->Text = text->Replace(",", ".");
            textBox3->SelectionStart = textBox3->Text->Length;
        }

        array<String^>^ parts = text->Split('.');
        if (parts->Length > 0 && parts[0]->Length > 7) {
            if (parts[0]->Length > 7) {
                textBox3->Text = parts[0]->Substring(0, 7) + (parts->Length > 1 ? "." + parts[1] : "");
                textBox3->SelectionStart = textBox3->Text->Length;
            }
        }
    }

    System::Void MyForm3::numericUpDown1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
        int value = (int)numericUpDown1->Value;
        if (value < 1)
            numericUpDown1->Value = 1;
        if (value > 100)
            numericUpDown1->Value = 100;
    }

    System::Void MyForm3::numericUpDown1_Leave(System::Object^ sender, System::EventArgs^ e) {
        ValidateBenefitInput();
    }

    System::Void MyForm3::numericUpDown1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
        if (!(e->KeyChar >= '0' && e->KeyChar <= '9') && e->KeyChar != (char)8) {
            e->Handled = true;
            System::Media::SystemSounds::Beep->Play();
        }
    }

    System::Void MyForm3::maskedTextBox1_Leave(System::Object^ sender, System::EventArgs^ e) {
        ValidateBenefitTypeInput();
    }

    System::Void MyForm3::maskedTextBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
        if (e->KeyChar == (char)8) {
            e->Handled = false;
            return;
        }

        wchar_t c = e->KeyChar;
        if (!(IsRussianLetter(c) || IsEnglishLetter(c) || c == L' ')) {
            e->Handled = true;
            System::Media::SystemSounds::Beep->Play();
        }
    }

    System::Void MyForm3::buttonSave_Click(System::Object^ sender, System::EventArgs^ e) {
        SaveDataToFile();
    }
}

//методы MyForm4
namespace WinForms {
    void MyForm4::CenterForm() {
        this->StartPosition = FormStartPosition::CenterScreen;
    }

    bool MyForm4::ContainsOnlyLettersAndSpaces(String^ text) {
        if (String::IsNullOrEmpty(text))
            return false;

        for each (wchar_t c in text) {
            if (!(IsRussianLetter(c) || IsEnglishLetter(c) || c == L' ')) {
                return false;
            }
        }
        return true;
    }

    bool MyForm4::IsRussianLetter(wchar_t c) {
        return (c >= L'А' && c <= L'я') || c == L'ё' || c == L'Ё';
    }

    bool MyForm4::IsEnglishLetter(wchar_t c) {
        return (c >= L'A' && c <= L'Z') || (c >= L'a' && c <= L'z');
    }

    bool MyForm4::IsValidAddress(String^ text) {
        if (String::IsNullOrEmpty(text))
            return false;

        array<String^>^ parts = text->Split(' ');
        if (parts->Length < 2)
            return false;

        String^ lastPart = parts[parts->Length - 1];
        int houseNumber;
        bool isNumber = Int32::TryParse(lastPart, houseNumber);

        if (!isNumber || houseNumber <= 0)
            return false;

        for (int i = 0; i < parts->Length - 1; i++) {
            if (!ContainsOnlyLettersAndSpaces(parts[i]))
                return false;
        }

        return true;
    }

    void MyForm4::ValidateNameInput() {
        if (isClosing) return;
        String^ input = textBox1->Text->Trim();

        if (String::IsNullOrEmpty(input)) {
            MessageBox::Show("Ошибка! Ввод не может быть пустым.", "Ошибка ввода",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox1->Focus();
            return;
        }

        if (!ContainsOnlyLettersAndSpaces(input)) {
            MessageBox::Show("Ошибка! Имя может содержать только буквы (русские или английские) и пробелы.",
                "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox1->Focus();
            textBox1->SelectAll();
            return;
        }

        array<String^>^ words = input->Split(' ');
        int wordCount = 0;

        for each (String ^ word in words) {
            if (!String::IsNullOrWhiteSpace(word))
                wordCount++;
        }

        if (wordCount < 2) {
            MessageBox::Show("Ошибка! Введите имя и фамилию через пробел (например: Иван Иванов).",
                "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox1->Focus();
            textBox1->SelectAll();
            return;
        }

        MessageBox::Show("Имя введено корректно!", "Успех",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    void MyForm4::ValidateAddressInput() {
        if (isClosing) return;
        String^ input = textBox2->Text->Trim();

        if (String::IsNullOrEmpty(input)) {
            MessageBox::Show("Ошибка! Адрес не может быть пустым.", "Ошибка ввода",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox2->Focus();
            return;
        }

        if (!IsValidAddress(input)) {
            MessageBox::Show("Ошибка! Адрес должен содержать название улицы и номер дома через пробел.\nПример: Пионерская 30 или Lenina 15",
                "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox2->Focus();
            textBox2->SelectAll();
            return;
        }

        MessageBox::Show("Адрес введен корректно!", "Успех",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    void MyForm4::ValidateCostInput() {
        if (isClosing) return;
        String^ input = textBox3->Text->Trim();

        if (String::IsNullOrEmpty(input)) {
            MessageBox::Show("Ошибка! Стоимость услуг не может быть пустой.", "Ошибка ввода",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox3->Focus();
            return;
        }

        input = input->Replace(",", ".");

        double cost;
        bool isNumber = Double::TryParse(input, System::Globalization::NumberStyles::Any,
            System::Globalization::CultureInfo::InvariantCulture, cost);

        if (!isNumber) {
            MessageBox::Show("Ошибка! Введите корректное число.",
                "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox3->Focus();
            textBox3->SelectAll();
            return;
        }

        if (cost <= 0) {
            MessageBox::Show("Ошибка! Стоимость услуг должна быть положительным числом.",
                "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox3->Focus();
            textBox3->SelectAll();
            return;
        }

        if (cost > 1000000) {
            MessageBox::Show("Ошибка! Стоимость услуг не может превышать 1 000 000.",
                "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox3->Focus();
            textBox3->SelectAll();
            return;
        }

        array<String^>^ parts = input->Split('.');
        if (parts->Length > 1 && parts[1]->Length > 6) {
            MessageBox::Show("Ошибка! Максимальное количество знаков после точки - 6.",
                "Ошибка ввода", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox3->Focus();
            textBox3->SelectAll();
            return;
        }

        textBox3->Text = cost.ToString("F2", System::Globalization::CultureInfo::InvariantCulture);

        MessageBox::Show("Стоимость введена корректно!", "Успех",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    bool MyForm4::ValidateAllFields() {
        String^ nameInput = textBox1->Text->Trim();
        if (String::IsNullOrEmpty(nameInput)) {
            MessageBox::Show("Пожалуйста, заполните поле 'Имя жильца'.",
                "Ошибка проверки", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox1->Focus();
            return false;
        }

        if (!ContainsOnlyLettersAndSpaces(nameInput)) {
            MessageBox::Show("Имя может содержать только буквы и пробелы.",
                "Ошибка проверки", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox1->Focus();
            textBox1->SelectAll();
            return false;
        }

        array<String^>^ nameWords = nameInput->Split(' ');
        int nameWordCount = 0;
        for each (String ^ word in nameWords) {
            if (!String::IsNullOrWhiteSpace(word))
                nameWordCount++;
        }

        if (nameWordCount < 2) {
            MessageBox::Show("Введите имя и фамилию через пробел (например: Иван Иванов).",
                "Ошибка проверки", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox1->Focus();
            textBox1->SelectAll();
            return false;
        }

        String^ addressInput = textBox2->Text->Trim();
        if (String::IsNullOrEmpty(addressInput)) {
            MessageBox::Show("Пожалуйста, заполните поле 'Адрес жильца'.",
                "Ошибка проверки", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox2->Focus();
            return false;
        }

        if (!IsValidAddress(addressInput)) {
            MessageBox::Show("Адрес должен содержать название улицы и номер дома через пробел.\nПример: Пионерская 30",
                "Ошибка проверки", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox2->Focus();
            textBox2->SelectAll();
            return false;
        }

        String^ costInput = textBox3->Text->Trim();
        if (String::IsNullOrEmpty(costInput)) {
            MessageBox::Show("Пожалуйста, заполните поле 'Стоимость услуг'.",
                "Ошибка проверки", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox3->Focus();
            return false;
        }

        double cost;
        if (!Double::TryParse(costInput->Replace(",", "."), System::Globalization::NumberStyles::Any,
            System::Globalization::CultureInfo::InvariantCulture, cost)) {
            MessageBox::Show("Введите корректное число в поле 'Стоимость услуг'.",
                "Ошибка проверки", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox3->Focus();
            textBox3->SelectAll();
            return false;
        }

        if (cost <= 0 || cost > 1000000) {
            MessageBox::Show("Стоимость услуг должна быть от 0.01 до 1 000 000.",
                "Ошибка проверки", MessageBoxButtons::OK, MessageBoxIcon::Warning);
            textBox3->Focus();
            textBox3->SelectAll();
            return false;
        }

        return true;
    }

    void MyForm4::SaveDataToFile() {
        try {
            if (!ValidateAllFields()) {
                return;
            }

            String^ name = textBox1->Text->Trim();
            String^ address = textBox2->Text->Trim();
            String^ cost = textBox3->Text->Trim();
            String^ benefitPercent = "0";
            String^ benefitType = "Нет льготы";

            String^ dataLine = String::Format("{0}|{1}|{2}|{3}|{4}",
                name, address, cost, benefitPercent, benefitType);

            String^ filePath = "residents_data.txt";

            StreamWriter^ writer = gcnew StreamWriter(filePath, true);
            writer->WriteLine(dataLine);
            writer->Close();

            MessageBox::Show("Данные успешно сохранены в файл!", "Успех",
                MessageBoxButtons::OK, MessageBoxIcon::Information);

            ClearFormFields();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Ошибка при сохранении данных: " + ex->Message,
                "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    void MyForm4::ClearFormFields() {
        textBox1->Clear();
        textBox2->Clear();
        textBox3->Clear();
        textBox1->Focus();
    }

   
    System::Void MyForm4::label1_Click(System::Object^ sender, System::EventArgs^ e) {
    }

    System::Void MyForm4::buttonBack_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }

    System::Void MyForm4::buttonSave_Click(System::Object^ sender, System::EventArgs^ e) {
        SaveDataToFile();
    }

    System::Void MyForm4::textBox1_Leave(System::Object^ sender, System::EventArgs^ e) {
        ValidateNameInput();
    }

    System::Void MyForm4::textBox2_Leave(System::Object^ sender, System::EventArgs^ e) {
        ValidateAddressInput();
    }

    System::Void MyForm4::textBox3_Leave(System::Object^ sender, System::EventArgs^ e) {
        ValidateCostInput();
    }

    System::Void MyForm4::textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
        if (e->KeyChar == (char)8) {
            e->Handled = false;
            return;
        }

        wchar_t c = e->KeyChar;
        if (!(IsRussianLetter(c) || IsEnglishLetter(c) || c == L' ')) {
            e->Handled = true;
            System::Media::SystemSounds::Beep->Play();
        }
    }

    System::Void MyForm4::textBox2_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
        if (e->KeyChar == (char)8) {
            e->Handled = false;
            return;
        }

        wchar_t c = e->KeyChar;
        if (!(IsRussianLetter(c) || IsEnglishLetter(c) || c == L' ' || (c >= L'0' && c <= L'9'))) {
            e->Handled = true;
            System::Media::SystemSounds::Beep->Play();
        }
    }

    System::Void MyForm4::textBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
        if (e->KeyChar == (char)8) {
            e->Handled = false;
            return;
        }

        wchar_t c = e->KeyChar;
        bool isDigit = (c >= L'0' && c <= L'9');
        bool isDot = (c == L'.');
        bool isComma = (c == L',');

        if (!(isDigit || isDot || isComma)) {
            e->Handled = true;
            System::Media::SystemSounds::Beep->Play();
            return;
        }

        if (isDot || isComma) {
            String^ currentText = textBox3->Text;

            if (currentText->Contains(".") || currentText->Contains(",")) {
                e->Handled = true;
                System::Media::SystemSounds::Beep->Play();
                return;
            }

            if (currentText->Length == 0) {
                e->Handled = true;
                System::Media::SystemSounds::Beep->Play();
                return;
            }

            if (isComma) {
                e->KeyChar = L'.';
            }
        }

        String^ currentText = textBox3->Text;
        if (currentText->Length >= 15) {
            e->Handled = true;
            System::Media::SystemSounds::Beep->Play();
        }
    }

    System::Void MyForm4::textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        String^ text = textBox3->Text;

        if (text->Contains(",")) {
            textBox3->Text = text->Replace(",", ".");
            textBox3->SelectionStart = textBox3->Text->Length;
        }

        array<String^>^ parts = text->Split('.');
        if (parts->Length > 0 && parts[0]->Length > 7) {
            if (parts[0]->Length > 7) {
                textBox3->Text = parts[0]->Substring(0, 7) + (parts->Length > 1 ? "." + parts[1] : "");
                textBox3->SelectionStart = textBox3->Text->Length;
            }
        }
    }

    System::Void MyForm4::MyForm4_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
        isClosing = true;
    }

    System::Void MyForm4::MyForm4_Load(System::Object^ sender, System::EventArgs^ e) {
        isClosing = false;
    }
}

//методы MyForm5
namespace WinForms {
    void MyForm5::CenterForm() {
        this->StartPosition = FormStartPosition::CenterScreen;
    }

    array<String^>^ MyForm5::ReadDataFromFile() {
        try {
            String^ filePath = "residents_data.txt";

            if (!File::Exists(filePath)) {
                return gcnew array<String^>(0);
            }

            array<String^>^ lines = File::ReadAllLines(filePath);
            return lines;
        }
        catch (Exception^ ex) {
            MessageBox::Show("Ошибка при чтении данных: " + ex->Message,
                "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return gcnew array<String^>(0);
        }
    }

    void MyForm5::WriteDataToFile(Collections::Generic::List<array<String^>^>^ residents) {
        try {
            String^ filePath = "residents_data.txt";
            StreamWriter^ writer = gcnew StreamWriter(filePath, false);

            for each (array<String^> ^ resident in residents) {
                if (resident->Length >= 5) {
                    String^ dataLine = String::Format("{0}|{1}|{2}|{3}|{4}",
                        resident[0], resident[1], resident[2], resident[3], resident[4]);
                    writer->WriteLine(dataLine);
                }
            }

            writer->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Ошибка при сохранении данных: " + ex->Message,
                "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    array<String^>^ MyForm5::ParseDataLine(String^ dataLine) {
        return dataLine->Split('|');
    }

    int MyForm5::CompareByBenefitPercent(array<String^>^ x, array<String^>^ y) {
        int percentX, percentY;
        if (Int32::TryParse(x[3], percentX) && Int32::TryParse(y[3], percentY)) {
            return percentY.CompareTo(percentX);
        }
        return 0;
    }

    void MyForm5::LoadResidentsData() {
        try {
            
            dataGridViewResidents->Rows->Clear();
            dataGridViewResidents->Columns->Clear();
            allResidents = gcnew Collections::Generic::List<array<String^>^>();

            dataGridViewResidents->Columns->Add("Number", "№");
            dataGridViewResidents->Columns->Add("Name", "Имя жильца");
            dataGridViewResidents->Columns->Add("Address", "Адрес");
            dataGridViewResidents->Columns->Add("Cost", "Стоимость услуг (руб.)");
            dataGridViewResidents->Columns->Add("BenefitPercent", "Размер льготы (%)");
            dataGridViewResidents->Columns->Add("BenefitType", "Тип льготы");

            dataGridViewResidents->Columns["Number"]->Width = 50;
            dataGridViewResidents->Columns["Name"]->Width = 200;
            dataGridViewResidents->Columns["Address"]->Width = 150;
            dataGridViewResidents->Columns["Cost"]->Width = 120;
            dataGridViewResidents->Columns["BenefitPercent"]->Width = 100;
            dataGridViewResidents->Columns["BenefitType"]->Width = 150;

            array<String^>^ records = ReadDataFromFile();

            if (records->Length == 0) {
                
                dataGridViewResidents->Rows->Add("", "Нет данных о жильцах", "", "", "", "");
                return;
            }

            Collections::Generic::List<array<String^>^>^ withBenefits = gcnew Collections::Generic::List<array<String^>^>();
            Collections::Generic::List<array<String^>^>^ withoutBenefits = gcnew Collections::Generic::List<array<String^>^>();

            for each (String ^ record in records) {
                if (!String::IsNullOrEmpty(record)) {
                    array<String^>^ data = ParseDataLine(record);

                    if (data->Length >= 5) {
                        String^ benefitPercent = data[3];
                        String^ benefitType = data[4];

                        int percent;
                        if (Int32::TryParse(benefitPercent, percent) && percent > 0 && benefitType != "Нет льготы") {
                            withBenefits->Add(data);
                        }
                        else {
                            withoutBenefits->Add(data);
                        }

                        allResidents->Add(data);
                    }
                }
            }

            if (withBenefits->Count > 0) {
                withBenefits->Sort(gcnew Comparison<array<String^>^>(&MyForm5::CompareByBenefitPercent));
            }

            int totalCount = 0;

            if (withBenefits->Count > 0) {
                int count = 0;
                for each (array<String^> ^ data in withBenefits) {
                    count++;
                    totalCount++;
                    dataGridViewResidents->Rows->Add(
                        count.ToString(),
                        data[0],
                        data[1],
                        data[2],
                        data[3],
                        data[4]
                    );
                }
            }

            if (withoutBenefits->Count > 0) {
                int count = withBenefits->Count;
                for each (array<String^> ^ data in withoutBenefits) {
                    count++;
                    totalCount++;
                    dataGridViewResidents->Rows->Add(
                        count.ToString(),
                        data[0],
                        data[1],
                        data[2],
                        "0",
                        "Без льготы"
                    );
                }
            }

            dataGridViewResidents->Rows->Add("", "СТАТИСТИКА:", "", "", "", "");
            dataGridViewResidents->Rows->Add("", "Всего жильцов: " + totalCount.ToString(), "", "", "", "");
            dataGridViewResidents->Rows->Add("", "Со льготами: " + withBenefits->Count.ToString(), "", "", "", "");
            dataGridViewResidents->Rows->Add("", "Без льгот: " + withoutBenefits->Count.ToString(), "", "", "", "");

        }
        catch (Exception^ ex) {
            dataGridViewResidents->Rows->Add("", "Ошибка при загрузке данных: " + ex->Message, "", "", "", "");
        }
    }

    array<String^>^ MyForm5::GetSelectedResident() {
        if (dataGridViewResidents->SelectedRows->Count == 0) {
            MessageBox::Show("Пожалуйста, выберите жильца из таблицы", "Внимание",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return nullptr;
        }

        DataGridViewRow^ selectedRow = dataGridViewResidents->SelectedRows[0];

        if (selectedRow->Cells["Name"]->Value == nullptr ||
            selectedRow->Cells["Name"]->Value->ToString()->Contains("СТАТИСТИКА") ||
            selectedRow->Cells["Name"]->Value->ToString()->Contains("Всего жильцов") ||
            selectedRow->Cells["Name"]->Value->ToString()->Contains("Со льготами") ||
            selectedRow->Cells["Name"]->Value->ToString()->Contains("Без льгот") ||
            selectedRow->Cells["Name"]->Value->ToString()->Contains("Нет данных")) {
            MessageBox::Show("Пожалуйста, выберите конкретного жильца, а не статистическую строку", "Внимание",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return nullptr;
        }

        String^ name = selectedRow->Cells["Name"]->Value->ToString();
        String^ address = selectedRow->Cells["Address"]->Value->ToString();

        for each (array<String^> ^ resident in allResidents) {
            if (resident->Length >= 2 && resident[0] == name && resident[1] == address) {
                return resident;
            }
        }

        MessageBox::Show("Не удалось определить выбранного жильца", "Ошибка",
            MessageBoxButtons::OK, MessageBoxIcon::Error);
        return nullptr;
    }

    void MyForm5::DeleteResident(array<String^>^ residentToDelete) {
        if (residentToDelete == nullptr) return;

        String^ message = String::Format("Вы уверены, что хотите удалить жильца:\n{0}\n{1}?",
            residentToDelete[0], residentToDelete[1]);

        System::Windows::Forms::DialogResult result = MessageBox::Show(message, "Подтверждение удаления",
            System::Windows::Forms::MessageBoxButtons::YesNo,
            System::Windows::Forms::MessageBoxIcon::Question);

        if (result == System::Windows::Forms::DialogResult::Yes) {
            allResidents->Remove(residentToDelete);
            WriteDataToFile(allResidents);
            LoadResidentsData();

            MessageBox::Show("Жилец успешно удален", "Успех",
                System::Windows::Forms::MessageBoxButtons::OK,
                System::Windows::Forms::MessageBoxIcon::Information);
        }
    }

    void MyForm5::EditResident(array<String^>^ residentToEdit) {
        if (residentToEdit == nullptr) return;

        Form^ editForm = gcnew Form();
        editForm->Text = "Редактирование жильца";
        editForm->Size = Drawing::Size(500, 400);
        editForm->StartPosition = FormStartPosition::CenterParent;
        editForm->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
        editForm->MaximizeBox = false;
        editForm->MinimizeBox = false;

        Label^ lblName = gcnew Label();
        lblName->Text = "Имя:";
        lblName->Location = Drawing::Point(20, 20);
        lblName->Size = Drawing::Size(100, 20);

        TextBox^ txtName = gcnew TextBox();
        txtName->Text = residentToEdit[0];
        txtName->Location = Drawing::Point(120, 20);
        txtName->Size = Drawing::Size(300, 20);

        Label^ lblAddress = gcnew Label();
        lblAddress->Text = "Адрес:";
        lblAddress->Location = Drawing::Point(20, 60);
        lblAddress->Size = Drawing::Size(100, 20);

        TextBox^ txtAddress = gcnew TextBox();
        txtAddress->Text = residentToEdit[1];
        txtAddress->Location = Drawing::Point(120, 60);
        txtAddress->Size = Drawing::Size(300, 20);

        Label^ lblCost = gcnew Label();
        lblCost->Text = "Стоимость:";
        lblCost->Location = Drawing::Point(20, 100);
        lblCost->Size = Drawing::Size(100, 20);

        TextBox^ txtCost = gcnew TextBox();
        txtCost->Text = residentToEdit[2];
        txtCost->Location = Drawing::Point(120, 100);
        txtCost->Size = Drawing::Size(300, 20);

        Label^ lblBenefitPercent = gcnew Label();
        lblBenefitPercent->Text = "Льгота (%):";
        lblBenefitPercent->Location = Drawing::Point(20, 140);
        lblBenefitPercent->Size = Drawing::Size(100, 20);

        TextBox^ txtBenefitPercent = gcnew TextBox();
        txtBenefitPercent->Text = residentToEdit[3];
        txtBenefitPercent->Location = Drawing::Point(120, 140);
        txtBenefitPercent->Size = Drawing::Size(300, 20);

        Label^ lblBenefitType = gcnew Label();
        lblBenefitType->Text = "Тип льготы:";
        lblBenefitType->Location = Drawing::Point(20, 180);
        lblBenefitType->Size = Drawing::Size(100, 20);

        TextBox^ txtBenefitType = gcnew TextBox();
        txtBenefitType->Text = residentToEdit[4];
        txtBenefitType->Location = Drawing::Point(120, 180);
        txtBenefitType->Size = Drawing::Size(300, 20);

        Button^ btnSave = gcnew Button();
        btnSave->Text = "Сохранить";
        btnSave->Location = Drawing::Point(120, 240);
        btnSave->Size = Drawing::Size(100, 30);
        btnSave->DialogResult = System::Windows::Forms::DialogResult::OK;

        Button^ btnCancel = gcnew Button();
        btnCancel->Text = "Отмена";
        btnCancel->Location = Drawing::Point(240, 240);
        btnCancel->Size = Drawing::Size(100, 30);
        btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;

        editForm->Controls->AddRange(gcnew array<Control^> {
            lblName, txtName, lblAddress, txtAddress, lblCost, txtCost,
                lblBenefitPercent, txtBenefitPercent, lblBenefitType, txtBenefitType,
                btnSave, btnCancel
        });

        editForm->AcceptButton = btnSave;
        editForm->CancelButton = btnCancel;

       
        if (editForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            
            residentToEdit[0] = txtName->Text;
            residentToEdit[1] = txtAddress->Text;
            residentToEdit[2] = txtCost->Text;
            residentToEdit[3] = txtBenefitPercent->Text;
            residentToEdit[4] = txtBenefitType->Text;

            WriteDataToFile(allResidents);
            LoadResidentsData();

            MessageBox::Show("Данные жильца успешно обновлены", "Успех",
                System::Windows::Forms::MessageBoxButtons::OK,
                System::Windows::Forms::MessageBoxIcon::Information);
        }

        delete editForm;
    }
    System::Void MyForm5::buttonExit_Click(System::Object^ sender, System::EventArgs^ e) {
        if (form1 != nullptr) {
            form1->Show();
            form1->StartPosition = FormStartPosition::CenterScreen;
        }
        this->Close();
    }

    System::Void MyForm5::buttonRefresh_Click(System::Object^ sender, System::EventArgs^ e) {
        LoadResidentsData();
        MessageBox::Show("Данные обновлены!", "Обновление",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }

    System::Void MyForm5::buttonEdit_Click(System::Object^ sender, System::EventArgs^ e) {
        array<String^>^ selectedResident = GetSelectedResident();
        if (selectedResident != nullptr) {
            EditResident(selectedResident);
        }
    }

    System::Void MyForm5::buttonDelete_Click(System::Object^ sender, System::EventArgs^ e) {
        array<String^>^ selectedResident = GetSelectedResident();
        if (selectedResident != nullptr) {
            DeleteResident(selectedResident);
        }
    }
}

//методы MyForm6
namespace WinForms {
    void MyForm6::CenterForm() {
        this->StartPosition = FormStartPosition::CenterScreen;
    }

    array<String^>^ MyForm6::ReadDataFromFile() {
        try {
            String^ filePath = "residents_data.txt";

            if (!File::Exists(filePath)) {
                return gcnew array<String^>(0);
            }

            array<String^>^ lines = File::ReadAllLines(filePath);
            return lines;
        }
        catch (Exception^ ex) {
            MessageBox::Show("Ошибка при чтении данных: " + ex->Message,
                "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return gcnew array<String^>(0);
        }
    }

    array<String^>^ MyForm6::ParseDataLine(String^ dataLine) {
        return dataLine->Split('|');
    }

    void MyForm6::CalculateTotalCost() {
        try {
            array<String^>^ records = ReadDataFromFile();

            if (records->Length == 0) {
                labelTotalCost->Text = "Нет данных о жильцах";
                return;
            }

            double totalCost = 0.0;
            double totalCostWithBenefits = 0.0;
            double totalDiscount = 0.0;
            int residentCount = 0;
            int residentsWithBenefits = 0;

            for each (String ^ record in records) {
                if (!String::IsNullOrEmpty(record)) {
                    array<String^>^ data = ParseDataLine(record);

                    if (data->Length >= 5) {
                        residentCount++;

                        String^ costStr = data[2];
                        String^ benefitPercentStr = data[3];
                        String^ benefitType = data[4];

                        double cost;
                        if (Double::TryParse(costStr->Replace(",", "."),
                            System::Globalization::NumberStyles::Any,
                            System::Globalization::CultureInfo::InvariantCulture, cost)) {
                            totalCost += cost;

                            int benefitPercent;
                            if (Int32::TryParse(benefitPercentStr, benefitPercent) &&
                                benefitPercent > 0 && benefitType != "Нет льготы") {
                                residentsWithBenefits++;
                                double discount = cost * benefitPercent / 100.0;
                                double costWithBenefit = cost - discount;
                                totalCostWithBenefits += costWithBenefit;
                                totalDiscount += discount;
                            }
                            else {
                                totalCostWithBenefits += cost;
                            }
                        }
                    }
                }
            }

            labelTotalCost->Text = String::Format("Общая стоимость: {0:F2} руб.", totalCost);
            labelCostWithBenefits->Text = String::Format("Стоимость с учетом льгот: {0:F2} руб.", totalCostWithBenefits);
            labelDiscount->Text = String::Format("Общая сумма льгот: {0:F2} руб.", totalDiscount);
            labelResidentsCount->Text = String::Format("Количество жильцов: {0}", residentCount);
            labelResidentsWithBenefits->Text = String::Format("Из них со льготами: {0}", residentsWithBenefits);

        }
        catch (Exception^ ex) {
            labelTotalCost->Text = "Ошибка при расчете стоимости";
        }
    }

    System::Void MyForm6::buttonExit_Click(System::Object^ sender, System::EventArgs^ e) {
        if (form1 != nullptr) {
            form1->Show();
            form1->StartPosition = FormStartPosition::CenterScreen;
        }
        this->Close();
    }

    System::Void MyForm6::buttonRefresh_Click(System::Object^ sender, System::EventArgs^ e) {
        CalculateTotalCost();
        MessageBox::Show("Данные обновлены!", "Обновление",
            MessageBoxButtons::OK, MessageBoxIcon::Information);
    }
}
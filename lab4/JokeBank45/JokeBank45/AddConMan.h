#pragma once
#include "Contributor.h"
#include "DataManager.h"
//#include <msclr\marshal_cppstd.h>
namespace JokeBank45 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AddConMan
	/// </summary>
	public ref class AddConMan : public System::Windows::Forms::Form
	{
	public:
		//event System::EventHandler^ ContributorAdded;

		AddConMan(void)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
			this->Size = System::Drawing::Size(1000, 800);
			SetupValidation();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddConMan()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ LabAddCon;
	private: System::Windows::Forms::TextBox^ textName;
	private: System::Windows::Forms::TextBox^ textAge;

	private: System::Windows::Forms::Label^ labName;
	private: System::Windows::Forms::Label^ labAge;
	private: System::Windows::Forms::Button^ BackBut4;
	private: System::Windows::Forms::Button^ Acc4;


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
			this->LabAddCon = (gcnew System::Windows::Forms::Label());
			this->textName = (gcnew System::Windows::Forms::TextBox());
			this->textAge = (gcnew System::Windows::Forms::TextBox());
			this->labName = (gcnew System::Windows::Forms::Label());
			this->labAge = (gcnew System::Windows::Forms::Label());
			this->BackBut4 = (gcnew System::Windows::Forms::Button());
			this->Acc4 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// LabAddCon
			// 
			this->LabAddCon->AutoSize = true;
			this->LabAddCon->Font = (gcnew System::Drawing::Font(L"Times New Roman", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabAddCon->ForeColor = System::Drawing::SystemColors::Control;
			this->LabAddCon->Location = System::Drawing::Point(273, 159);
			this->LabAddCon->Name = L"LabAddCon";
			this->LabAddCon->Size = System::Drawing::Size(485, 73);
			this->LabAddCon->TabIndex = 10;
			this->LabAddCon->Text = L"Add a contributor";
			this->LabAddCon->Click += gcnew System::EventHandler(this, &AddConMan::LabAddCon_Click);
			// 
			// textName
			// 
			this->textName->Font = (gcnew System::Drawing::Font(L"Times New Roman", 26.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textName->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->textName->Location = System::Drawing::Point(267, 290);
			this->textName->Name = L"textName";
			this->textName->Size = System::Drawing::Size(508, 48);
			this->textName->TabIndex = 11;
			this->textName->TextChanged += gcnew System::EventHandler(this, &AddConMan::textBoxName_TextChanged);
			// 
			// textAge
			// 
			this->textAge->Font = (gcnew System::Drawing::Font(L"Times New Roman", 26.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textAge->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->textAge->Location = System::Drawing::Point(267, 399);
			this->textAge->Name = L"textAge";
			this->textAge->Size = System::Drawing::Size(508, 48);
			this->textAge->TabIndex = 12;
			this->textAge->TextChanged += gcnew System::EventHandler(this, &AddConMan::textBoxAge_TextChanged);
			// 
			// labName
			// 
			this->labName->AutoSize = true;
			this->labName->Font = (gcnew System::Drawing::Font(L"Times New Roman", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labName->ForeColor = System::Drawing::SystemColors::Control;
			this->labName->Location = System::Drawing::Point(449, 232);
			this->labName->Name = L"labName";
			this->labName->Size = System::Drawing::Size(136, 55);
			this->labName->TabIndex = 13;
			this->labName->Text = L"Name";
			// 
			// labAge
			// 
			this->labAge->AutoSize = true;
			this->labAge->Font = (gcnew System::Drawing::Font(L"Times New Roman", 36, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labAge->Location = System::Drawing::Point(462, 341);
			this->labAge->Name = L"labAge";
			this->labAge->Size = System::Drawing::Size(98, 55);
			this->labAge->TabIndex = 14;
			this->labAge->Text = L"Age";
			// 
			// BackBut4
			// 
			this->BackBut4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 26.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->BackBut4->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->BackBut4->Location = System::Drawing::Point(267, 507);
			this->BackBut4->Name = L"BackBut4";
			this->BackBut4->Size = System::Drawing::Size(508, 48);
			this->BackBut4->TabIndex = 15;
			this->BackBut4->Text = L"Back";
			this->BackBut4->UseVisualStyleBackColor = true;
			this->BackBut4->Click += gcnew System::EventHandler(this, &AddConMan::BackBut4_Click);
			// 
			// Acc4
			// 
			this->Acc4->Font = (gcnew System::Drawing::Font(L"Times New Roman", 26.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Acc4->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->Acc4->Location = System::Drawing::Point(267, 453);
			this->Acc4->Name = L"Acc4";
			this->Acc4->Size = System::Drawing::Size(508, 48);
			this->Acc4->TabIndex = 16;
			this->Acc4->Text = L"Accept";
			this->Acc4->UseVisualStyleBackColor = true;
			this->Acc4->Click += gcnew System::EventHandler(this, &AddConMan::Acc4_Click);
			// 
			// AddConMan
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(19, 40);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(927, 758);
			this->Controls->Add(this->Acc4);
			this->Controls->Add(this->BackBut4);
			this->Controls->Add(this->labAge);
			this->Controls->Add(this->labName);
			this->Controls->Add(this->textAge);
			this->Controls->Add(this->textName);
			this->Controls->Add(this->LabAddCon);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ForeColor = System::Drawing::SystemColors::Control;
			this->Margin = System::Windows::Forms::Padding(10, 9, 10, 9);
			this->Name = L"AddConMan";
			this->Text = L"AddConMan";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void SetupValidation()
		{
			// Изначально подсвечиваем поля как невалидные
			textName->BackColor = Drawing::Color::White;
			textAge->BackColor = Drawing::Color::White;
			textName->MaxLength = 10; // Максимум 10 символов
			textAge->MaxLength = 3;   // Максимум 3 цифры
		}
#pragma endregion
	private:
		// Валидация имени в реальном времени
		void textBoxName_TextChanged(System::Object^ sender, System::EventArgs^ e)
		{
			String^ name = textName->Text;
			bool isValid = !String::IsNullOrEmpty(name) && name->Length >= 2 && name->Length <= 10;

			if (String::IsNullOrEmpty(name)) {
				textName->BackColor = Drawing::Color::White;
			}
			else {
				textName->BackColor = isValid ? Drawing::Color::LightGreen : Drawing::Color::LightPink;
			}
			ValidateForm();
		}

		// Валидация возраста в реальном времени
		void textBoxAge_TextChanged(System::Object^ sender, System::EventArgs^ e)
		{
			String^ ageText = textAge->Text;
			bool isValid = false;

			if (String::IsNullOrEmpty(ageText)) {
				textAge->BackColor = Drawing::Color::White;
				ValidateForm();
				return;
			}

			// Проверяем, что вводятся только цифры
			bool isNumeric = true;
			for each (Char c in ageText) {
				if (!Char::IsDigit(c)) {
					isNumeric = false;
					break;
				}
			}

			if (isNumeric) {
				try {
					int age = Convert::ToInt32(ageText);
					isValid = (age >= 18 && age <= 120);
				}
				catch (FormatException^) {
					isValid = false;
				}
			}

			textAge->BackColor = isValid ? Drawing::Color::LightGreen : Drawing::Color::LightPink;
			ValidateForm();
		}

		// Проверка всей формы
		void ValidateForm()
		{
			bool nameValid = (textName->BackColor == Drawing::Color::LightGreen) ||
				(String::IsNullOrEmpty(textName->Text) && textName->BackColor == Drawing::Color::White);
			bool ageValid = (textAge->BackColor == Drawing::Color::LightGreen) ||
				(String::IsNullOrEmpty(textAge->Text) && textAge->BackColor == Drawing::Color::White);

			// Оба поля должны быть валидными и не пустыми
			bool bothValid = (textName->BackColor == Drawing::Color::LightGreen) &&
				(textAge->BackColor == Drawing::Color::LightGreen);

			// Кнопка активируется только когда оба поля валидны
			Acc4->Enabled = bothValid;

			// Меняем внешний вид кнопки
			if (Acc4->Enabled) {
				Acc4->BackColor = Drawing::Color::White; // Обычный белый фон
				Acc4->ForeColor = Drawing::Color::Black; // Обычный черный текст
			}
			else {
				Acc4->BackColor = Drawing::Color::LightGray; // Серый когда недоступна
				Acc4->ForeColor = Drawing::Color::DarkGray; // Темно-серый текст
			}
		}
	private: System::Void LabAddCon_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void BackBut4_Click(System::Object^ sender, System::EventArgs^ e) {
		for each (Form ^ form in Application::OpenForms) {
			if (form->Name == "MyForm") {
				form->Show();
				break;
			}
		}
		this->Close();
	}
private: System::Void Acc4_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ name = textName->Text;
	int age = Convert::ToInt32(textAge->Text);

	// Добавляем в DataManager
	DataManager::Instance->AddContributor(name, age);

	// Очищаем форму
	textName->Text = "";
	textAge->Text = "";
	SetupValidation();

	// Возвращаемся в главное меню
	for each(Form ^ form in Application::OpenForms) {
		if (form->Name == "MyForm") {
			form->Show();
			break;
		}
	}
	this->Close();
}
 
};

}

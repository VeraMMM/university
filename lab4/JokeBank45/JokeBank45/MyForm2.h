#pragma once
#include "AddConMan.h"
#include "DataManager.h"
#include <msclr\marshal_cppstd.h>

namespace JokeBank45 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	ref class MyForm2;
	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2(void)
		{
			InitializeComponent();
			this->StartPosition = FormStartPosition::CenterScreen;
			this->Size = System::Drawing::Size(1000, 800);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ LabAddCon;
	private: System::Windows::Forms::Button^ ButImport;
	private: System::Windows::Forms::Button^ ButInput;
	private: System::Windows::Forms::Button^ ButBack;

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
			this->LabAddCon = (gcnew System::Windows::Forms::Label());
			this->ButImport = (gcnew System::Windows::Forms::Button());
			this->ButInput = (gcnew System::Windows::Forms::Button());
			this->ButBack = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// LabAddCon
			// 
			this->LabAddCon->AutoSize = true;
			this->LabAddCon->Font = (gcnew System::Drawing::Font(L"Times New Roman", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LabAddCon->ForeColor = System::Drawing::SystemColors::Control;
			this->LabAddCon->Location = System::Drawing::Point(190, 159);
			this->LabAddCon->Name = L"LabAddCon";
			this->LabAddCon->Size = System::Drawing::Size(485, 73);
			this->LabAddCon->TabIndex = 9;
			this->LabAddCon->Text = L"Add a contributor";
			// 
			// ButImport
			// 
			this->ButImport->Font = (gcnew System::Drawing::Font(L"Times New Roman", 26.25, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ButImport->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ButImport->Location = System::Drawing::Point(264, 235);
			this->ButImport->Name = L"ButImport";
			this->ButImport->Size = System::Drawing::Size(348, 59);
			this->ButImport->TabIndex = 10;
			this->ButImport->Text = L"Import from txt";
			this->ButImport->UseVisualStyleBackColor = true;
			this->ButImport->Click += gcnew System::EventHandler(this, &MyForm2::ButImport_Click);
			// 
			// ButInput
			// 
			this->ButInput->Font = (gcnew System::Drawing::Font(L"Times New Roman", 26.25, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ButInput->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ButInput->Location = System::Drawing::Point(264, 300);
			this->ButInput->Name = L"ButInput";
			this->ButInput->Size = System::Drawing::Size(348, 59);
			this->ButInput->TabIndex = 11;
			this->ButInput->Text = L"Manual input";
			this->ButInput->UseVisualStyleBackColor = true;
			this->ButInput->Click += gcnew System::EventHandler(this, &MyForm2::ButInput_Click);
			// 
			// ButBack
			// 
			this->ButBack->Font = (gcnew System::Drawing::Font(L"Times New Roman", 26.25, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ButBack->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ButBack->Location = System::Drawing::Point(264, 365);
			this->ButBack->Name = L"ButBack";
			this->ButBack->Size = System::Drawing::Size(348, 59);
			this->ButBack->TabIndex = 12;
			this->ButBack->Text = L"Back";
			this->ButBack->UseVisualStyleBackColor = true;
			this->ButBack->Click += gcnew System::EventHandler(this, &MyForm2::ButBack_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->ClientSize = System::Drawing::Size(927, 758);
			this->Controls->Add(this->ButBack);
			this->Controls->Add(this->ButInput);
			this->Controls->Add(this->ButImport);
			this->Controls->Add(this->LabAddCon);
			this->ForeColor = System::Drawing::SystemColors::Control;
			this->Name = L"MyForm2";
			this->Text = L"Bank of joke";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void ButBack_Click(System::Object^ sender, System::EventArgs^ e) {
			for each (Form ^ form in Application::OpenForms) {
				if (form->Name == "MyForm") {
					form->Show();
					break;
				}
			}
			this->Close();
		}

	private:
		System::Void ButInput_Click(System::Object^ sender, System::EventArgs^ e) {
			AddConMan^ form4 = gcnew AddConMan();
			form4->Show();
			this->Hide();
		}

	private:
		System::Void ButImport_Click(System::Object^ sender, System::EventArgs^ e) {
			ImportFromTxtFile();
		}

	private:
		void ImportFromTxtFile()
		{
			try
			{
				// Создаем диалог выбора файла
				OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();
				openFileDialog->Filter = "Text files (*.txt)|*.txt";
				openFileDialog->FilterIndex = 1;
				openFileDialog->RestoreDirectory = true;
				openFileDialog->Title = "Select text file with contributors data";

				// Показываем диалог и проверяем результат
				if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
				{
					String^ filePath = openFileDialog->FileName;

					// Проверяем расширение файла
					String^ extension = Path::GetExtension(filePath);
					if (!extension->Equals(".txt", StringComparison::OrdinalIgnoreCase))
					{
						MessageBox::Show("Please select a .txt file!", "Invalid File Type",
							MessageBoxButtons::OK, MessageBoxIcon::Warning);
						return;
					}

					// Обрабатываем файл
					ProcessTxtFile(filePath);
				}
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error selecting file: " + ex->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

	private:
		void ProcessTxtFile(String^ filePath)
		{
			int importedCount = 0;
			int errorCount = 0;
			int invalidAgeCount = 0;

			try
			{
				// Проверяем существование файла
				if (!File::Exists(filePath))
				{
					MessageBox::Show("File not found: " + filePath, "Error",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}

				// Читаем все строки из файла - исправленная строка
				cli::array<String^>^ lines = File::ReadAllLines(filePath);

				for each (String ^ line in lines)
				{
					if (!String::IsNullOrWhiteSpace(line))
					{
						// Парсим строку и добавляем вкладчика
						int result = ParseAndAddContributor(line);
						if (result == 1)
						{
							importedCount++;
						}
						else if (result == -1)
						{
							invalidAgeCount++;
						}
						else
						{
							errorCount++;
						}
					}
				}

				// Показываем результат импорта
				String^ message = String::Format(
					"Import completed!\n\n" +
					"Successfully imported: {0}\n" +
					"Invalid age: {1}\n" +
					"Format errors: {2}\n\n" +
					"Total lines processed: {3}",
					importedCount, invalidAgeCount, errorCount, lines->Length);

				MessageBox::Show(message, "Import Result",
					MessageBoxButtons::OK,
					importedCount > 0 ? MessageBoxIcon::Information : MessageBoxIcon::Warning);
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("Error reading file: " + ex->Message,
					"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

	private:
		// Возвращает: 1 - успех, 0 - ошибка формата, -1 - невалидный возраст
		int ParseAndAddContributor(String^ line)
		{
			try
			{
				// Убираем лишние пробелы
				line = line->Trim();

				// Разделяем строку на части
				cli::array<String^>^ parts = line->Split(',');

				// Проверяем минимальное количество частей (ФИО и возраст)
				if (parts->Length < 2)
				{
					return 0; // Ошибка формата
				}

				// Извлекаем ФИО (первая часть)
				String^ fullName = parts[0]->Trim();
				if (String::IsNullOrWhiteSpace(fullName))
				{
					return 0; // Ошибка формата
				}

				// Извлекаем и проверяем возраст
				int age = Convert::ToInt32(parts[1]->Trim());

				// Проверка возраста (например, от 18 до 100 лет)
				if (age < 18 || age > 100)
				{
					return -1; // Невалидный возраст
				}

				// Извлекаем сумму вклада, если указана
				double size = 0.0;
				if (parts->Length >= 3)
				{
					try
					{
						String^ sizeStr = parts[2]->Trim();

						// ЗАМЕНЯЕМ точку на запятую для корректного парсинга
						sizeStr = sizeStr->Replace(".", ",");

						// Или используем CultureInfo для парсинга с точкой
						// System::Globalization::CultureInfo^ culture = gcnew System::Globalization::CultureInfo("en-US");
						// size = Double::Parse(sizeStr, culture);

						size = Convert::ToDouble(sizeStr);
						if (size < 0) size = 0.0; // Не допускаем отрицательные суммы
					}
					catch (Exception^)
					{
						try
						{
							// Альтернативная попытка парсинга с точкой
							String^ sizeStr = parts[2]->Trim();
							System::Globalization::CultureInfo^ culture = gcnew System::Globalization::CultureInfo("en-US");
							size = Double::Parse(sizeStr, culture);
							if (size < 0) size = 0.0;
						}
						catch (Exception^)
						{
							size = 0.0; // Если сумма некорректна, устанавливаем 0
						}
					}
				}

				// Добавляем вкладчика через DataManager
				DataManager::Instance->AddContributor(fullName, age);

				// Если была указана сумма, обновляем последнего добавленного вкладчика
				if (parts->Length >= 3)
				{
					int lastIndex = DataManager::Instance->GetContributorCount() - 1;
					if (lastIndex >= 0)
					{
						ManagedContributor^ lastContributor = DataManager::Instance->GetContributor(lastIndex);
						if (lastContributor != nullptr)
						{
							lastContributor->Size = size;
						}
					}
				}

				return 1; // Успех
			}
			catch (Exception^)
			{
				return 0; // Ошибка формата
			}
		}
	};
}
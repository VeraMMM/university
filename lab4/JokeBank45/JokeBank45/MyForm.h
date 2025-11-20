#pragma once
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include "MyForm2.h" 
#include "MyForm3.h"
#include "Contributor.h"
#include <msclr\marshal_cppstd.h>
#include "AddConMan.h"
#include "DataManager.h"
#include "EditContributorForm.h"

namespace JokeBank45 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace std;

    public ref class MyForm : public System::Windows::Forms::Form
    {
    public:
        MyForm(void)
        {
            InitializeComponent();
            this->StartPosition = FormStartPosition::CenterScreen;
            this->Size = System::Drawing::Size(1000, 800);

            // Подписываемся на события ОДИН РАЗ в конструкторе
            dataGridView1->CellContentClick += gcnew DataGridViewCellEventHandler(this, &MyForm::dataGridView1_CellContentClick);
        }

    protected:
        ~MyForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Button^ AddCon;
        System::Windows::Forms::Button^ DelCon;
        System::Windows::Forms::Button^ ShowInf;
        System::Windows::Forms::Button^ TotalAm;
        System::Windows::Forms::Button^ exxit;
        System::Windows::Forms::Label^ JokeBank;
        System::Windows::Forms::DataGridView^ dataGridView1;
        System::ComponentModel::Container^ components;
    private: System::Windows::Forms::Button^ Savetxt;


        bool isEditFormOpen = false; // Флаг для блокировки множественных открытий

#pragma region Windows Form Designer generated code
        void InitializeComponent()
        {
            this->AddCon = (gcnew System::Windows::Forms::Button());
            this->DelCon = (gcnew System::Windows::Forms::Button());
            this->ShowInf = (gcnew System::Windows::Forms::Button());
            this->TotalAm = (gcnew System::Windows::Forms::Button());
            this->exxit = (gcnew System::Windows::Forms::Button());
            this->JokeBank = (gcnew System::Windows::Forms::Label());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->Savetxt = (gcnew System::Windows::Forms::Button());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();
            // 
            // AddCon
            // 
            this->AddCon->Font = (gcnew System::Drawing::Font(L"Times New Roman", 26.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->AddCon->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->AddCon->Location = System::Drawing::Point(264, 235);
            this->AddCon->Name = L"AddCon";
            this->AddCon->Size = System::Drawing::Size(348, 59);
            this->AddCon->TabIndex = 1;
            this->AddCon->Text = L"Add a contributor";
            this->AddCon->UseVisualStyleBackColor = true;
            this->AddCon->Click += gcnew System::EventHandler(this, &MyForm::AddCon_Click);
            // 
            // DelCon
            // 
            this->DelCon->Font = (gcnew System::Drawing::Font(L"Times New Roman", 26.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->DelCon->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->DelCon->Location = System::Drawing::Point(264, 300);
            this->DelCon->Name = L"DelCon";
            this->DelCon->Size = System::Drawing::Size(348, 59);
            this->DelCon->TabIndex = 2;
            this->DelCon->Text = L"Delete a contributor";
            this->DelCon->UseVisualStyleBackColor = true;
            this->DelCon->Click += gcnew System::EventHandler(this, &MyForm::DelCon_Click);
            // 
            // ShowInf
            // 
            this->ShowInf->Font = (gcnew System::Drawing::Font(L"Times New Roman", 26.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->ShowInf->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->ShowInf->Location = System::Drawing::Point(264, 365);
            this->ShowInf->Name = L"ShowInf";
            this->ShowInf->Size = System::Drawing::Size(348, 59);
            this->ShowInf->TabIndex = 4;
            this->ShowInf->Text = L"Show information";
            this->ShowInf->UseVisualStyleBackColor = true;
            this->ShowInf->Click += gcnew System::EventHandler(this, &MyForm::ShowInf_Click);
            // 
            // TotalAm
            // 
            this->TotalAm->Font = (gcnew System::Drawing::Font(L"Times New Roman", 26.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->TotalAm->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->TotalAm->Location = System::Drawing::Point(264, 430);
            this->TotalAm->Name = L"TotalAm";
            this->TotalAm->Size = System::Drawing::Size(348, 59);
            this->TotalAm->TabIndex = 5;
            this->TotalAm->Text = L"Total amount";
            this->TotalAm->UseVisualStyleBackColor = true;
            this->TotalAm->Click += gcnew System::EventHandler(this, &MyForm::TotalAm_Click);
            // 
            // exxit
            // 
            this->exxit->Font = (gcnew System::Drawing::Font(L"Times New Roman", 26.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->exxit->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->exxit->Location = System::Drawing::Point(264, 560);
            this->exxit->Name = L"exxit";
            this->exxit->Size = System::Drawing::Size(348, 59);
            this->exxit->TabIndex = 6;
            this->exxit->Text = L"Exit";
            this->exxit->UseVisualStyleBackColor = true;
            this->exxit->Click += gcnew System::EventHandler(this, &MyForm::exxit_Click);
            // 
            // JokeBank
            // 
            this->JokeBank->AutoSize = true;
            this->JokeBank->Font = (gcnew System::Drawing::Font(L"Times New Roman", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->JokeBank->ForeColor = System::Drawing::SystemColors::Control;
            this->JokeBank->Location = System::Drawing::Point(251, 159);
            this->JokeBank->Name = L"JokeBank";
            this->JokeBank->Size = System::Drawing::Size(361, 73);
            this->JokeBank->TabIndex = 8;
            this->JokeBank->Text = L"Bank of joke";
            // 
            // dataGridView1
            // 
            this->dataGridView1->Location = System::Drawing::Point(59, 625);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->Size = System::Drawing::Size(808, 271);
            this->dataGridView1->TabIndex = 9;
            this->dataGridView1->Visible = false;
            // 
            // Savetxt
            // 
            this->Savetxt->Font = (gcnew System::Drawing::Font(L"Times New Roman", 26.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->Savetxt->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
            this->Savetxt->Location = System::Drawing::Point(264, 495);
            this->Savetxt->Name = L"Savetxt";
            this->Savetxt->Size = System::Drawing::Size(348, 59);
            this->Savetxt->TabIndex = 10;
            this->Savetxt->Text = L"Save to txt";
            this->Savetxt->UseVisualStyleBackColor = true;
            this->Savetxt->Click += gcnew System::EventHandler(this, &MyForm::Savetxt_Click);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
            this->ClientSize = System::Drawing::Size(927, 995);
            this->Controls->Add(this->Savetxt);
            this->Controls->Add(this->dataGridView1);
            this->Controls->Add(this->JokeBank);
            this->Controls->Add(this->exxit);
            this->Controls->Add(this->TotalAm);
            this->Controls->Add(this->ShowInf);
            this->Controls->Add(this->DelCon);
            this->Controls->Add(this->AddCon);
            this->Name = L"MyForm";
            this->Text = L"Bank of joke";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        System::Void AddCon_Click(System::Object^ sender, System::EventArgs^ e) {
            MyForm2^ form2 = gcnew MyForm2();
            form2->Show();
            this->Hide();
        }

        System::Void DelCon_Click(System::Object^ sender, System::EventArgs^ e) {
            MyForm3^ form3 = gcnew MyForm3();
            form3->Show();
            this->Hide();
        }

        System::Void exxit_Click(System::Object^ sender, System::EventArgs^ e) {
            Application::Exit();
        }

        System::Void ShowInf_Click(System::Object^ sender, System::EventArgs^ e) {
            UpdateDataGridView();
        }

        System::Void TotalAm_Click(System::Object^ sender, System::EventArgs^ e) {
            double total = 0.0;
            int count = DataManager::Instance->GetContributorCount();

            for (int i = 0; i < count; i++)
            {
                ManagedContributor^ contributor = DataManager::Instance->GetContributor(i);
                if (contributor != nullptr)
                {
                    total += contributor->Size;
                }
            }

            MessageBox::Show("Total amount: " + total.ToString("F2"), "Total Amount");
        }

        void UpdateDataGridView()
        {
            dataGridView1->Rows->Clear();
            dataGridView1->Columns->Clear();

            // Настройка DataGridView
            dataGridView1->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            dataGridView1->AllowUserToAddRows = false;
            dataGridView1->ReadOnly = true;

            // Создаем колонки
            dataGridView1->Columns->Add("ID", "ID");
            dataGridView1->Columns->Add("Name", "Name");
            dataGridView1->Columns->Add("Age", "Age");
            dataGridView1->Columns->Add("Size", "Size");

            // Добавляем кнопку Edit
            DataGridViewButtonColumn^ editButton = gcnew DataGridViewButtonColumn();
            editButton->HeaderText = "Action";
            editButton->Text = "Edit";
            editButton->UseColumnTextForButtonValue = true;
            editButton->Name = "EditButton";
            dataGridView1->Columns->Add(editButton);

            // Получаем данные
            int count = DataManager::Instance->GetContributorCount();
            for (int i = 0; i < count; i++)
            {
                ManagedContributor^ contributor = DataManager::Instance->GetContributor(i);
                if (contributor != nullptr)
                {
                    dataGridView1->Rows->Add(
                        (i + 1).ToString(),
                        contributor->Name,
                        contributor->Age.ToString(),
                        contributor->Size.ToString("F2")
                    );
                }
            }

            dataGridView1->Visible = true;
        }

    private: System::Void dataGridView1_CellContentClick(System::Object^ sender, DataGridViewCellEventArgs^ e) {
        // Проверяем, что кликнули по колонке с кнопкой Edit
        if (e->RowIndex >= 0 && e->ColumnIndex >= 0 && !isEditFormOpen)
        {
            DataGridViewColumn^ clickedColumn = dataGridView1->Columns[e->ColumnIndex];

            if (clickedColumn->Name == "EditButton")
            {
                isEditFormOpen = true; // Блокируем

                try
                {
                    int contributorId = Convert::ToInt32(dataGridView1->Rows[e->RowIndex]->Cells[0]->Value);
                    int actualIndex = contributorId - 1;

                    EditContributorForm^ editForm = gcnew EditContributorForm(actualIndex);

                    // Показываем как модальное окно и ждем результата
                    System::Windows::Forms::DialogResult result = editForm->ShowDialog();

                    if (result == System::Windows::Forms::DialogResult::OK)
                    {
                        UpdateDataGridView(); // Обновляем если сохранили
                    }

                    // Явно освобождаем ресурсы
                    delete editForm;
                    isEditFormOpen = false; // Разблокируем
                }
                catch (Exception^ ex)
                {
                    MessageBox::Show("Error: " + ex->Message);
                    isEditFormOpen = false; // Разблокируем при ошибке
                }
            }
        }
    }

    public:
        void ReturnToMainMenu() {
            this->Show();
        }
    private: System::Void Savetxt_Click(System::Object^ sender, System::EventArgs^ e) {
        SaveDataToFile();
    }

    private:
        void SaveDataToFile()
        {
            try
            {
                // Создаем диалог сохранения файла
                SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();
                saveFileDialog->Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*";
                saveFileDialog->FilterIndex = 1;
                saveFileDialog->RestoreDirectory = true;
                saveFileDialog->Title = "Save contributors data to file";
                saveFileDialog->FileName = "contributors_backup.txt";

                if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
                {
                    String^ filePath = saveFileDialog->FileName;

                    // Сохраняем данные
                    SaveGridToTextFile(filePath);

                    MessageBox::Show("Data successfully saved to:\n" + filePath,
                        "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                }
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error saving file: " + ex->Message,
                    "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

private:
    void SaveGridToTextFile(String^ filePath)
    {
        System::Collections::Generic::List<String^>^ lines = gcnew System::Collections::Generic::List<String^>();

        // Сохраняем все данные из DataManager
        int count = DataManager::Instance->GetContributorCount();
        for (int i = 0; i < count; i++)
        {
            ManagedContributor^ contributor = DataManager::Instance->GetContributor(i);
            if (contributor != nullptr)
            {
                String^ line = String::Format("{0},{1},{2:F2}",
                    contributor->Name,
                    contributor->Age,
                    contributor->Size);
                lines->Add(line);
            }
        }

        System::IO::File::WriteAllLines(filePath, lines->ToArray());
    }
};
}
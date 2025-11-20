#pragma once
#include "DataManager.h"

namespace JokeBank45 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MyForm3 : public System::Windows::Forms::Form
    {
    public:
        MyForm3(void)
        {
            InitializeComponent();
            this->StartPosition = FormStartPosition::CenterScreen;
            this->Size = System::Drawing::Size(1000, 800);
            LoadContributors();
        }

    protected:
        ~MyForm3()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::DataGridView^ dataGridView1;
        System::Windows::Forms::Button^ btnDelete;
        System::Windows::Forms::Button^ btnBack;
        System::Windows::Forms::Label^ label1;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->btnDelete = (gcnew System::Windows::Forms::Button());
            this->btnBack = (gcnew System::Windows::Forms::Button());
            this->label1 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();

            // dataGridView1
            this->dataGridView1->AllowUserToAddRows = false;
            this->dataGridView1->AllowUserToDeleteRows = false;
            this->dataGridView1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((
                System::Windows::Forms::AnchorStyles::Top |
                System::Windows::Forms::AnchorStyles::Bottom)
                | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right);
            this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Location = System::Drawing::Point(12, 80);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->ReadOnly = true;
            this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
            this->dataGridView1->Size = System::Drawing::Size(900, 500);
            this->dataGridView1->TabIndex = 0;

            // btnDelete
            this->btnDelete->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
            this->btnDelete->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->btnDelete->Location = System::Drawing::Point(300, 600);
            this->btnDelete->Name = L"btnDelete";
            this->btnDelete->Size = System::Drawing::Size(150, 50);
            this->btnDelete->TabIndex = 1;
            this->btnDelete->Text = L"Delete";
            this->btnDelete->UseVisualStyleBackColor = true;
            this->btnDelete->Click += gcnew System::EventHandler(this, &MyForm3::btnDelete_Click);

            // btnBack
            this->btnBack->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
            this->btnBack->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->btnBack->Location = System::Drawing::Point(500, 600);
            this->btnBack->Name = L"btnBack";
            this->btnBack->Size = System::Drawing::Size(150, 50);
            this->btnBack->TabIndex = 2;
            this->btnBack->Text = L"Back";
            this->btnBack->UseVisualStyleBackColor = true;
            this->btnBack->Click += gcnew System::EventHandler(this, &MyForm3::btnBack_Click);

            // label1
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->label1->Location = System::Drawing::Point(350, 20);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(250, 36);
            this->label1->TabIndex = 3;
            this->label1->Text = L"Delete Contributor";

            // MyForm3
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
            this->ClientSize = System::Drawing::Size(924, 671);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->btnBack);
            this->Controls->Add(this->btnDelete);
            this->Controls->Add(this->dataGridView1);
            this->Name = L"MyForm3";
            this->Text = L"Delete Contributor";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }

    private:
        void LoadContributors()
        {
            dataGridView1->Rows->Clear();
            dataGridView1->Columns->Clear();

            // Создаем колонки
            dataGridView1->Columns->Add("ID", "ID");
            dataGridView1->Columns->Add("Name", "Name");
            dataGridView1->Columns->Add("Age", "Age");
            dataGridView1->Columns->Add("Size", "Size");

            // Получаем данные
            int count = DataManager::Instance->GetContributorCount();

            for (int i = 0; i < count; i++)
            {
                ManagedContributor^ contributor = DataManager::Instance->GetContributor(i);
                if (contributor != nullptr)
                {
                    dataGridView1->Rows->Add(
                        (i + 1).ToString(),      // ID
                        contributor->Name,       // Name
                        contributor->Age.ToString(), // Age
                        contributor->Size.ToString("F2") // Size
                    );
                }
            }
        }

        System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (dataGridView1->SelectedRows->Count > 0)
            {
                int selectedIndex = dataGridView1->SelectedRows[0]->Index;
                int contributorId = Convert::ToInt32(dataGridView1->Rows[selectedIndex]->Cells[0]->Value);

                // ID в таблице начинается с 1, а в списке с 0
                int actualIndex = contributorId - 1;

                if (DataManager::Instance->RemoveContributor(actualIndex))
                {
                    MessageBox::Show("Contributor deleted successfully!");
                    LoadContributors(); // Обновляем таблицу
                }
                else
                {
                    MessageBox::Show("Error deleting contributor!");
                }
            }
            else
            {
                MessageBox::Show("Please select a contributor to delete!");
            }
        }

        System::Void btnBack_Click(System::Object^ sender, System::EventArgs^ e)
        {
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
#pragma once
#include "DataManager.h"

namespace JokeBank45 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class EditContributorForm : public System::Windows::Forms::Form
    {
    private:
        int contributorIndex;
        bool isClosing; // Флаг для предотвращения повторного закрытия

    public:
        EditContributorForm(int index)
        {
            contributorIndex = index;
            isClosing = false;
            InitializeComponent();
            LoadContributorData();
        }

    protected:
        ~EditContributorForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TextBox^ txtName;
        System::Windows::Forms::TextBox^ txtAge;
        System::Windows::Forms::TextBox^ txtSize;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::Button^ btnSave;
        System::Windows::Forms::Button^ btnCancel;
        System::ComponentModel::Container^ components;

        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->txtName = (gcnew System::Windows::Forms::TextBox());
            this->txtAge = (gcnew System::Windows::Forms::TextBox());
            this->txtSize = (gcnew System::Windows::Forms::TextBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->btnSave = (gcnew System::Windows::Forms::Button());
            this->btnCancel = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();

            // txtName
            this->txtName->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
            this->txtName->Location = System::Drawing::Point(150, 50);
            this->txtName->Name = L"txtName";
            this->txtName->Size = System::Drawing::Size(200, 25);
            this->txtName->TabIndex = 0;
            this->txtName->MaxLength = 10;

            // txtAge
            this->txtAge->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
            this->txtAge->Location = System::Drawing::Point(150, 100);
            this->txtAge->Name = L"txtAge";
            this->txtAge->Size = System::Drawing::Size(200, 25);
            this->txtAge->TabIndex = 1;
            this->txtAge->MaxLength = 3;

            // txtSize
            this->txtSize->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
            this->txtSize->Location = System::Drawing::Point(150, 150);
            this->txtSize->Name = L"txtSize";
            this->txtSize->Size = System::Drawing::Size(200, 25);
            this->txtSize->TabIndex = 2;

            // label1
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
            this->label1->Location = System::Drawing::Point(50, 53);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(50, 19);
            this->label1->TabIndex = 3;
            this->label1->Text = L"Name:";

            // label2
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
            this->label2->Location = System::Drawing::Point(50, 103);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(41, 19);
            this->label2->TabIndex = 4;
            this->label2->Text = L"Age:";

            // label3
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
            this->label3->Location = System::Drawing::Point(50, 153);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(44, 19);
            this->label3->TabIndex = 5;
            this->label3->Text = L"Size:";

            // btnSave
            this->btnSave->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
            this->btnSave->Location = System::Drawing::Point(100, 220);
            this->btnSave->Name = L"btnSave";
            this->btnSave->Size = System::Drawing::Size(100, 35);
            this->btnSave->TabIndex = 6;
            this->btnSave->Text = L"Save";
            this->btnSave->UseVisualStyleBackColor = true;
            this->btnSave->Click += gcnew System::EventHandler(this, &EditContributorForm::btnSave_Click);

            // btnCancel
            this->btnCancel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12));
            this->btnCancel->Location = System::Drawing::Point(250, 220);
            this->btnCancel->Name = L"btnCancel";
            this->btnCancel->Size = System::Drawing::Size(100, 35);
            this->btnCancel->TabIndex = 7;
            this->btnCancel->Text = L"Cancel";
            this->btnCancel->UseVisualStyleBackColor = true;
            this->btnCancel->Click += gcnew System::EventHandler(this, &EditContributorForm::btnCancel_Click);

            // EditContributorForm
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
            this->ClientSize = System::Drawing::Size(500, 300);
            this->Controls->Add(this->btnCancel);
            this->Controls->Add(this->btnSave);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->txtSize);
            this->Controls->Add(this->txtAge);
            this->Controls->Add(this->txtName);
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->Name = L"EditContributorForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Edit Contributor";

            // Добавляем обработчики для валидации
            this->txtAge->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EditContributorForm::txtAge_KeyPress);
            this->txtAge->TextChanged += gcnew System::EventHandler(this, &EditContributorForm::txtAge_TextChanged);

            this->ResumeLayout(false);
            this->PerformLayout();
        }

    private:
        void LoadContributorData()
        {
            ManagedContributor^ contributor = DataManager::Instance->GetContributor(contributorIndex);
            if (contributor != nullptr)
            {
                txtName->Text = contributor->Name;
                txtAge->Text = contributor->Age.ToString();
                txtSize->Text = contributor->Size.ToString("F2");
            }
        }

        System::Void txtAge_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
        {
            if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 8 && e->KeyChar != 127)
            {
                e->Handled = true;
            }
        }

        System::Void txtAge_TextChanged(System::Object^ sender, System::EventArgs^ e)
        {
            String^ ageText = txtAge->Text;

            if (!String::IsNullOrEmpty(ageText))
            {
                int age;
                if (Int32::TryParse(ageText, age))
                {
                    if (age < 18 || age > 120)
                    {
                        txtAge->BackColor = Drawing::Color::LightPink;
                    }
                    else
                    {
                        txtAge->BackColor = Drawing::Color::LightGreen;
                    }
                }
                else
                {
                    txtAge->BackColor = Drawing::Color::LightPink;
                }
            }
            else
            {
                txtAge->BackColor = Drawing::Color::White;
            }
        }

        System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e)
        {
            try
            {
                // Валидация данных перед сохранением
                if (String::IsNullOrEmpty(txtName->Text) || txtName->Text->Length > 10)
                {
                    MessageBox::Show("Name must be between 1 and 10 characters!");
                    return;
                }

                int age;
                if (!Int32::TryParse(txtAge->Text, age) || age < 18 || age > 120)
                {
                    MessageBox::Show("Age must be a number between 18 and 120!");
                    return;
                }

                double size;
                if (!Double::TryParse(txtSize->Text, size) || size < 0)
                {
                    MessageBox::Show("Size must be a positive number!");
                    return;
                }

                ManagedContributor^ contributor = DataManager::Instance->GetContributor(contributorIndex);
                if (contributor != nullptr)
                {
                    contributor->Name = txtName->Text;
                    contributor->Age = age;
                    contributor->Size = size;
                }

                this->DialogResult = System::Windows::Forms::DialogResult::OK;
                this->Close();
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error saving changes: " + ex->Message);
            }
        }

        System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->Close();
        }
    };
}
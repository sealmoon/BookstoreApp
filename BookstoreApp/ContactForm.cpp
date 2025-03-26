#include "ContactForm.h"
#include "Contact.h"

using namespace System;
using namespace System::Windows::Forms;

namespace BookstoreApp {

    ContactForm::ContactForm(bool isEditMode) {
        InitializeComponent();
        SetFormMode(isEditMode);
    }

    ContactForm::ContactForm(bool isEditMode, Contact^ contact) {
        InitializeComponent();
        SetFormMode(isEditMode);
        if (contact != nullptr) {
            SetContactDetails(contact);
        }
    }

    ContactForm::~ContactForm() {
        if (components) {
            delete components;
        }
    }

    void ContactForm::SetFormMode(bool isEditMode) {
        this->Text = isEditMode ? "Edit Contact" : "Add New Contact";
    }

    void ContactForm::SetContactDetails(Contact^ contact) {
        this->txtName->Text = contact->Name;
        this->txtPhoneNumber->Text = contact->PhoneNumber;
        this->txtEmail->Text = contact->Email;
    }

    Contact^ ContactForm::GetContact() {
        try {
            String^ name = this->txtName->Text;
            String^ phoneNumber = this->txtPhoneNumber->Text;
            String^ email = this->txtEmail->Text;

            return gcnew Contact(name, phoneNumber, email);
        }
        catch (Exception^ ex) {
            MessageBox::Show("Invalid input: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
            return nullptr;
        }
    }

    System::Void ContactForm::btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
        try {
            if (String::IsNullOrEmpty(txtName->Text)) {
                MessageBox::Show("Please enter a name.", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            if (String::IsNullOrEmpty(txtEmail->Text)) {
                MessageBox::Show("Please enter an email address.", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Error);
                return;
            }

            this->DialogResult = ::DialogResult::OK;
            this->Close();
        }
        catch (Exception^ ex) {
            MessageBox::Show("Error saving contact: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
        }
    }

    System::Void ContactForm::btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
        this->DialogResult = ::DialogResult::Cancel;
        this->Close();
    }

    System::Void ContactForm::txtName_TextChanged(System::Object^ sender, System::EventArgs^ e) {
        // Empty implementation
    }

    void ContactForm::InitializeComponent() {
        this->components = gcnew System::ComponentModel::Container();

        this->txtName = gcnew System::Windows::Forms::TextBox();
        this->txtPhoneNumber = gcnew System::Windows::Forms::TextBox();
        this->txtEmail = gcnew System::Windows::Forms::TextBox();
        this->btnSave = gcnew System::Windows::Forms::Button();
        this->btnCancel = gcnew System::Windows::Forms::Button();
        this->lblName = gcnew System::Windows::Forms::Label();
        this->lblPhoneNumber = gcnew System::Windows::Forms::Label();
        this->lblEmail = gcnew System::Windows::Forms::Label();

        // Control initialization code
        this->SuspendLayout();

        // txtName
        this->txtName->Location = System::Drawing::Point(150, 50);
        this->txtName->Name = L"txtName";
        this->txtName->Size = System::Drawing::Size(200, 20);
        this->txtName->TabIndex = 0;
        this->txtName->TextChanged += gcnew System::EventHandler(this, &ContactForm::txtName_TextChanged);

        // txtPhoneNumber
        this->txtPhoneNumber->Location = System::Drawing::Point(150, 80);
        this->txtPhoneNumber->Name = L"txtPhoneNumber";
        this->txtPhoneNumber->Size = System::Drawing::Size(200, 20);
        this->txtPhoneNumber->TabIndex = 1;

        // txtEmail
        this->txtEmail->Location = System::Drawing::Point(150, 110);
        this->txtEmail->Name = L"txtEmail";
        this->txtEmail->Size = System::Drawing::Size(200, 20);
        this->txtEmail->TabIndex = 2;

        // btnSave
        this->btnSave->Location = System::Drawing::Point(150, 150);
        this->btnSave->Name = L"btnSave";
        this->btnSave->Size = System::Drawing::Size(75, 30);
        this->btnSave->TabIndex = 3;
        this->btnSave->Text = L"Save";
        this->btnSave->UseVisualStyleBackColor = true;
        this->btnSave->Click += gcnew System::EventHandler(this, &ContactForm::btnSave_Click);

        // btnCancel
        this->btnCancel->Location = System::Drawing::Point(250, 150);
        this->btnCancel->Name = L"btnCancel";
        this->btnCancel->Size = System::Drawing::Size(75, 30);
        this->btnCancel->TabIndex = 4;
        this->btnCancel->Text = L"Cancel";
        this->btnCancel->UseVisualStyleBackColor = true;
        this->btnCancel->Click += gcnew System::EventHandler(this, &ContactForm::btnCancel_Click);

        // lblName
        this->lblName->AutoSize = true;
        this->lblName->Location = System::Drawing::Point(50, 50);
        this->lblName->Name = L"lblName";
        this->lblName->Size = System::Drawing::Size(38, 13);
        this->lblName->TabIndex = 5;
        this->lblName->Text = L"Name:";

        // lblPhoneNumber
        this->lblPhoneNumber->AutoSize = true;
        this->lblPhoneNumber->Location = System::Drawing::Point(50, 80);
        this->lblPhoneNumber->Name = L"lblPhoneNumber";
        this->lblPhoneNumber->Size = System::Drawing::Size(81, 13);
        this->lblPhoneNumber->TabIndex = 6;
        this->lblPhoneNumber->Text = L"Phone Number:";

        // lblEmail
        this->lblEmail->AutoSize = true;
        this->lblEmail->Location = System::Drawing::Point(50, 110);
        this->lblEmail->Name = L"lblEmail";
        this->lblEmail->Size = System::Drawing::Size(35, 13);
        this->lblEmail->TabIndex = 7;
        this->lblEmail->Text = L"Email:";

        // ContactForm
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(400, 200);
        this->Controls->Add(this->lblEmail);
        this->Controls->Add(this->lblPhoneNumber);
        this->Controls->Add(this->lblName);
        this->Controls->Add(this->btnCancel);
        this->Controls->Add(this->btnSave);
        this->Controls->Add(this->txtEmail);
        this->Controls->Add(this->txtPhoneNumber);
        this->Controls->Add(this->txtName);
        this->Name = L"ContactForm";
        this->Text = L"Contact Details";
        this->ResumeLayout(false);
        this->PerformLayout();
    }
}
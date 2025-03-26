#pragma once
#include "Contact.h"

namespace BookstoreApp {
    public ref class ContactForm : public System::Windows::Forms::Form {
    public:
        ContactForm(bool isEditMode);
        ContactForm(bool isEditMode, Contact^ contact);
        ~ContactForm();

        Contact^ GetContact();
        void SetContactDetails(Contact^ contact);

    private:
        System::Windows::Forms::TextBox^ txtName;
        System::Windows::Forms::TextBox^ txtPhoneNumber;
        System::Windows::Forms::TextBox^ txtEmail;
        System::Windows::Forms::Button^ btnSave;
        System::Windows::Forms::Button^ btnCancel;
        System::Windows::Forms::Label^ lblName;
        System::Windows::Forms::Label^ lblPhoneNumber;
        System::Windows::Forms::Label^ lblEmail;

        System::ComponentModel::Container^ components;

        void SetFormMode(bool isEditMode);
        void InitializeComponent();

        System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void txtName_TextChanged(System::Object^ sender, System::EventArgs^ e);
    };
}
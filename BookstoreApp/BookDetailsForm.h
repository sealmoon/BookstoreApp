#pragma once
#include "Book.h"

namespace BookstoreApp {
    using namespace System;
    using namespace System::Windows::Forms;

    public ref class BookDetailsForm : public Form {
    public:
        BookDetailsForm(bool isEditMode);
        BookDetailsForm(bool isEditMode, Book^ bookToEdit);
        Book^ GetBook();

    private:
        TextBox^ txtTitle;
        TextBox^ txtAuthor;
        TextBox^ txtPages;
        TextBox^ txtPrice;
        TextBox^ txtQuantity;
        Button^ btnSave;
        Button^ btnCancel;
        Label^ lblTitle;
        Label^ lblAuthor;
        Label^ lblPages;
        Label^ lblPrice;
        Label^ lblQuantity;

        bool isEditMode;
        Book^ bookToEdit;

        void InitializeComponent();
        void SetFormMode(bool isEditMode);
        System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e);
    };
}
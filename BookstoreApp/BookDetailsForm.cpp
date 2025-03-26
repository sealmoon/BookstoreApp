#include "BookDetailsForm.h"
#include "Book.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace BookstoreApp {

    BookDetailsForm::BookDetailsForm(bool isEditMode) : isEditMode(isEditMode), bookToEdit(nullptr) {
        InitializeComponent();
        SetFormMode(isEditMode);
    }

    BookDetailsForm::BookDetailsForm(bool isEditMode, Book^ bookToEdit) : isEditMode(isEditMode), bookToEdit(bookToEdit) {
        InitializeComponent();
        SetFormMode(isEditMode);

        // Populate fields if editing
        if (bookToEdit != nullptr) {
            txtTitle->Text = bookToEdit->Title;
            txtAuthor->Text = bookToEdit->Author;
            txtPages->Text = bookToEdit->Pages.ToString();
            txtPrice->Text = bookToEdit->Price.ToString();
            txtQuantity->Text = bookToEdit->Quantity.ToString();
        }
    }

    void BookDetailsForm::SetFormMode(bool isEditMode) {
        this->Text = isEditMode ? "Edit Book" : "Add New Book";

        // In edit mode, make title and author read-only
        txtTitle->ReadOnly = isEditMode;
        txtAuthor->ReadOnly = isEditMode;
    }

    Book^ BookDetailsForm::GetBook() {
        try {
            String^ title = txtTitle->Text;
            String^ author = txtAuthor->Text;
            int pages = Convert::ToInt32(txtPages->Text);
            double price = Convert::ToDouble(txtPrice->Text);
            int quantity = Convert::ToInt32(txtQuantity->Text);

            if (isEditMode && bookToEdit != nullptr) {
                // Update the existing book
                bookToEdit->Pages = pages;
                bookToEdit->Price = price;
                bookToEdit->Quantity = quantity;
                return bookToEdit;
            }
            else {
                // Create a new book
                return gcnew Book(title, author, pages, price, quantity);
            }
        }
        catch (Exception^ ex) {
            MessageBox::Show("Invalid input: " + ex->Message, "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
            return nullptr;
        }
    }

    System::Void BookDetailsForm::btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
        // Validate inputs
        if (String::IsNullOrEmpty(txtTitle->Text)) {
            MessageBox::Show("Please enter a title", "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        if (String::IsNullOrEmpty(txtAuthor->Text)) {
            MessageBox::Show("Please enter an author", "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        try {
            Convert::ToInt32(txtPages->Text);
            Convert::ToDouble(txtPrice->Text);
            Convert::ToInt32(txtQuantity->Text);
        }
        catch (Exception^) {
            MessageBox::Show("Please enter valid numeric values for pages, price, and quantity",
                "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        this->DialogResult = Windows::Forms::DialogResult::OK;
        this->Close();
    }

    System::Void BookDetailsForm::btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
        this->DialogResult = Windows::Forms::DialogResult::Cancel;
        this->Close();
    }

    void BookDetailsForm::InitializeComponent() {
        this->SuspendLayout();

        // Create controls
        this->txtTitle = gcnew TextBox();
        this->txtAuthor = gcnew TextBox();
        this->txtPages = gcnew TextBox();
        this->txtPrice = gcnew TextBox();
        this->txtQuantity = gcnew TextBox();
        this->btnSave = gcnew Button();
        this->btnCancel = gcnew Button();
        this->lblTitle = gcnew Label();
        this->lblAuthor = gcnew Label();
        this->lblPages = gcnew Label();
        this->lblPrice = gcnew Label();
        this->lblQuantity = gcnew Label();

        // Set control properties
        // Labels
        lblTitle->Text = "Title:";
        lblTitle->Location = Drawing::Point(20, 20);
        lblTitle->AutoSize = true;

        lblAuthor->Text = "Author:";
        lblAuthor->Location = Drawing::Point(20, 50);
        lblAuthor->AutoSize = true;

        lblPages->Text = "Pages:";
        lblPages->Location = Drawing::Point(20, 80);
        lblPages->AutoSize = true;

        lblPrice->Text = "Price:";
        lblPrice->Location = Drawing::Point(20, 110);
        lblPrice->AutoSize = true;

        lblQuantity->Text = "Quantity:";
        lblQuantity->Location = Drawing::Point(20, 140);
        lblQuantity->AutoSize = true;

        // TextBoxes
        txtTitle->Location = Drawing::Point(100, 20);
        txtTitle->Size = Drawing::Size(200, 20);

        txtAuthor->Location = Drawing::Point(100, 50);
        txtAuthor->Size = Drawing::Size(200, 20);

        txtPages->Location = Drawing::Point(100, 80);
        txtPages->Size = Drawing::Size(200, 20);

        txtPrice->Location = Drawing::Point(100, 110);
        txtPrice->Size = Drawing::Size(200, 20);

        txtQuantity->Location = Drawing::Point(100, 140);
        txtQuantity->Size = Drawing::Size(200, 20);

        // Buttons
        btnSave->Text = "Save";
        btnSave->Location = Drawing::Point(100, 180);
        btnSave->Size = Drawing::Size(75, 30);
        btnSave->Click += gcnew EventHandler(this, &BookDetailsForm::btnSave_Click);

        btnCancel->Text = "Cancel";
        btnCancel->Location = Drawing::Point(180, 180);
        btnCancel->Size = Drawing::Size(75, 30);
        btnCancel->Click += gcnew EventHandler(this, &BookDetailsForm::btnCancel_Click);

        // Form properties
        this->Text = isEditMode ? "Edit Book" : "Add New Book";
        this->ClientSize = Drawing::Size(350, 250);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
        this->MaximizeBox = false;
        this->MinimizeBox = false;
        this->StartPosition = FormStartPosition::CenterParent;

        // Add controls to form
        this->Controls->Add(lblTitle);
        this->Controls->Add(lblAuthor);
        this->Controls->Add(lblPages);
        this->Controls->Add(lblPrice);
        this->Controls->Add(lblQuantity);
        this->Controls->Add(txtTitle);
        this->Controls->Add(txtAuthor);
        this->Controls->Add(txtPages);
        this->Controls->Add(txtPrice);
        this->Controls->Add(txtQuantity);
        this->Controls->Add(btnSave);
        this->Controls->Add(btnCancel);

        this->ResumeLayout(false);
        this->PerformLayout();
    }
}
#include "ReviewForm.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;

namespace BookstoreApp {

    ReviewForm::ReviewForm() {
        InitializeComponent();
    }

    ReviewForm::~ReviewForm() {
        if (components) {
            delete components;
        }
    }

    System::Void ReviewForm::btnSubmit_Click(System::Object^ sender, System::EventArgs^ e) {
        if (String::IsNullOrEmpty(txtUsername->Text)) {
            MessageBox::Show("Please enter your username", "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        if (String::IsNullOrEmpty(txtComment->Text)) {
            MessageBox::Show("Please enter your review comment", "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        this->DialogResult = Windows::Forms::DialogResult::OK;
        this->Close();
    }

    System::Void ReviewForm::btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
        this->DialogResult = Windows::Forms::DialogResult::Cancel;
        this->Close();
    }

    void ReviewForm::InitializeComponent() {
        this->SuspendLayout();

        // Create controls
        this->txtUsername = gcnew TextBox();
        this->txtComment = gcnew RichTextBox();
        this->numRating = gcnew NumericUpDown();
        this->btnSubmit = gcnew Button();
        this->btnCancel = gcnew Button();
        this->lblUsername = gcnew Label();
        this->lblComment = gcnew Label();
        this->lblRating = gcnew Label();

        // Set control properties
        // Labels
        lblUsername->Text = "Username:";
        lblUsername->Location = Drawing::Point(20, 20);
        lblUsername->AutoSize = true;

        lblComment->Text = "Review:";
        lblComment->Location = Drawing::Point(20, 50);
        lblComment->AutoSize = true;

        lblRating->Text = "Rating (1-5):";
        lblRating->Location = Drawing::Point(20, 130);
        lblRating->AutoSize = true;

        // TextBoxes
        txtUsername->Location = Drawing::Point(100, 20);
        txtUsername->Size = Drawing::Size(200, 20);

        txtComment->Location = Drawing::Point(100, 50);
        txtComment->Size = Drawing::Size(200, 70);
        txtComment->Multiline = true;

        // NumericUpDown
        numRating->Location = Drawing::Point(100, 130);
        numRating->Size = Drawing::Size(50, 20);
        numRating->Minimum = 1;
        numRating->Maximum = 5;
        numRating->Value = 3;

        // Buttons
        btnSubmit->Text = "Submit";
        btnSubmit->Location = Drawing::Point(100, 160);
        btnSubmit->Size = Drawing::Size(75, 30);
        btnSubmit->Click += gcnew EventHandler(this, &ReviewForm::btnSubmit_Click);

        btnCancel->Text = "Cancel";
        btnCancel->Location = Drawing::Point(180, 160);
        btnCancel->Size = Drawing::Size(75, 30);
        btnCancel->Click += gcnew EventHandler(this, &ReviewForm::btnCancel_Click);

        // Form properties
        this->Text = "Add Review";
        this->ClientSize = Drawing::Size(320, 200);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
        this->MaximizeBox = false;
        this->MinimizeBox = false;
        this->StartPosition = FormStartPosition::CenterParent;

        // Add controls to form
        this->Controls->Add(lblUsername);
        this->Controls->Add(lblComment);
        this->Controls->Add(lblRating);
        this->Controls->Add(txtUsername);
        this->Controls->Add(txtComment);
        this->Controls->Add(numRating);
        this->Controls->Add(btnSubmit);
        this->Controls->Add(btnCancel);

        this->ResumeLayout(false);
        this->PerformLayout();
    }
}
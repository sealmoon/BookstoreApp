#pragma once

namespace BookstoreApp {
    public ref class ReviewForm : public System::Windows::Forms::Form {
    public:
        ReviewForm();
        ~ReviewForm();

        property System::String^ Username {
            System::String^ get() { return txtUsername->Text; }
        }

        property System::String^ Comment {
            System::String^ get() { return txtComment->Text; }
        }

        property int Rating {
            int get() { return System::Convert::ToInt32(numRating->Value); }
        }

    private:
        System::Windows::Forms::TextBox^ txtUsername;
        System::Windows::Forms::RichTextBox^ txtComment;
        System::Windows::Forms::NumericUpDown^ numRating;
        System::Windows::Forms::Button^ btnSubmit;
        System::Windows::Forms::Button^ btnCancel;
        System::Windows::Forms::Label^ lblUsername;
        System::Windows::Forms::Label^ lblComment;
        System::Windows::Forms::Label^ lblRating;

        System::ComponentModel::Container^ components;

        void InitializeComponent();
        System::Void btnSubmit_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e);
    };
}
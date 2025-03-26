#pragma once

namespace BookstoreApp {
    public ref class ReceiptForm : public System::Windows::Forms::Form {
    public:
        ReceiptForm(void);
        ~ReceiptForm();

        void AddItemToReceipt(System::String^ item, double price, int quantity);
        void SetContactInfo(System::String^ contactInfo);
        void CalculateAndDisplayTotal();

    private:
        System::Windows::Forms::RichTextBox^ rtbReceipt;
        System::Windows::Forms::Button^ btnClose;
        System::Windows::Forms::Label^ lblContactInfo;
        System::ComponentModel::Container^ components;

        double totalCost;

        void InitializeComponent();
        System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e);
    };
}
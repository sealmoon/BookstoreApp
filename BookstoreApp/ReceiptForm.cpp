#include "ReceiptForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace BookstoreApp {

    ReceiptForm::ReceiptForm(void) {
        InitializeComponent();
        totalCost = 0.0;

        // Set up the receipt header
        rtbReceipt->AppendText("BOOKSTORE RECEIPT\n");
        rtbReceipt->AppendText("--------------------------------\n");
        rtbReceipt->AppendText(String::Format("Date: {0}\n", DateTime::Now.ToString("f")));
        rtbReceipt->AppendText("--------------------------------\n");
        rtbReceipt->AppendText("ITEMS PURCHASED:\n\n");
    }

    ReceiptForm::~ReceiptForm() {
        if (components) {
            delete components;
        }
    }

    void ReceiptForm::AddItemToReceipt(System::String^ item, double price, int quantity) {
        // Add item details to receipt
        rtbReceipt->AppendText(String::Format("{0}\n", item));
        rtbReceipt->AppendText(String::Format("  Quantity: {0}\n", quantity));
        rtbReceipt->AppendText(String::Format("  Price: ${0:0.00}\n", price));
        rtbReceipt->AppendText("--------------------------------\n");

        // Update total
        totalCost += (price * quantity);
    }

    void ReceiptForm::SetContactInfo(System::String^ contactInfo) {
        lblContactInfo->Text = "CUSTOMER DETAILS:\n" + contactInfo;
    }

    void ReceiptForm::CalculateAndDisplayTotal() {
        // Add total to receipt
        rtbReceipt->AppendText("\n");
        rtbReceipt->AppendText(String::Format("TOTAL: ${0:0.00}\n", totalCost));
        rtbReceipt->AppendText("\nThank you for your purchase!\n");
    }

    System::Void ReceiptForm::btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Close();
    }

    void ReceiptForm::InitializeComponent() {
        this->components = gcnew System::ComponentModel::Container();

        this->rtbReceipt = gcnew System::Windows::Forms::RichTextBox();
        this->btnClose = gcnew System::Windows::Forms::Button();
        this->lblContactInfo = gcnew System::Windows::Forms::Label();

        // 
        // rtbReceipt
        // 
        this->rtbReceipt->Location = System::Drawing::Point(20, 20);
        this->rtbReceipt->Name = L"rtbReceipt";
        this->rtbReceipt->Size = System::Drawing::Size(550, 300);
        this->rtbReceipt->TabIndex = 0;
        this->rtbReceipt->ReadOnly = true;
        this->rtbReceipt->Font = gcnew System::Drawing::Font("Consolas", 10);

        // 
        // btnClose
        // 
        this->btnClose->Location = System::Drawing::Point(250, 400);
        this->btnClose->Name = L"btnClose";
        this->btnClose->Size = System::Drawing::Size(100, 30);
        this->btnClose->TabIndex = 1;
        this->btnClose->Text = L"Close";
        this->btnClose->UseVisualStyleBackColor = true;
        this->btnClose->Click += gcnew System::EventHandler(this, &ReceiptForm::btnClose_Click);

        // 
        // lblContactInfo
        // 
        this->lblContactInfo->Location = System::Drawing::Point(20, 330);
        this->lblContactInfo->Name = L"lblContactInfo";
        this->lblContactInfo->Size = System::Drawing::Size(550, 60);
        this->lblContactInfo->TabIndex = 2;
        this->lblContactInfo->Font = gcnew System::Drawing::Font("Arial", 9);

        // 
        // ReceiptForm
        // 
        this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
        this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
        this->ClientSize = System::Drawing::Size(600, 450);
        this->Controls->Add(this->lblContactInfo);
        this->Controls->Add(this->btnClose);
        this->Controls->Add(this->rtbReceipt);
        this->Name = L"ReceiptForm";
        this->Text = L"Purchase Receipt";
        this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
    }
}
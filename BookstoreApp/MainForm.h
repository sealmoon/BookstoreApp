#pragma once
#include "Book.h"
#include "Contact.h"
#include "Cart.h"

namespace BookstoreApp {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class MainForm : public System::Windows::Forms::Form {
    public:
        MainForm(void) {
            InitializeComponent();
            this->WindowState = FormWindowState::Maximized;
            books = gcnew System::Collections::Generic::List<Book^>();
            contacts = gcnew System::Collections::Generic::List<Contact^>();
        }

    protected:
        ~MainForm() {
            if (components) {
                delete components;
            }
        }

    private:
        System::Windows::Forms::ListBox^ listBoxBooks;
        System::Windows::Forms::Button^ btnAddBook;
        System::Windows::Forms::Button^ btnRemoveBook;
        System::Windows::Forms::Button^ btnPurchase;
        System::Windows::Forms::Button^ btnReview;
        System::Windows::Forms::ListBox^ listBoxFavorites;
        System::Windows::Forms::ListBox^ listBoxCart;
        System::Windows::Forms::Button^ btnCheckout;
        System::Windows::Forms::Button^ btnEditBook;
        System::Windows::Forms::Button^ btnAddToFavorites;
        System::Windows::Forms::Button^ btnRemoveFromFavorites;
        System::Windows::Forms::Button^ btnAddContact;
        System::Windows::Forms::Button^ btnRemoveContact;
        System::Windows::Forms::ListBox^ listBoxContacts;

        System::ComponentModel::Container^ components;
        System::Collections::Generic::List<Book^>^ books;
        System::Collections::Generic::List<Contact^>^ contacts;

        // Helper method declaration
        void RefreshBookList();

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            this->listBoxBooks = (gcnew System::Windows::Forms::ListBox());
            this->btnAddBook = (gcnew System::Windows::Forms::Button());
            this->btnRemoveBook = (gcnew System::Windows::Forms::Button());
            this->btnPurchase = (gcnew System::Windows::Forms::Button());
            this->btnReview = (gcnew System::Windows::Forms::Button());
            this->listBoxFavorites = (gcnew System::Windows::Forms::ListBox());
            this->listBoxCart = (gcnew System::Windows::Forms::ListBox());
            this->btnCheckout = (gcnew System::Windows::Forms::Button());
            this->btnEditBook = (gcnew System::Windows::Forms::Button());
            this->btnAddToFavorites = (gcnew System::Windows::Forms::Button());
            this->btnRemoveFromFavorites = (gcnew System::Windows::Forms::Button());
            this->listBoxContacts = (gcnew System::Windows::Forms::ListBox());
            this->btnAddContact = (gcnew System::Windows::Forms::Button());
            this->btnRemoveContact = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();

            // listBoxBooks
            this->listBoxBooks->FormattingEnabled = true;
            this->listBoxBooks->Location = System::Drawing::Point(50, 50);
            this->listBoxBooks->Name = L"listBoxBooks";
            this->listBoxBooks->Size = System::Drawing::Size(300, 200);
            this->listBoxBooks->TabIndex = 0;
            this->listBoxBooks->Anchor = static_cast<AnchorStyles>((AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Right));

            // btnAddBook
            this->btnAddBook->Location = System::Drawing::Point(50, 260);
            this->btnAddBook->Name = L"btnAddBook";
            this->btnAddBook->Size = System::Drawing::Size(75, 30);
            this->btnAddBook->TabIndex = 1;
            this->btnAddBook->Text = L"Add Book";
            this->btnAddBook->UseVisualStyleBackColor = true;
            this->btnAddBook->Click += gcnew System::EventHandler(this, &MainForm::btnAddBook_Click);

            // btnRemoveBook
            this->btnRemoveBook->Location = System::Drawing::Point(135, 260);
            this->btnRemoveBook->Name = L"btnRemoveBook";
            this->btnRemoveBook->Size = System::Drawing::Size(90, 30);
            this->btnRemoveBook->TabIndex = 2;
            this->btnRemoveBook->Text = L"Remove Book";
            this->btnRemoveBook->UseVisualStyleBackColor = true;
            this->btnRemoveBook->Click += gcnew System::EventHandler(this, &MainForm::btnRemoveBook_Click);

            // btnPurchase
            this->btnPurchase->Location = System::Drawing::Point(235, 260);
            this->btnPurchase->Name = L"btnPurchase";
            this->btnPurchase->Size = System::Drawing::Size(75, 30);
            this->btnPurchase->TabIndex = 3;
            this->btnPurchase->Text = L"Purchase";
            this->btnPurchase->UseVisualStyleBackColor = true;
            this->btnPurchase->Click += gcnew System::EventHandler(this, &MainForm::btnPurchase_Click);

            // btnReview
            this->btnReview->Location = System::Drawing::Point(320, 260);
            this->btnReview->Name = L"btnReview";
            this->btnReview->Size = System::Drawing::Size(75, 30);
            this->btnReview->TabIndex = 4;
            this->btnReview->Text = L"Review";
            this->btnReview->UseVisualStyleBackColor = true;
            this->btnReview->Click += gcnew System::EventHandler(this, &MainForm::btnReview_Click);

            // listBoxFavorites
            this->listBoxFavorites->FormattingEnabled = true;
            this->listBoxFavorites->Location = System::Drawing::Point(400, 50);
            this->listBoxFavorites->Name = L"listBoxFavorites";
            this->listBoxFavorites->Size = System::Drawing::Size(300, 200);
            this->listBoxFavorites->TabIndex = 5;
            this->listBoxFavorites->Anchor = static_cast<AnchorStyles>((AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Right));

            // listBoxCart
            this->listBoxCart->FormattingEnabled = true;
            this->listBoxCart->Location = System::Drawing::Point(750, 50);
            this->listBoxCart->Name = L"listBoxCart";
            this->listBoxCart->Size = System::Drawing::Size(300, 200);
            this->listBoxCart->TabIndex = 6;
            this->listBoxCart->Anchor = static_cast<AnchorStyles>((AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Right));

            // btnCheckout
            this->btnCheckout->Location = System::Drawing::Point(750, 260);
            this->btnCheckout->Name = L"btnCheckout";
            this->btnCheckout->Size = System::Drawing::Size(100, 30);
            this->btnCheckout->TabIndex = 7;
            this->btnCheckout->Text = L"Checkout";
            this->btnCheckout->UseVisualStyleBackColor = true;
            this->btnCheckout->Click += gcnew System::EventHandler(this, &MainForm::btnCheckout_Click);

            // btnEditBook
            this->btnEditBook->Location = System::Drawing::Point(50, 310);
            this->btnEditBook->Name = L"btnEditBook";
            this->btnEditBook->Size = System::Drawing::Size(100, 30);
            this->btnEditBook->TabIndex = 8;
            this->btnEditBook->Text = L"Edit Book";
            this->btnEditBook->UseVisualStyleBackColor = true;
            this->btnEditBook->Click += gcnew System::EventHandler(this, &MainForm::btnEditBook_Click);

            // btnAddToFavorites
            this->btnAddToFavorites->Location = System::Drawing::Point(400, 260);
            this->btnAddToFavorites->Name = L"btnAddToFavorites";
            this->btnAddToFavorites->Size = System::Drawing::Size(120, 30);
            this->btnAddToFavorites->TabIndex = 9;
            this->btnAddToFavorites->Text = L"Add to Favorites";
            this->btnAddToFavorites->UseVisualStyleBackColor = true;
            this->btnAddToFavorites->Click += gcnew System::EventHandler(this, &MainForm::btnAddToFavorites_Click);

            // btnRemoveFromFavorites
            this->btnRemoveFromFavorites->Location = System::Drawing::Point(530, 260);
            this->btnRemoveFromFavorites->Name = L"btnRemoveFromFavorites";
            this->btnRemoveFromFavorites->Size = System::Drawing::Size(120, 30);
            this->btnRemoveFromFavorites->TabIndex = 10;
            this->btnRemoveFromFavorites->Text = L"Remove Favorite";
            this->btnRemoveFromFavorites->UseVisualStyleBackColor = true;
            this->btnRemoveFromFavorites->Click += gcnew System::EventHandler(this, &MainForm::btnRemoveFromFavorites_Click);

            // listBoxContacts
            this->listBoxContacts->FormattingEnabled = true;
            this->listBoxContacts->Location = System::Drawing::Point(50, 400);
            this->listBoxContacts->Name = L"listBoxContacts";
            this->listBoxContacts->Size = System::Drawing::Size(300, 150);
            this->listBoxContacts->TabIndex = 11;

            // btnAddContact
            this->btnAddContact->Location = System::Drawing::Point(50, 560);
            this->btnAddContact->Name = L"btnAddContact";
            this->btnAddContact->Size = System::Drawing::Size(100, 30);
            this->btnAddContact->TabIndex = 12;
            this->btnAddContact->Text = L"Add Contact";
            this->btnAddContact->UseVisualStyleBackColor = true;
            this->btnAddContact->Click += gcnew System::EventHandler(this, &MainForm::btnAddContact_Click);

            // btnRemoveContact
            this->btnRemoveContact->Location = System::Drawing::Point(160, 560);
            this->btnRemoveContact->Name = L"btnRemoveContact";
            this->btnRemoveContact->Size = System::Drawing::Size(100, 30);
            this->btnRemoveContact->TabIndex = 13;
            this->btnRemoveContact->Text = L"Remove Contact";
            this->btnRemoveContact->UseVisualStyleBackColor = true;
            this->btnRemoveContact->Click += gcnew System::EventHandler(this, &MainForm::btnRemoveContact_Click);

            // MainForm
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1100, 650);
            this->Controls->Add(this->btnRemoveContact);
            this->Controls->Add(this->btnAddContact);
            this->Controls->Add(this->listBoxContacts);
            this->Controls->Add(this->btnRemoveFromFavorites);
            this->Controls->Add(this->btnAddToFavorites);
            this->Controls->Add(this->btnEditBook);
            this->Controls->Add(this->btnCheckout);
            this->Controls->Add(this->listBoxCart);
            this->Controls->Add(this->listBoxFavorites);
            this->Controls->Add(this->btnReview);
            this->Controls->Add(this->btnPurchase);
            this->Controls->Add(this->btnRemoveBook);
            this->Controls->Add(this->btnAddBook);
            this->Controls->Add(this->listBoxBooks);
            this->Name = L"MainForm";
            this->Text = L"Bookstore Application";
            this->ResumeLayout(false);
        }
#pragma endregion

    private:
        System::Void btnAddBook_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnRemoveBook_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnPurchase_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnReview_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnCheckout_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnEditBook_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnAddToFavorites_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnRemoveFromFavorites_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnAddContact_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void btnRemoveContact_Click(System::Object^ sender, System::EventArgs^ e);
    };
}
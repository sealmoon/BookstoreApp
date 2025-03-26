#include "MainForm.h"
#include "BookDetailsForm.h"
#include "ReceiptForm.h"
#include "ContactForm.h"
#include "Contact.h"
#include "Book.h"
#include "Cart.h"

using namespace System;
using namespace System::Windows::Forms;

namespace BookstoreApp {

    System::Void MainForm::btnAddBook_Click(System::Object^ sender, System::EventArgs^ e) {
        BookDetailsForm^ bookForm = gcnew BookDetailsForm(false);
        if (bookForm->ShowDialog() == Windows::Forms::DialogResult::OK) {
            Book^ newBook = bookForm->GetBook();
            if (newBook != nullptr) {
                books->Add(newBook);
                RefreshBookList();
            }
        }
    }

    System::Void MainForm::btnRemoveBook_Click(System::Object^ sender, System::EventArgs^ e) {
        if (listBoxBooks->SelectedIndex != -1) {
            books->RemoveAt(listBoxBooks->SelectedIndex);
            RefreshBookList();
        }
    }

    System::Void MainForm::btnPurchase_Click(System::Object^ sender, System::EventArgs^ e) {
        if (listBoxBooks->SelectedIndex != -1) {
            Book^ selectedBook = books[listBoxBooks->SelectedIndex];
            if (selectedBook->Quantity > 0) {
                selectedBook->UpdateQuantity(-1);
                listBoxCart->Items->Add(selectedBook->Title + " by " + selectedBook->Author);
                RefreshBookList();
            }
            else {
                MessageBox::Show("This book is out of stock!", "Error",
                    MessageBoxButtons::OK, MessageBoxIcon::Warning);
            }
        }
    }

    System::Void MainForm::btnReview_Click(System::Object^ sender, System::EventArgs^ e) {
        if (listBoxBooks->SelectedIndex != -1) {
            MessageBox::Show("Review for: " + listBoxBooks->SelectedItem->ToString(),
                "Review", MessageBoxButtons::OK, MessageBoxIcon::Information);
        }
    }

    System::Void MainForm::btnCheckout_Click(System::Object^ sender, System::EventArgs^ e) {
        if (listBoxCart->Items->Count == 0) {
            MessageBox::Show("Your cart is empty!", "Checkout",
                MessageBoxButtons::OK, MessageBoxIcon::Information);
            return;
        }

        if (listBoxContacts->SelectedIndex == -1) {
            MessageBox::Show("Please select a contact for this order.", "Checkout",
                MessageBoxButtons::OK, MessageBoxIcon::Warning);
            return;
        }

        ReceiptForm^ receiptForm = gcnew ReceiptForm();
        Cart^ tempCart = gcnew Cart();

        for each (String ^ item in listBoxCart->Items) {
            for each (Book ^ book in books) {
                String^ bookEntry = book->Title + " by " + book->Author;
                if (item == bookEntry) {
                    tempCart->AddBook(book, 1);
                    break;
                }
            }
        }

        for each (CartItem ^ item in tempCart->Items) {
            receiptForm->AddItemToReceipt(
                item->BookItem->Title + " by " + item->BookItem->Author,
                item->BookItem->Price,
                item->Quantity
            );
            item->BookItem->UpdateQuantity(-item->Quantity);
        }

        Contact^ selectedContact = contacts[listBoxContacts->SelectedIndex];
        String^ contactInfo = "Name: " + selectedContact->Name + "\n" +
            "Email: " + selectedContact->Email + "\n" +
            "Phone: " + selectedContact->PhoneNumber;
        receiptForm->SetContactInfo(contactInfo);

        receiptForm->CalculateAndDisplayTotal();
        if (receiptForm->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
            listBoxCart->Items->Clear();
            RefreshBookList();
        }
    }

    System::Void MainForm::btnEditBook_Click(System::Object^ sender, System::EventArgs^ e) {
        if (listBoxBooks->SelectedIndex == -1) {
            MessageBox::Show("Please select a book to edit", "Error",
                MessageBoxButtons::OK, MessageBoxIcon::Error);
            return;
        }

        Book^ selectedBook = books[listBoxBooks->SelectedIndex];
        BookDetailsForm^ bookForm = gcnew BookDetailsForm(true, selectedBook);
        if (bookForm->ShowDialog() == Windows::Forms::DialogResult::OK) {
            RefreshBookList();
        }
    }

    System::Void MainForm::btnAddToFavorites_Click(System::Object^ sender, System::EventArgs^ e) {
        if (listBoxBooks->SelectedIndex != -1) {
            Book^ selectedBook = books[listBoxBooks->SelectedIndex];
            String^ bookEntry = selectedBook->Title + " by " + selectedBook->Author;

            if (!listBoxFavorites->Items->Contains(bookEntry)) {
                listBoxFavorites->Items->Add(bookEntry);
                MessageBox::Show("Book added to favorites!", "Success",
                    MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
        }
    }

    System::Void MainForm::btnRemoveFromFavorites_Click(System::Object^ sender, System::EventArgs^ e) {
        if (listBoxFavorites->SelectedIndex != -1) {
            System::Windows::Forms::DialogResult result = MessageBox::Show(
                "Remove this book from favorites?", "Confirm",
                MessageBoxButtons::YesNo, MessageBoxIcon::Question);

            if (result == ::DialogResult::Yes) {
                listBoxFavorites->Items->RemoveAt(listBoxFavorites->SelectedIndex);
            }
        }
    }

    System::Void MainForm::btnAddContact_Click(System::Object^ sender, System::EventArgs^ e) {
        ContactForm^ contactForm = gcnew ContactForm(false);
        if (contactForm->ShowDialog() == ::DialogResult::OK) {
            Contact^ newContact = contactForm->GetContact();
            if (newContact != nullptr) {
                contacts->Add(newContact);
                listBoxContacts->Items->Add(newContact->Name + " - " + newContact->Email);
            }
        }
    }

    System::Void MainForm::btnRemoveContact_Click(System::Object^ sender, System::EventArgs^ e) {
        if (listBoxContacts->SelectedIndex != -1) {
            System::Windows::Forms::DialogResult result = MessageBox::Show(
                "Are you sure you want to delete this contact?", "Confirm Delete",
                MessageBoxButtons::YesNo, MessageBoxIcon::Question);

            if (result == ::DialogResult::Yes) {
                contacts->RemoveAt(listBoxContacts->SelectedIndex);
                listBoxContacts->Items->RemoveAt(listBoxContacts->SelectedIndex);
            }
        }
    }

    void MainForm::RefreshBookList() {
        listBoxBooks->Items->Clear();
        for each (Book ^ book in books) {
            listBoxBooks->Items->Add(book->Title + " by " + book->Author +
                " (Qty: " + book->Quantity + ")");
        }
    }
}
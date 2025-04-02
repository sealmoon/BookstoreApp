#pragma once
#include "Book.h"

namespace BookstoreApp {
    public ref class Receipt {
    private:
        System::Collections::Generic::List<Book^>^ purchasedBooks;
        System::DateTime purchaseDateTime;

    public:
        Receipt();

        property System::Collections::Generic::List<Book^>^ PurchasedBooks{
            System::Collections::Generic::List<Book^> ^ get() { return purchasedBooks; }
        }

            property System::DateTime PurchaseDateTime{
                System::DateTime get() { return purchaseDateTime; }
                void set(System::DateTime value) { purchaseDateTime = value; }
        }

        System::String^ GenerateReceipt();
        double CalculateTotal();
    };
}
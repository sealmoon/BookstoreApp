#pragma once
#include "Book.h"

namespace BookstoreApp {
    public ref class Receipt {
    public:
        property System::Collections::Generic::List<Book^>^ PurchasedBooks;
        property System::DateTime PurchaseDateTime;

        // Constructor
        Receipt();

        // Method to generate the receipt
        System::String^ GenerateReceipt();

        // Method to calculate the total cost
        double CalculateTotal();
    };
}

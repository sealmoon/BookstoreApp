#include "Receipt.h"

namespace BookstoreApp {
    // Constructor
    Receipt::Receipt() {
        PurchasedBooks = gcnew System::Collections::Generic::List<Book^>();
        PurchaseDateTime = System::DateTime::Now;
    }

    // Generate the receipt
    System::String^ Receipt::GenerateReceipt() {
        System::String^ receipt = "Receipt:\n";
        for each (Book ^ book in PurchasedBooks) {
            receipt += book->Title + " - $" + book->Price + "\n";
        }
        receipt += "Total: $" + CalculateTotal() + "\n";
        receipt += "Date: " + PurchaseDateTime.ToString();
        return receipt;
    }

    // Calculate the total cost
    double Receipt::CalculateTotal() {
        double total = 0.0;
        for each (Book ^ book in PurchasedBooks) {
            total += book->Price;
        }
        return total;
    }
}

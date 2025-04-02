#include "Receipt.h"
#include <msclr/marshal_cppstd.h>

using namespace System;
using namespace System::Text;

namespace BookstoreApp {
    Receipt::Receipt() {
        purchasedBooks = gcnew System::Collections::Generic::List<Book^>();
        purchaseDateTime = DateTime::Now;
    }

    System::String^ Receipt::GenerateReceipt() {
        StringBuilder^ sb = gcnew StringBuilder();

        sb->AppendLine("BOOKSTORE RECEIPT");
        sb->AppendLine("----------------------------------------");
        sb->AppendLine(String::Format("Date: {0}", purchaseDateTime.ToString("f")));
        sb->AppendLine("----------------------------------------");
        sb->AppendLine("ITEMS PURCHASED:");
        sb->AppendLine();

        for each(Book ^ book in purchasedBooks) {
            sb->AppendLine(String::Format("{0} - ${1:0.00}", book->Title, book->Price));
        }

        sb->AppendLine("----------------------------------------");
        sb->AppendLine(String::Format("TOTAL: ${0:0.00}", CalculateTotal()));
        sb->AppendLine("----------------------------------------");

        return sb->ToString();
    }

    double Receipt::CalculateTotal() {
        double total = 0.0;
        for each(Book ^ book in purchasedBooks) {
            total += book->Price;
        }
        return total;
    }
}
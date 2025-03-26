#include "Book.h"

namespace BookstoreApp {
    Book::Book(System::String^ title, System::String^ author, int pages, double price, int quantity) {
        Title = title;
        Author = author;
        Pages = pages;
        Price = price;
        Quantity = quantity;
    }

    void Book::AddPages(int numPages) {
        Pages += numPages;
    }

    void Book::RemovePages(int numPages) {
        Pages -= numPages;
    }

    void Book::UpdateQuantity(int change) {
        Quantity += change;
    }
}
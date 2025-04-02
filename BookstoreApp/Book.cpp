#include "Book.h"

namespace BookstoreApp {
    Book::Book(System::String^ title, System::String^ author, int pages, double price, int quantity) {
        this->title = title;
        this->author = author;
        this->pages = pages;
        this->price = price;
        this->quantity = quantity;
        this->reviews = gcnew System::Collections::Generic::List<Review^>();
    }

    Book::~Book() {
        // Clean up if needed
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

    void Book::AddReview(Review^ review) {
        reviews->Add(review);
    }
}
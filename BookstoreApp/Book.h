#pragma once
#include "Review.h"

namespace BookstoreApp {
    public ref class Book {
    private:
        System::String^ title;
        System::String^ author;
        int pages;
        double price;
        int quantity;
        System::Collections::Generic::List<Review^>^ reviews;

    public:
        Book(System::String^ title, System::String^ author, int pages, double price, int quantity);
        ~Book();

        property System::String^ Title {
            System::String^ get() { return title; }
            void set(System::String^ value) { title = value; }
        }

        property System::String^ Author {
            System::String^ get() { return author; }
            void set(System::String^ value) { author = value; }
        }

        property int Pages {
            int get() { return pages; }
            void set(int value) { pages = value; }
        }

        property double Price {
            double get() { return price; }
            void set(double value) { price = value; }
        }

        property int Quantity {
            int get() { return quantity; }
            void set(int value) { quantity = value; }
        }

        property System::Collections::Generic::List<Review^>^ Reviews {
            System::Collections::Generic::List<Review^>^ get() { return reviews; }
        }

        void AddPages(int numPages);
        void RemovePages(int numPages);
        void UpdateQuantity(int change);
        void AddReview(Review^ review);
    };
}
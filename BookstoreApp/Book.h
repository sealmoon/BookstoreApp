#pragma once

namespace BookstoreApp {
    public ref class Book {
    public:
        property System::String^ Title;
        property System::String^ Author;
        property int Pages;
        property double Price;
        property int Quantity;

        Book(System::String^ title, System::String^ author, int pages, double price, int quantity);
        void AddPages(int numPages);
        void RemovePages(int numPages);
        void UpdateQuantity(int change);
    };
}
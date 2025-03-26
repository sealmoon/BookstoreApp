#pragma once
#include "Book.h"

namespace BookstoreApp {
    public ref class CartItem {
    public:
        property Book^ BookItem;  // Changed from 'Book' to 'BookItem'
        property int Quantity;

        CartItem(Book^ book, int quantity) {
            this->BookItem = book;  // Updated to use BookItem
            this->Quantity = quantity;
        }
    };

    public ref class Cart {
    public:
        property System::Collections::Generic::List<CartItem^>^ Items;

        Cart();
        void AddBook(Book^ book, int quantity);
        void RemoveBook(Book^ book);
        void UpdateQuantity(Book^ book, int newQuantity);
        double CalculateTotal();
    };
}
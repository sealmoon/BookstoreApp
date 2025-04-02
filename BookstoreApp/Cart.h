#pragma once
#include "Book.h"

namespace BookstoreApp {
    public ref class CartItem {
    private:
        Book^ bookItem;
        int quantity;

    public:
        CartItem(Book^ book, int quantity);

        property Book^ BookItem{
            Book ^ get() { return bookItem; }
            void set(Book ^ value) { bookItem = value; }
        }

            property int Quantity{
                int get() { return quantity; }
                void set(int value) { quantity = value; }
        }
    };

    public ref class Cart {
    private:
        System::Collections::Generic::List<CartItem^>^ items;

    public:
        Cart();

        property System::Collections::Generic::List<CartItem^>^ Items{
            System::Collections::Generic::List<CartItem^> ^ get() { return items; }
        }

        void AddBook(Book^ book, int quantity);
        void RemoveBook(Book^ book);
        void UpdateQuantity(Book^ book, int newQuantity);
        double CalculateTotal();
    };
}
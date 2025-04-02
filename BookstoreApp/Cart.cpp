#include "Cart.h"

namespace BookstoreApp {
    CartItem::CartItem(Book^ book, int quantity)
        : bookItem(book), quantity(quantity) {
    }

    Cart::Cart() {
        items = gcnew System::Collections::Generic::List<CartItem^>();
    }

    void Cart::AddBook(Book^ book, int quantity) {
        for each(CartItem ^ item in items) {
            if (item->BookItem == book) {
                item->Quantity += quantity;
                return;
            }
        }
        items->Add(gcnew CartItem(book, quantity));
    }

    void Cart::RemoveBook(Book^ book) {
        for (int i = 0; i < items->Count; i++) {
            if (items[i]->BookItem == book) {
                items->RemoveAt(i);
                return;
            }
        }
    }

    void Cart::UpdateQuantity(Book^ book, int newQuantity) {
        for each(CartItem ^ item in items) {
            if (item->BookItem == book) {
                item->Quantity = newQuantity;
                return;
            }
        }
    }

    double Cart::CalculateTotal() {
        double total = 0.0;
        for each(CartItem ^ item in items) {
            total += (item->BookItem->Price * item->Quantity);
        }
        return total;
    }
}
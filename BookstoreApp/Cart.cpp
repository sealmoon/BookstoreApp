#include "Cart.h"

namespace BookstoreApp {
    Cart::Cart() {
        Items = gcnew System::Collections::Generic::List<CartItem^>();
    }

    void Cart::AddBook(Book^ book, int quantity) {
        for each(CartItem ^ item in Items) {
            if (item->BookItem == book) {  // Updated to use BookItem
                item->Quantity += quantity;
                return;
            }
        }
        Items->Add(gcnew CartItem(book, quantity));
    }

    void Cart::RemoveBook(Book^ book) {
        for (int i = 0; i < Items->Count; i++) {
            if (Items[i]->BookItem == book) {  // Updated to use BookItem
                Items->RemoveAt(i);
                return;
            }
        }
    }

    void Cart::UpdateQuantity(Book^ book, int newQuantity) {
        for each(CartItem ^ item in Items) {
            if (item->BookItem == book) {  // Updated to use BookItem
                item->Quantity = newQuantity;
                return;
            }
        }
    }

    double Cart::CalculateTotal() {
        double total = 0.0;
        for each(CartItem ^ item in Items) {
            total += (item->BookItem->Price * item->Quantity);  // Updated to use BookItem
        }
        return total;
    }
}
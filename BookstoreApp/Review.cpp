#include "Review.h"

namespace BookstoreApp {
    Review::Review(System::String^ username, System::String^ comment, int rating) {
        this->username = username;
        this->comment = comment;
        this->rating = rating;
        this->reviewDate = System::DateTime::Now;
    }
}
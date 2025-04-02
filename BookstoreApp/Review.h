#pragma once
#include <msclr/marshal_cppstd.h>

namespace BookstoreApp {
    public ref class Review {
    private:
        System::String^ username;
        System::String^ comment;
        int rating;
        System::DateTime reviewDate;

    public:
        Review(System::String^ username, System::String^ comment, int rating);

        property System::String^ Username {
            System::String^ get() { return username; }
        }

        property System::String^ Comment {
            System::String^ get() { return comment; }
        }

        property int Rating {
            int get() { return rating; }
        }

        property System::DateTime ReviewDate {
            System::DateTime get() { return reviewDate; }
        }
    };
}
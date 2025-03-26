#include "Contact.h"

namespace BookstoreApp {
    // Constructor
    Contact::Contact(System::String^ name, System::String^ phoneNumber, System::String^ email) {
        Name = name;
        PhoneNumber = phoneNumber;
        Email = email;
    }
}

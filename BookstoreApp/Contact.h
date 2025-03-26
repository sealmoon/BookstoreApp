#pragma once

namespace BookstoreApp {
    public ref class Contact {
    public:
        property System::String^ Name;
        property System::String^ PhoneNumber;
        property System::String^ Email;

        // Constructor
        Contact(System::String^ name, System::String^ phoneNumber, System::String^ email);
    };
}

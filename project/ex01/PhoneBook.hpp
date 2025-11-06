/* PhoneBook.hpp */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {
private:
    Contact contacts[MAX_CONTACTS];
    int index;

public:
    PhoneBook();
    ~PhoneBook();

    void add();
    void search();
};

#endif // PHONEBOOK_HPP

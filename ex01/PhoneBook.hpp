#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {
public:
    PhoneBook();
    ~PhoneBook();

    void add();
    void search() const;

private:
    Contact contacts[MAX_CONTACTS];
    int index;
};

#endif

#include <cctype> // provides isalpha, isdigit
#include <cstdlib> // provides atoi, exit, size_t
#include <iomanip> // provides setw
#include <iostream> // provides cin, cout, endl
#include <sstream> // provides ostringstream

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
    this->index = 0;

    std::cout << "\nWelcome to the 80s and their unbelievable technology!\n"
                 "My Awesome PhoneBook can store a maximum of " << MAX_CONTACTS << " contacts.\n"
                 "The program only accepts ADD, SEARCH and EXIT.\n" << std::endl;
}

PhoneBook::~PhoneBook() {
    std::cout << "\nGoodbye, contacts are lost forever! Ups...\n" << std::endl;
}

std::string promptNonEmptyInput(const std::string& prompt) {
    std::string input;

    while (true) {
        std::cout << prompt;

        if (!std::getline(std::cin, input)) {
            std::cout << "^D" << std::endl;
            std::exit(0);
        }

        if (!input.empty()) {
            return input;
        }
    }
}

bool isAlphasOnly(const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isalpha(static_cast<unsigned char>(str[i]))) {
            return false;
        }
    }
    return true;
}

bool isDigitsOnly(const std::string& str) {
    for (size_t i = 0; i < str.length(); ++i) {
        if (!std::isdigit(static_cast<unsigned char>(str[i]))) {
            return false;
        }
    }
    return true;
}

void PhoneBook::add() {
    if (this->index >= MAX_CONTACTS) {
        std::string input;

        std::cout << "\n\033[33mWarning! You already have " << MAX_CONTACTS << " contacts.\n"
                  << this->contacts[this->index % MAX_CONTACTS].getFirstName() << "'s contact will be overwritten.\033[0m\n\n"
                     "Would you like to continue anyway? (y or n) ";

        while (true) {
            if (!std::getline(std::cin, input)) {
                std::cout << "^D" << std::endl;
                std::exit(0);
            }

            if (input == "y" || input == "Y") {
                std::cout << std::endl;
                break;
            }
            else if (input == "n" || input == "N") {
                std::cout << std::endl;
                return;
            }
            else {
                std::cout << "\nYou can only answer y or n.\n"
                             "Would you like to continue anyway? (y or n) ";
            }
        }
    }

    std::cout << "\n\033[33mFields cannot be left empty.\033[0m\n" << std::endl;

    std::string firstName;
    while (true) {
        firstName = promptNonEmptyInput("First name:     ");

        if (isAlphasOnly(firstName)) {
            break;
        } else {
            std::cout << "\033[31mFirst name must contain only letters.\033[0m" << std::endl;
        }
    }

    std::string lastName;
    while (true) {
        lastName = promptNonEmptyInput("Last name:      ");

        if (isAlphasOnly(lastName)) {
            break;
        } else {
            std::cout << "\033[31mLast name must contain only letters.\033[0m" << std::endl;
        }
    }

    std::string nickname = promptNonEmptyInput("Nickname:       ");
    
    std::string phoneNumber;
    while (true) {
        phoneNumber = promptNonEmptyInput("Phone number:   ");

        if (isDigitsOnly(phoneNumber)) {
            break;
        } else {
            std::cout << "\033[31mPhone number must contain only digits.\033[0m" << std::endl;
        }
    }

    std::string darkestSecret = promptNonEmptyInput("Darkest secret: ");

    std::cout << std::endl;

    int contactIndex = this->index % MAX_CONTACTS;
    this->contacts[contactIndex].setFirstName(firstName);
    this->contacts[contactIndex].setLastName(lastName);
    this->contacts[contactIndex].setNickname(nickname);
    this->contacts[contactIndex].setPhoneNumber(phoneNumber);
    this->contacts[contactIndex].setDarkestSecret(darkestSecret);

    this->index++;
}

std::string formatString(const std::string& str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    else {
        std::ostringstream out;
        out << std::setw(10) << str;
        return out.str();
    }
}

void PhoneBook::search() const {
    if (this->index <= 0) {
        std::cout << "\033[33mNo contacts are stored. Try adding one first!\033[0m" << std::endl;
        return;
    }

    int numberOfContacts;
    if (this->index < MAX_CONTACTS) {
        numberOfContacts = this->index;
    } else {
        numberOfContacts = MAX_CONTACTS;
    }

    std::cout << "\n     Index|First Name| Last Name|  Nickname" << std::endl;

    for (int i = 0; i < numberOfContacts; ++i) {
        if (!this->contacts[i].getFirstName().empty()) {
            std::cout << std::setw(10) << (i + 1) << "|"
                      << formatString(this->contacts[i].getFirstName()) << "|"
                      << formatString(this->contacts[i].getLastName())  << "|"
                      << formatString(this->contacts[i].getNickname())  << std::endl;
        }
    }

    std::cout << "\nEnter the index of the contact to display: ";

    std::string input;

    while (true) {
        if (!std::getline(std::cin, input)) {
            std::cout << "^D" << std::endl;
            std::exit(0);
        }

        int index = std::atoi(input.c_str());

        if (!isDigitsOnly(input) || index < 1 || index > numberOfContacts) {
            std::cout << "\n\033[31mInvalid input.\033[0m\n" << std::endl;

            std::cout << "\n     Index|First Name| Last Name|  Nickname" << std::endl;
            
            for (int i = 0; i < numberOfContacts; ++i) {
                if (!this->contacts[i].getFirstName().empty()) {
                    std::cout << std::setw(10) << (i + 1) << "|"
                              << formatString(this->contacts[i].getFirstName()) << "|"
                              << formatString(this->contacts[i].getLastName())  << "|"
                              << formatString(this->contacts[i].getNickname())  << std::endl;
                }
            }

            std::cout << "\n\nYou must enter the index of a existing contact.\n"
                         "Enter the index of the contact to display: ";
        }
        else {
            std::cout << "\n     Index|First Name| Last Name|  Nickname|Phone Num.|Darkest S." << std::endl;

            std::cout << std::setw(10) << index << "|"
                      << formatString(this->contacts[index - 1].getFirstName()) << "|"
                      << formatString(this->contacts[index - 1].getLastName()) << "|"
                      << formatString(this->contacts[index - 1].getNickname()) << "|"
                      << formatString(this->contacts[index - 1].getPhoneNumber()) << "|"
                      << formatString(this->contacts[index - 1].getDarkestSecret()) << "\n" << std::endl;

            return;
        }
    }
}

/* main.cpp */

#include <cstdlib> // provides exit
#include <iostream> // provides cin, cout, endl

#include "PhoneBook.hpp"

int main() {
    PhoneBook phonebook;
    std::string input;

    while (true) {
        std::cout << "Enter a command > ";

        if (!std::getline(std::cin, input)) {
            std::cout << "^D" << std::endl;
            std::exit(0);
        }

        if (input == "ADD") {
            phonebook.add();
        }
        else if (input == "SEARCH") {
            phonebook.search();
        }
        else if (input == "EXIT") {
            break;
        }
        else {
            std::cout << "\033[31m" << "Unrecognized command" << "\033[0m" << std::endl;
        }
    }
}

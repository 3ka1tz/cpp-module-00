/* megaphone.cpp */

#include <cctype> // provides toupper
#include <iostream> // provides cout

// int std::toupper(int ch);

const char* DEFAULT_OUTPUT = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << DEFAULT_OUTPUT << "\n";
        return 0;
    }
    
    for (int i = 1; i < argc; ++i) {
        for (int j = 0; argv[i][j] != '\0'; ++j) {
            std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>((argv[i][j]))));
        }
    }
    std::cout << "\n";

    return 0;
}

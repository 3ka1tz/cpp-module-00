#include <iostream>

const std::string DEFAULT = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << DEFAULT << std::endl;

        return 0;
    }
    
    for (int i = 1; i < argc; ++i) {
        for (int j = 0; argv[i][j] != '\0'; ++j) {
            std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>((argv[i][j]))));
        }
    }
    std::cout << std::endl;

    return 0;
}

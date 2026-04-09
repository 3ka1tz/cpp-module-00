#include <cctype>
#include <iostream>

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
        return 0;
    }

    for (int i = 1; i < argc; ++i)
    {
        for (int j = 0; argv[i][j]; ++j)
            std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>((argv[i][j]))));
    }

    std::cout << '\n';
}

#include <iostream>

#include "Zombie.hpp"

int main() {
    int hordeSize = 5;

    if (hordeSize <= 0) {
        std::cerr << "Error: Horde size must be a positive integer." << std::endl;
        return 1;
    }
    
    Zombie* horde = zombieHorde(hordeSize, "Foo");
    
    if (horde) {
        for (int i = 0; i < hordeSize; ++i) {
            horde[i].announce();
        }

        delete[] horde;
    }

    return 0;
}

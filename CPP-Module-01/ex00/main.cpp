#include "Zombie.hpp"

int main() {
    Zombie* zombie = newZombie("Zombie1");
    zombie->announce();
    delete zombie;

    randomChump("Zombie2");

    return 0;
}

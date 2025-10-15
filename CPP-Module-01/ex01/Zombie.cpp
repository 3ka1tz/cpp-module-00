#include <iostream>

#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::Zombie(std::string name) : name_(name) {}

Zombie::~Zombie() {
    std::cout << name_ << " has been destructed." << std::endl;
}

void Zombie::setName(std::string name) {
    name_ = name;
}

void Zombie::announce() {
    std::cout << name_  << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

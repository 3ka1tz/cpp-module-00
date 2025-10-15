#include <iostream>

#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon& weapon) : name_(name), weapon_(weapon) {}

void HumanA::attack() const{
    std::cout << name_ << " attacks with their " << weapon_.getType() << std::endl;
}

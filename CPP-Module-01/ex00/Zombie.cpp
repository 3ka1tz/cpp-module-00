#include <iostream> // provides cout, endl

#include "Zombie.hpp"

Zombie::Zombie(std::string name) : m_name(name) {
    std::cout << "Wild " << m_name << " appeared!" << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Wild " << m_name << " fainted!" << std::endl;
}

void Zombie::announce() {
    std::cout << m_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

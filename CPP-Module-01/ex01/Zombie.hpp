#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie {
public:
    Zombie();
    Zombie(std::string name);
    ~Zombie();

    void setName(std::string name);

    void announce();

private:
    std::string name_;
};

Zombie* zombieHorde(int n, std::string name);

#endif

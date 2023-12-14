#include "Zombie.hpp"

void	Zombie::set_name(std::string name)
{
    if (name.empty())
        this->m_name = "anonymous";
    else
        this->m_name = name;
}

std::string Zombie::get_name(void)
{
    return (this->m_name);
}

void    Zombie::announce(void)
{
    std::cout << get_name();
    std::cout << ": ";
    std::cout << "BraiiiiiiinnnzzzZ...";
    std::cout << std::endl;
}

Zombie::~Zombie( void )
{
    std::cout << "destructor called.";
    std::cout << "for Name: " << Zombie::get_name();
    std::cout << std::endl;
}
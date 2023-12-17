#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
{
    m_name = name;
    m_weapon = weapon;
}

void    HumanA::attack(void)
{
    std::cout << m_name;
    std::cout << " attacks with their ";
    std::cout << m_weapon.getType();
    std::cout << std::endl;
}

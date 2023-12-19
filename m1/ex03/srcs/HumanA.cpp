#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):m_Refweapon(weapon)
{
	m_name = name;
}

void    HumanA::attack(void)
{
	std::cout << m_name;
	std::cout << " attacks with their ";
	std::cout << m_Refweapon.getType();
	std::cout << std::endl;
}

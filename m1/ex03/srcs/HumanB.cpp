#include "HumanB.hpp"

HumanB::HumanB(const std::string name)
{
	m_name = name;
	m_Ptrweapon = NULL;
}

void	HumanB::setWeapon(Weapon& name)
{
	m_Ptrweapon = &name;
}

void    HumanB::attack(void)
{
	std::cout << m_name;
	std::cout << " attacks with their ";
	if (m_Ptrweapon != NULL)
		std::cout << (*m_Ptrweapon).getType();
	else
		std::cout << "hip!";
	std::cout << std::endl;
}

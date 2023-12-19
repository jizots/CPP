#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB
{
public:
	void	attack();
	void	setWeapon(Weapon& name);

	HumanB(const std::string name);
	HumanB(void);

private:
	std::string	m_name;
	Weapon		*m_Ptrweapon;    
};

#endif

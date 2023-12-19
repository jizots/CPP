#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
public:
	void	attack(void);

	HumanA(std::string name, Weapon &weapon);

private:
	std::string	m_name;
	Weapon&		m_Refweapon;    
};

#endif

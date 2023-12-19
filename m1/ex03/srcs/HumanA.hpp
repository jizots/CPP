#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{
public:
	void	attack(void);

	HumanA(std::string name, Weapon &weapon);
	HumanA(std::string name);

private:
	std::string	m_name;
	Weapon&		m_Refweapon;    
};

#endif

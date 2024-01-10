#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap(void);
	DiamondTrap(const std::string& name);
	~DiamondTrap(void);
	// void	attack(void);
	void	whoAmI();

private:
	std::string	m_name;
};

#endif
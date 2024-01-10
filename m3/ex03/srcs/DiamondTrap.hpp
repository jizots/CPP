#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap(void);
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& other);
	~DiamondTrap(void);
	DiamondTrap& operator=(const DiamondTrap& rhs);
	void	attack(const std::string& target);
	void	whoAmI();

private:
	std::string	m_name;
};

#endif
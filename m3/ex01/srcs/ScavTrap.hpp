#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& other);
	~ScavTrap(void);
	ScavTrap&	operator=(const ScavTrap& rhs);
	virtual void	attack(const std::string& target);
	void			guardGata();
private:
};

#endif
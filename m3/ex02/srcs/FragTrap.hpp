#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& ohter);
	~FragTrap(void);
	void	highFivesGuys(void);
};

#endif
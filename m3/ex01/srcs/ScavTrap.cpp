#include "ScavTrap.hpp"
#include "Libft.hpp"

ScavTrap::ScavTrap(void)
	:ClapTrap("Scavless")
{
	set_Hit_points(100);
	set_Energy_points(50);
	set_Attack_damage(20);
	Libft::print_colored_string_endl("Scav Constructor(void) called", green);
}

ScavTrap::ScavTrap(const std::string& name)
	:ClapTrap(name)
{
	set_Hit_points(100);
	set_Energy_points(50);
	set_Attack_damage(20);
	Libft::print_colored_string_endl("Scav Constructor(with name) called", green);
}

ScavTrap::~ScavTrap(void)
{
	Libft::print_colored_string_endl("Scav Destructor called", red);
}

void	ScavTrap::attack(const std::string& target)
{
	if (get_Hit_points() == 0 || get_Energy_points() == 0)
	{
		Libft::print_colored_string_endl("Oh.. I have no Energy. Can't give damage.", yellow);
		return ;
	}
	set_Energy_points(get_Energy_points() - 1);
	std::cout << "ScavTrap " << get_name() << " " << "attacks " << target << ", ";
	std::cout << "causing " << get_Attack_damage() << " " << "points of damage!" << std::endl;
	std::cout << get_name() << ": loss 1 Energy points. Remaining: " << get_Energy_points() << std::endl;
}

void	ScavTrap::guardGata()
{
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

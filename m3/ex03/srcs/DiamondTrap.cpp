#include <iostream>
#include <string>
#include "Libft.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
	:m_name("DiamondLess")
{
	Libft::print_colored_string_endl("Diamond Default constructor called", green);
	this->FragTrap::set_Hit_points(this->FragTrap::get_Hit_points());
	this->ScavTrap::set_Energy_points(this->ScavTrap::get_Energy_points());
	this->FragTrap::set_Attack_damage(this->FragTrap::get_Attack_damage());
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ScavTrap(name + "_clap_name"),
	m_name(name)
{
	Libft::print_colored_string_endl("Diamond constructor called", green);
	this->FragTrap::set_Hit_points(this->FragTrap::get_Hit_points());
	this->ScavTrap::set_Energy_points(this->ScavTrap::get_Energy_points());
	this->FragTrap::set_Attack_damage(this->FragTrap::get_Attack_damage());
}

DiamondTrap::~DiamondTrap(void)
{
	Libft::print_colored_string_endl("Diamond Destructor called", red);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "ClapTrap's name: " << this->ScavTrap::get_name() << std::endl;
	std::cout << "DiamondTrap's name: " << this->m_name << std::endl;
}

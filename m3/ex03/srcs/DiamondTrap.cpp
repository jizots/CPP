#include <iostream>
#include <string>
#include "Libft.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
	:m_name("DiamondLess")
{
	Libft::print_colored_string_endl("Diamond Default constructor called", green);
	FragTrap::set_Hit_points(this->FragTrap::get_Hit_points());
	ScavTrap::set_Energy_points(this->ScavTrap::get_Energy_points());
	FragTrap::set_Attack_damage(this->FragTrap::get_Attack_damage());
}

DiamondTrap::DiamondTrap(const std::string& name)
	:ClapTrap(name + "_clap_name"),
	m_name(name)
{
	Libft::print_colored_string_endl("Diamond constructor(with name) called", green);
	// std::cout << this->ScavTrap::get_Hit_points() << ", " << this->ScavTrap::get_Energy_points() << ", " << this->ScavTrap::get_Attack_damage() << std::endl;
	// std::cout << this->FragTrap::get_Hit_points() << ", " << this->FragTrap::get_Energy_points() << ", " << this->FragTrap::get_Attack_damage() << std::endl;
	FragTrap::set_Hit_points(100);
	ScavTrap::set_Energy_points(50);
	FragTrap::set_Attack_damage(30);
	// std::cout << this->ScavTrap::get_Hit_points() << ", " << this->ScavTrap::get_Energy_points() << ", " << this->ScavTrap::get_Attack_damage() << std::endl;
	// std::cout << this->FragTrap::get_Hit_points() << ", " << this->FragTrap::get_Energy_points() << ", " << this->FragTrap::get_Attack_damage() << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	:ScavTrap(other.ScavTrap::get_name()),
	m_name(other.m_name)
{
	Libft::print_colored_string_endl("Diamond copy constructor called", green);
	FragTrap::set_Hit_points(FragTrap::get_Hit_points());
	ScavTrap::set_Energy_points(ScavTrap::get_Energy_points());
	FragTrap::set_Attack_damage(FragTrap::get_Attack_damage());
}

DiamondTrap::~DiamondTrap(void)
{
	Libft::print_colored_string_endl("Diamond Destructor called", red);
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& rhs)
{
	Libft::print_colored_string_endl("Copy assingment operator called. But can't change name!", red);
	set_Hit_points(rhs.get_Hit_points());
	set_Energy_points(rhs.get_Energy_points());
	set_Attack_damage(rhs.get_Attack_damage());
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "ClapTrap's name: " << this->ScavTrap::get_name() << std::endl;
	std::cout << "DiamondTrap's name: " << this->m_name << std::endl;
}

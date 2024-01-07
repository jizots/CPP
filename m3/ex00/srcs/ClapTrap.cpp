#include <iostream>
#include "ClapTrap.hpp"
#include "Libft.hpp"

ClapTrap::ClapTrap(void):
m_name("Nameless"),
m_Hit_points(10),
m_Energy_points(10),
m_Attack_damage(0)
{
}

ClapTrap::ClapTrap(const std::string& name):
m_name(name),
m_Hit_points(10),
m_Energy_points(10),
m_Attack_damage(0)
{
}

ClapTrap::ClapTrap(const ClapTrap& other)
	:m_Energy_points(other.m_Energy_points), m_Attack_damage(other.m_Attack_damage)
{
	Libft::print_colored_string_endl("Copy constructor called", blue);
	this->m_Hit_points = other.get_Hit_points();
}

ClapTrap::~ClapTrap(void)
{
	Libft::print_colored_string_endl("Destructor called", red);
}

ClapTrap& ClapTrap::operator=(const ClapTrap& rhs)
{
	(void)rhs;
	Libft::print_colored_string_endl("Copy assingment operator can't used", red);
	std::exit(EXIT_FAILURE);
}

void	ClapTrap::attack(const std::string& target)
{
	if (get_Hit_points() == 0 || get_Energy_points() == 0)
	{
		Libft::print_colored_string_endl("Oh.. I have no Energy. Can't give damage.", yellow);
		return ;
	}
	set_Energy_points(get_Energy_points() - 1);
	std::cout << "ClapTrap ";
	std::cout << get_name() << " ";
	std::cout << "attacks ";
	std::cout << target << ", ";
	takeDamage(get_Attack_damage());
	beRepaired(10);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "causing ";
	std::cout << amount << " ";
	std::cout << "points of damage!" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (get_Hit_points() == 0 || get_Energy_points() == 0)
	{
		Libft::print_colored_string_endl("Oh.. I have no Energy. Can't repair.", yellow);
		return ;
	}
	std::cout << "Hitpoint was repaired: form(" << get_Hit_points() << ") -> (";
	set_Hit_points(get_Hit_points() + amount);
	std::cout << get_Hit_points() << ")" << std::endl;
}

const std::string&	ClapTrap::get_name(void)
{
	return (m_name);
}

void	ClapTrap::set_Hit_points(const int points)
{
	m_Hit_points = points;
}

unsigned int	ClapTrap::get_Hit_points(void) const
{
	return (m_Hit_points);
}

void	ClapTrap::set_Energy_points(const unsigned int points)
{
	m_Energy_points = points;
}

unsigned int	ClapTrap::get_Energy_points(void) const
{
	return (m_Energy_points);
}

unsigned int	ClapTrap::get_Attack_damage(void) const
{
	return (m_Attack_damage);
}

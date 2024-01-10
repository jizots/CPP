#include <iostream>
#include "ClapTrap.hpp"
#include "Libft.hpp"

ClapTrap::ClapTrap(void):
	m_name("Nameless"),
	m_Hit_points(10),
	m_Energy_points(10),
	m_Attack_damage(0)
{
	Libft::print_colored_string_endl("Constructor(void) called", green);
}

ClapTrap::ClapTrap(const std::string& name):
	m_name(name),
	m_Hit_points(10),
	m_Energy_points(10),
	m_Attack_damage(0)
{
	Libft::print_colored_string_endl("Constructor(with name) called", green);
}

ClapTrap::ClapTrap(const ClapTrap& other)
	:m_Hit_points(other.get_Hit_points()),
	m_Energy_points(other.get_Energy_points()),
	m_Attack_damage(other.get_Attack_damage())
{
	Libft::print_colored_string_endl("Copy constructor called", blue);
}

ClapTrap::~ClapTrap(void)
{
	Libft::print_colored_string_endl("Destructor called", red);
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& rhs)
{
	Libft::print_colored_string_endl("Copy assingment operator called. But can't change name!", red);
	m_Hit_points = rhs.get_Hit_points();
	m_Energy_points = rhs.get_Energy_points();
	m_Attack_damage = rhs.get_Attack_damage();
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (get_Hit_points() == 0 || get_Energy_points() == 0)
	{
		Libft::print_colored_string_endl("Oh.. I have no Energy. Can't give damage.", yellow);
		return ;
	}
	set_Energy_points(get_Energy_points() - 1);
	std::cout << "ClapTrap " << get_name() << " " << "attacks " << target << ", ";
	std::cout << "causing " << get_Attack_damage() << " " << "points of damage!" << std::endl;
	std::cout << get_name() << ": loss 1 Energy points. Remaining: " << get_Energy_points() << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	long int	remainHP;

	remainHP = static_cast<long int>(get_Hit_points()) - amount;
	if (remainHP < 0)
		set_Hit_points(0);
	else
		set_Hit_points(remainHP);
	std::cout << "ClapTrap " << get_name() << " take " << amount << " Damage. Remaining: " << get_Hit_points() << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	long int	remainHP;

	if (get_Hit_points() == 0 || get_Energy_points() == 0)
	{
		Libft::print_colored_string_endl("Oh.. I have no Energy. Can't repair.", yellow);
		return ;
	}
	set_Energy_points(get_Energy_points() - 1);
	std::cout << get_name() <<  ": Hitpoint was repaired: form(" << get_Hit_points() << ") -> (";
	remainHP = static_cast<long int>(get_Hit_points()) + amount;
	if (remainHP > UINT32_MAX)
		set_Hit_points(UINT32_MAX);
	else
		set_Hit_points(get_Hit_points() + amount);
	std::cout << get_Hit_points() << ")" << std::endl;
	std::cout << get_name() << ": loss 1 Energy points. Remaining: " << get_Energy_points() << std::endl;
}

const std::string&	ClapTrap::get_name(void) const
{
	return (m_name);
}

void	ClapTrap::set_Hit_points(const unsigned int points)
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

void	ClapTrap::set_Attack_damage(const unsigned int points)
{
	m_Attack_damage = points;
}

unsigned int	ClapTrap::get_Attack_damage(void) const
{
	return (m_Attack_damage);
}

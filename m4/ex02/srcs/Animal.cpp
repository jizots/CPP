#include "Animal.hpp"
#include "Libft.hpp"

Animal::Animal(void)
	:m_type("Animal")
{
	Libft::print_colored_string_endl("Animal Default constructor called", green);
}

Animal::Animal(const std::string& type)
	:m_type(type)
{
	Libft::print_colored_string_endl("Animal constructor(with type) called", green);
}

Animal::Animal(const Animal& other)
	:m_type(other.getType())
{
	Libft::print_colored_string_endl("Animal copy constructor called", green);
}

Animal::~Animal(void)
{
	Libft::print_colored_string_endl("Animal destructor called", red);
}

Animal&	Animal::operator=(const Animal& rhs)
{
	Libft::print_colored_string_endl("Animal copy assignment operator called", blue);
	m_type = rhs.getType();
	return (*this);
}

std::string&	Animal::getType(void) const
{
	return (const_cast<std::string&>(m_type));
}

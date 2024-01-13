#include "WrongAnimal.hpp"
#include "Libft.hpp"

WrongAnimal::WrongAnimal(void)
	:m_type("WrongAnimal")
{
	Libft::print_colored_string_endl("WrongAnimal Default constructor called", green);
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
	:m_type(other.getType())
{
	Libft::print_colored_string_endl("WrongAnimal copy constructor called", green);
}

WrongAnimal::~WrongAnimal(void)
{
	Libft::print_colored_string_endl("WrongAnimal destructor called", red);
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& rhs)
{
	Libft::print_colored_string_endl("WrongAnimal copy assignment operator called", blue);
	m_type = rhs.getType();
	return (*this);
}

std::string&	WrongAnimal::getType(void) const
{
	return (const_cast<std::string&>(m_type));
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << Libft::get_colored_string("( ✌︎'ω')✌︎", red) << std::endl;
}
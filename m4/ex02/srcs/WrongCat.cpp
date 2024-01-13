#include "WrongCat.hpp"
#include "Libft.hpp"

WrongCat::WrongCat(void)
{
	Libft::print_colored_string_endl("WrongCat Default constructor called", green);
	m_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other)
{
	Libft::print_colored_string_endl("WrongCat copy constructor called", green);
	m_type = other.getType();
}

WrongCat::~WrongCat(void)
{
	Libft::print_colored_string_endl("WrongCat destructor called", red);
}

WrongCat&	WrongCat::operator=(const WrongCat& rhs)
{
	Libft::print_colored_string_endl("WrongCat copy assignment operator called", blue);
	m_type = rhs.getType();
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << Libft::get_colored_string("nya~", yellow) << std::endl;
}
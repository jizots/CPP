#include "Dog.hpp"
#include "Libft.hpp"

Dog::Dog(void)
{
	Libft::print_colored_string_endl("Dog Default constructor called", green);
	m_type = "Dog";
}

Dog::Dog(const Dog& other)
{
	Libft::print_colored_string_endl("Dog copy constructor called", green);
	m_type = other.getType();
}

Dog::~Dog(void)
{
	Libft::print_colored_string_endl("Dog destructor called", red);
}

Dog&	Dog::operator=(const Dog& rhs)
{
	Libft::print_colored_string_endl("Dog copy assignment operator called", green);
	m_type = rhs.getType();
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << Libft::get_colored_string("bow!!", brown) << std::endl;
}

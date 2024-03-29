#include "Cat.hpp"
#include "Libft.hpp"

Cat::Cat(void)
	:Animal("Cat")
{
	Libft::print_colored_string_endl("Cat Default constructor called", green);
}

Cat::Cat(const Cat& other)
{
	Libft::print_colored_string_endl("Cat copy constructor called", green);
	m_type = other.getType();
}

Cat::~Cat(void)
{
	Libft::print_colored_string_endl("Cat destructor called", red);
}

Cat&	Cat::operator=(const Cat& rhs)
{
	Libft::print_colored_string_endl("Cat copy assignment operator called", blue);
	m_type = rhs.getType();
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << Libft::get_colored_string("nya~", yellow) << std::endl;
}
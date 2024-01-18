#include "Dog.hpp"
#include "Libft.hpp"

Dog::Dog(void)
	:Animal("Dog")
{
	Libft::print_colored_string_endl("Dog Default constructor called", green);
	m_brain = new(std::nothrow) Brain();
	if (m_brain == NULL)
	{
		Libft::print_colored_string_endl("allocation failed.", red);
		std::exit(EXIT_FAILURE);
	}
}

Dog::Dog(const Dog& other)
{
	Libft::print_colored_string_endl("Dog copy constructor called", green);
	m_type = other.getType();
	m_brain = new(std::nothrow) Brain(*other.m_brain);
	if (m_brain == NULL)
	{
		Libft::print_colored_string_endl("allocation failed.", red);
		std::exit(EXIT_FAILURE);
	}
}

Dog::~Dog(void)
{
	Libft::print_colored_string_endl("Dog destructor called", red);
	delete m_brain;
}

Dog&	Dog::operator=(const Dog& rhs)
{
	Libft::print_colored_string_endl("Dog copy assignment operator called", blue);
	m_type = rhs.getType();
	m_brain = rhs.m_brain;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << Libft::get_colored_string("bow!!", brown) << std::endl;
}

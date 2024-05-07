#include "Cat.hpp"
#include "Libft.hpp"

Cat::Cat(void)
	:Animal("Cat")
{
	Libft::print_colored_string_endl("Cat Default constructor called", green);
	m_brain = new(std::nothrow) Brain();
	if (m_brain == NULL)
	{
		Libft::print_colored_string_endl("allocation failed.", red);
		std::exit(EXIT_FAILURE);
	}
}

Cat::Cat(const Cat& other)
	:Animal(other.getType())
{
	Libft::print_colored_string_endl("Cat copy constructor called", green);
	m_brain = new(std::nothrow) Brain(*other.m_brain);
	if (m_brain == NULL)
	{
		Libft::print_colored_string_endl("allocation failed.", red);
		std::exit(EXIT_FAILURE);
	}
}

Cat::~Cat(void)
{
	Libft::print_colored_string_endl("Cat destructor called", red);
	delete m_brain;
}

Cat&	Cat::operator=(const Cat& rhs)
{
	Libft::print_colored_string_endl("Cat copy assignment operator called", blue);
	if (this == &rhs)
		;
	else
	{
		m_type = rhs.getType();
		delete m_brain;
		m_brain = new Brain(*rhs.m_brain);
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << Libft::get_colored_string("nya~", yellow) << std::endl;
}

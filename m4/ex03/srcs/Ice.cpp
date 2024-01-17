#include "Ice.hpp"
#include "Libft.hpp"

Ice::Ice(void)
	:AMateria("ice")
{
	Libft::print_colored_string_endl("Ice default constructor called", green);
}

Ice::Ice(const Ice& other)
	:AMateria(other.getType())
{
	Libft::print_colored_string_endl("Ice copy constructor(with type) called", green);
}

Ice::~Ice(void)
{
	Libft::print_colored_string_endl("Ice Destructor called", red);
}

Ice&	Ice::operator=(const Ice& rhs)
{
	Libft::print_colored_string_endl("Ice copy assingnment called", blue);
	m_type = rhs.m_type;
	return (*this);
}

AMateria*	Ice::clone() const
{
	AMateria	*tmp = new(std::nothrow) Ice();

	if (tmp == NULL)
	{
		Libft::print_colored_string_endl("Ice allocation failed.", red);
		std::exit(EXIT_FAILURE);
	}
	return (tmp);
}
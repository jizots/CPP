#include "Cure.hpp"
#include "Libft.hpp"

Cure::Cure(void)
	:AMateria("cure")
{
	Libft::print_colored_string_endl("Cure default constructor called", green);
}

Cure::Cure(const Cure& other)
	:AMateria(other.getType())
{
	Libft::print_colored_string_endl("Cure copy constructor(with type) called", green);
}

Cure::~Cure(void)
{
	Libft::print_colored_string_endl("Cure Destructor called", red);
}

Cure&	Cure::operator=(const Cure& rhs)
{
	Libft::print_colored_string_endl("Cure copy assingnment called", blue);
	m_type = rhs.m_type;
	return (*this);
}

AMateria*	Cure::clone() const
{
	AMateria	*tmp = new(std::nothrow) Cure();

	if (tmp == NULL)
	{
		Libft::print_colored_string_endl("Cure allocation failed.", red);
		std::exit(EXIT_FAILURE);
	}
	return (tmp);
}

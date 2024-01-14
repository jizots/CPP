#include "AMateria.hpp"
#include "Libft.hpp"

//AMateria is pure abstract class, Constructor and Destructor is needed?
AMateria::AMateria(void)
	:m_type("undefined_AMateria")
{
	Libft::print_colored_string_endl("AMateria default constructor called", green);
}

AMateria::AMateria(std::string const & type)
	:m_type(type)
{
	Libft::print_colored_string_endl("AMateria constructor(with type) called", green);
}

AMateria::AMateria(const AMateria& other)
	:m_type(other.getType())
{
	Libft::print_colored_string_endl("AMateria copy constructor(with type) called", green);
}

AMateria::~AMateria(void)
{
	Libft::print_colored_string_endl("AMateria Destructor called", red);
}

AMateria&	AMateria::operator=(const AMateria& rhs)
{
	Libft::print_colored_string_endl("AMateria copy assingnment called", blue);
	m_type = rhs.m_type;
}

std::string const&	AMateria::getType() const
{
	return (m_type);
}

void	AMateria::use(ICharacter& target)//Must get target name
{
	if (getType() == "ice")
		std::cout << "* shoots an ice bolt at " << name << "*" << std::endl;
	else if (getType() == "cure")
		std::cout << "* heals " << name << "'s wounds *" << std::endl;
}

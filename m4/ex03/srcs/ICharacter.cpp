#include "ICharacter.hpp"
#include "Libft.hpp"

ICharacter::ICharacter(void)
	:m_name("Nameless")
{
	Libft::print_colored_string_endl("ICharacter default constructor called", green);
}

ICharacter::ICharacter(const std::string& name)
	:m_name(name)
{
	Libft::print_colored_string_endl("ICharacter constructor(with name) called", green);
}

ICharacter::ICharacter(const ICharacter& other)
	:m_name(other.m_name)
{
	Libft::print_colored_string_endl("ICharacter copy constructor(with type) called", green);
}

ICharacter::~ICharacter()
{
	Libft::print_colored_string_endl("ICharacter Destructor called", red);
}

ICharacter&	ICharacter::operator=(const ICharacter& rhs)
{
	Libft::print_colored_string_endl("ICharacter copy assingnment called", blue);
	m_name = rhs.m_name;
}
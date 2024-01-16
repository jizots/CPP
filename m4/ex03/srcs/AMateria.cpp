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
	for (size_t i = 0; i < m_sizeFloor; ++i)
		delete m_listFloor[i];
	delete [] m_listFloor;
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

void	AMateria::use(ICharacter& target)
{
	if (getType() == "ice")
		std::cout << "* shoots an ice bolt at " << target.ICharacter::getName() << "*" << std::endl;
	else if (getType() == "cure")
		std::cout << "* heals " << target.ICharacter::getName() << "'s wounds *" << std::endl;
}

void	AMateria::addToFloor(AMateria *m)
{
	size_t	i = 0;

	while (i < m_sizeFloor)
	{
		if (m_listFloor[i++] == m)
			return ;
	}
	AMateria **newlist = new(std::nothrow) AMateria*[m_sizeFloor + 1];
	if (newlist == NULL)
	{
		Libft::print_colored_string_endl("addToList allocation failed.", red);
		std::exit(EXIT_FAILURE);
	}
	i = 0;
	for ( ;i < m_sizeFloor; ++i)
		newlist[i] = m_listFloor[i];
	newlist[i] = m;
	m_sizeFloor += 1;
	delete [] m_listFloor;
	m_listFloor = newlist;
}


bool	AMateria::isFloor(const AMateria* m)
{
	for (size_t i = 0; i < m_sizeFloor; ++i)
	{
		if (m == m_listFloor[i])
			return (true);
	}
	return (false);
}

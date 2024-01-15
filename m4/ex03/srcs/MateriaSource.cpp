#include "MateriaSource.hpp"
#include "Libft.hpp"

MateriaSource::MateriaSource(void)
{
	Libft::print_colored_string_endl("MateriaSource default constructor called", green);
	for (int i = 0; i < 4; ++i)
		m_slot[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	Libft::print_colored_string_endl("MateriaSource copy constructor called", green);
	
}

MateriaSource::~MateriaSource()
{
	Libft::print_colored_string_endl("MateriaSource Destructor called", red);
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{

}

void		MateriaSource::learnMateria(AMateria*)
{

}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	
}

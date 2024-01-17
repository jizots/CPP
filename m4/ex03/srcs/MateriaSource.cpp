#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
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
	(*this) = other;
}

MateriaSource::~MateriaSource()
{
	Libft::print_colored_string_endl("MateriaSource Destructor called", red);
	clearSlot();
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	Libft::print_colored_string_endl("MateriaSource copy assignment operator called", blue);
	clearSlot();
	copySlot(rhs);
	return (*this);
}

void		MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL)
	{
		Libft::print_colored_string_endl("MateriaSource Materia is NULL!", yellow);
		return ;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (m_slot[i] == NULL)
		{
			m_slot[i] = m;
			return ;
		}
	}
	Libft::print_colored_string_endl("MateriaSource slot is FULL! Drop to Floor", yellow);
	AMateria::addToFloor(m);
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (m_slot[i] != NULL && m_slot[i]->getType() == type)
			return (m_slot[i]->clone());
	}
	return (NULL);
}

void	MateriaSource::copySlot(const MateriaSource& src)
{
	for (int i = 0; i < 4; ++i)
	{
		if (src.m_slot[i] != NULL)
			m_slot[i] = src.m_slot[i]->clone();
		else
			m_slot[i] = NULL;
	}
}

void	MateriaSource::clearSlot(void)//is correct? if have address with non-new, it's cause crash.
{
	for (int i = 0; i < 4; ++i)
		delete m_slot[i];
	for (int i = 0; i < 4; ++i)
		m_slot[i] = NULL;
}

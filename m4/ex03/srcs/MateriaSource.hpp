#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMAteriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& other);
	virtual ~MateriaSource(void);
	MateriaSource&		operator=(const MateriaSource& rhs);
	virtual void		learnMateria(AMateria*);
	virtual AMateria*	createMateria(std::string const & type);

private:
	AMateria*	m_slot[4];

};


#endif
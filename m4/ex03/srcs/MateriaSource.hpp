#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource(void);
	MateriaSource(const MateriaSource& other);
	virtual ~MateriaSource(void);
	MateriaSource&		operator=(const MateriaSource& rhs);
	virtual void		learnMateria(AMateria* m);
	virtual AMateria*	createMateria(std::string const & type);
	void	copySlot(const MateriaSource& src);
	void	clearSlot(void);

private:
	AMateria*	m_slot[4];

};

#endif
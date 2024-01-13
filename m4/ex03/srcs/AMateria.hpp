#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"

class AMateria
{
public:
	AMateria(void);
	AMateria(const AMateria& other);
	AMateria(std::string const & type);
	~AMateria(void);
	AMateria&	operator=(const AMateria& rhs);
	std::string const&	getType() const; //Returns the materia type
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);

protected:

private:

};

#endif
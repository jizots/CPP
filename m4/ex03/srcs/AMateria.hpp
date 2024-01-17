#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"
class ICharacter;

class AMateria
{
public:
	AMateria(void);
	AMateria(const AMateria& other);
	AMateria(std::string const & type);
	virtual ~AMateria(void);
	AMateria&	operator=(const AMateria& rhs);
	std::string const&	getType() const;
	virtual AMateria*	clone() const = 0;
	virtual void		use(ICharacter& target);
	static void		addToFloor(AMateria *m);
	static bool		isFloor(const AMateria* m);
	static void		clearFloor(void);

protected:
	std::string			m_type;
	static AMateria		**m_listFloor;
	static size_t		m_sizeFloor;

private:

};

#endif
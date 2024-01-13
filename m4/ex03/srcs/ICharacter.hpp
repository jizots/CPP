#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include <string>
# include "AMateria.hpp"

class ICharacter
{
public:
	ICharacter(void);
	ICharacter(const ICharacter& other);
	virtual ~ICharacter() {}
	ICharacter&	operator=(const ICharacter& rhs);
	virtual std::string const&	getName() const = 0;
	virtual void	equip(AMateria* m) = 0;
	virtual void	unequip(int idx) = 0;
	virtual void	use(int idx, ICharacter& target) = 0;

private:

};

#endif
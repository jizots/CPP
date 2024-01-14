#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "ICharacter.hpp"

class Character : public ICharacter
{
public:
	Character(void);
	Character(const std::string& name);
	Character(const Character& other);
	virtual ~Character();
	Character&	operator=(const Character& rhs);
	virtual std::string const&	getName() const;
	virtual void	equip(AMateria* m);
	virtual void	unequip(int idx);
	virtual void	use(int idx, Character& target);

private:

};

#endif
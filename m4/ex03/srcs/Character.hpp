#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
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
	virtual void	use(int idx, ICharacter& target);
	void			copySlot(const Character& src);
	void			clearSlot(void);

private:
	AMateria	*m_slot[4];

};

#endif
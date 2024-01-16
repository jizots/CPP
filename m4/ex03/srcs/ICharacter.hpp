#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"

class ICharacter
{
public:
	ICharacter(void);
	ICharacter(const std::string& name);
	ICharacter(const ICharacter& other);
	virtual ~ICharacter() {}
	ICharacter&	operator=(const ICharacter& rhs);
	virtual std::string const&	getName() const = 0;
	virtual void	equip(AMateria* m) = 0;
	virtual void	unequip(int idx) = 0;
	virtual void	use(int idx, ICharacter& target) = 0;

protected:
	std::string	m_name;
	AMateria	*m_slot[4];
	AMateria	*m_listDelete;

private:
};

#endif
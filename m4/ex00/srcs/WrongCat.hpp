#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "Animal.hpp"

class WrongCat : public Animal
{
public:
	WrongCat(void);
	WrongCat(const WrongCat& other);
	~WrongCat(void);
	WrongCat&	operator=(const WrongCat& rhs);
	virtual void	makeSound(void) const;

private:

};

#endif
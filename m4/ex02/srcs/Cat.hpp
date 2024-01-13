#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat& other);
	virtual ~Cat(void);
	Cat&	operator=(const Cat& rhs);
	virtual void	makeSound(void) const;

private:
	Brain	*m_brain;

};

#endif
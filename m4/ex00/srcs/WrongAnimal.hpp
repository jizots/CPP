#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
public:
	WrongAnimal(void);
	WrongAnimal(const WrongAnimal& other);
	virtual ~WrongAnimal(void);
	WrongAnimal&	operator=(const WrongAnimal& rhs);
	std::string&	getType(void) const;
	virtual void	makeSound(void) const;

protected:
	std::string	m_type;
private:

};

#endif
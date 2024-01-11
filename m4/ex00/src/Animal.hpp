#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
public:
	Animal(void);
	Animal(const Animal& other);
	virtual ~Animal(void);
	Animal&	operator=(const Animal& rhs);
	std::string&	getType(void) const;

protected:
	std::string	m_type;
private:

};

#endif
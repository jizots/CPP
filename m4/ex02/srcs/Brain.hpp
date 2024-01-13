#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
public:
	Brain(void);
	Brain(const Brain& other);
	~Brain(void);
	Brain&	operator=(const Brain& rhs);

private:
	std::string	m_brain[100];
};

#endif
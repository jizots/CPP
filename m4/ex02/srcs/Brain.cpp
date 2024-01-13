#include "Brain.hpp"
#include "Libft.hpp"

Brain::Brain(void)
{
	Libft::print_colored_string_endl("Brain Default constructor called", green);
}

Brain::Brain(const Brain& other)
{
	Libft::print_colored_string_endl("Brain Copy constructor called", green);
	for (size_t i = 0; i < 100; ++i)
		m_brain[i] = other.m_brain[i];
}

Brain::~Brain(void)
{
	Libft::print_colored_string_endl("Brain Destructor called", red);
}

Brain&	Brain::operator=(const Brain& rhs)
{
	Libft::print_colored_string_endl("Brain copy assingment operator called", blue);
	for (size_t i = 0; i < 100; ++i)
		m_brain[i] = rhs.m_brain[i];
	return(*this);
}
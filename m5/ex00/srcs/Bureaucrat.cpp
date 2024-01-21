#include "Bureaucrat.hpp"
#include "Libft.hpp"

Bureaucrat::Bureaucrat(void)
	:m_name("Nameless")
{
	Libft::print_colored_string_endl("Bureaucrat default constructor called", green);
	verifyGrade(150);
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
	:m_name(name)
{
	Libft::print_colored_string_endl("Bureaucrat constructor called", green);
	verifyGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	*this = other;
}

Bureaucrat::~Bureaucrat(void)
{
	Libft::print_colored_string_endl("Bureaucrat Destructor called", red);
}

void	Bureaucrat::setGrade(int grade)
{
	if (150 < grade)
		throw (GradeTooLowException(getName(), getGrade()));
	else if (grade < 1)
		throw (GradeTooHighException(getName(), getGrade()));
	else
		m_grade = grade;
}

void	Bureaucrat::verifyGrade(int grade)
{
	try
	{
		setGrade(grade);
		Libft::print_colored_string_endl("Success to be promoted!?", magenta);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{
		m_name = rhs.getName();
		verifyGrade(rhs.getGrade());
	}
	return (*this);
}

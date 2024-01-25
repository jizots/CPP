#include "Bureaucrat.hpp"
#include "Libft.hpp"

Bureaucrat::Bureaucrat(void)
	:m_name("Nameless"),
	m_grade(150)
{
	Libft::print_colored_string_endl("Bureaucrat default constructor called", green);
	verifyGrade(150);
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
	:m_name(name),
	m_grade(150)
{
	Libft::print_colored_string_endl("Bureaucrat constructor called", green);
	verifyGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
{
	Libft::print_colored_string_endl("Bureaucrat copy constructor called", green);
	*this = other;
}

Bureaucrat::~Bureaucrat(void)
{
	Libft::print_colored_string_endl("Bureaucrat Destructor called", red);
}

void	Bureaucrat::signForm(Form& form)
{
	form.beSigned(*this);
}

void	Bureaucrat::setGrade(int grade)
{
	if (150 < grade)
		throw (GradeTooLowException(getName(), grade, getGrade()));
	else if (grade < 1)
		throw (GradeTooHighException(getName(), grade, getGrade()));
	else
		m_grade = grade;
}

void	Bureaucrat::verifyGrade(int grade)
{
	try
	{
		setGrade(grade);
		std::cout << getName() << ": " 
			<< Libft::get_colored_string("Success to be promoted!?", magenta) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	Libft::print_colored_string_endl("Bureaucrat Copy assignment operator called", blue);
	if (this != &rhs)
	{
		m_name = rhs.getName();
		verifyGrade(rhs.getGrade());
	}
	return (*this);
}

/*Class TooHigh*/
Bureaucrat::GradeTooHighException::GradeTooHighException(const std::string& name, int gradeToSet, int gradeCurrent)
	:m_message("TooHigh: " + name + ", try set grade to " + std::to_string(gradeToSet) + ". Current grade is " + std::to_string(gradeCurrent))
{
	Libft::print_colored_string_endl("Bureaucrat TooHigh constructor called", green);
}

Bureaucrat::GradeTooHighException::~GradeTooHighException(void) _NOEXCEPT
{
	Libft::print_colored_string_endl("Bureaucrat TooHigh destructor called", red);
}


/*Class TooLow*/
Bureaucrat::GradeTooLowException::GradeTooLowException(const std::string& name, int gradeToSet, int gradeCurrent)
	:m_message("(Bureaucrat)TooLow: " + name + " try set grade to " + std::to_string(gradeToSet) + ". Current grade is " + std::to_string(gradeCurrent))
{
	Libft::print_colored_string_endl("Bureaucrat TooLow constructor called", green);
}

Bureaucrat::GradeTooLowException::~GradeTooLowException(void) _NOEXCEPT
{
	Libft::print_colored_string_endl("Bureaucrat TooLow destructor called", red);
}


/* << operator */
std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (os);
}
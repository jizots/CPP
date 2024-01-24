#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <stdexcept>
# include <iostream>
# include "Form.hpp"
class Form;

class Bureaucrat
{
public:
	Bureaucrat(void);
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat(void);
	inline std::string	getName(void) const{return (m_name);};
	inline int			getGrade(void) const{return (m_grade);};
	inline void			incrementGrade(void){verifyGrade(getGrade() - 1);};
	inline void			decrementGrade(void){verifyGrade(getGrade() + 1);};
	void				signForm(Form& form);

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException(const std::string& name, int gradeToSet, int gradeCurrent);
		virtual ~GradeTooHighException(void) _NOEXCEPT;
		inline virtual const char*	what() const _NOEXCEPT{return (m_message.c_str());};

	private:
		std::string	m_message;
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException(const std::string& name, int gradeToSet, int gradeCurrent);
		virtual ~GradeTooLowException(void) _NOEXCEPT;
		inline virtual const char*	what() const _NOEXCEPT{return (m_message.c_str());};

	private:
		std::string	m_message;
	};

private:
	std::string	m_name;
	int			m_grade;

private:
	void	setGrade(int grade);
	void	verifyGrade(int grade);

public:
	Bureaucrat&	operator=(const Bureaucrat& rhs);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif
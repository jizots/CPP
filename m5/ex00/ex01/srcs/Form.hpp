#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Form
{
public:
	Form(void);
	Form(const std::string& name, int grade_req_sig, int grade_req_exec);
	Form(const Form& other);
	~Form(void);
	std::string&	getName(void) const;
	bool			getSigned(void);
	int				getGradeReqSig(void) const;
	int				getGradeReqExec(void) const;
	void			beSigned(const Bureaucrat& signer);

	class GradeTooHighException : public Bureaucrat::GradeTooHighException
	{
	public:
	private:
	};

	class GradeTooLowException : public Bureaucrat::GradeTooLowException
	{
	public:
	private:
	};

private:
	const std::string	m_name;
	bool				m_signed;
	const int			m_grade_req_sig;
	const int			m_grade_req_exec;

public:
	Form& 	operator=(const Form& rhs);
};

std::ostream&	operator<<(std::ostream& os, const Form& rhs);

#endif
#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
public:
	Form(void);
	Form(const std::string& name, int grade_req_sig, int grade_req_exec);
	Form(const Form& other);
	~Form(void);
	inline std::string&	getName(void) const{return (const_cast<std::string&>(m_name));};
	inline bool			getSigned(void){return (m_isSigned);};
	int					getGradeReqSig(void) const{return (m_grade_req_sig);};
	int					getGradeReqExec(void) const{return (m_grade_req_exec);};
	void				beSigned(const Bureaucrat& signer);

	class GradeTooHighException
	{
	public:
		GradeTooHighException();

	private:
		std::string	m_message;
	};

	class GradeTooLowException
	{
	public:
		GradeTooLowException(const std::string nameForm, const int grade);
		GradeTooLowException(const Bureaucrat& signer, const Form& form);
	private:
		std::string	m_message;
	};

private:
	const std::string	m_name;
	bool				m_isSigned;
	const int			m_grade_req_sig;
	const int			m_grade_req_exec;

private:
	void	setGrade(int grade);
	int		verifyGrade(int grade);
	void	verifySign(const Bureaucrat& signer);

public:
	Form& 	operator=(const Form& rhs);
};

std::ostream&	operator<<(std::ostream& os, const Form& rhs);

#endif
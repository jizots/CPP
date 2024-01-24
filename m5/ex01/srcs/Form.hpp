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
	inline const std::string&	getName(void) const{return (m_name);};
	inline const std::string& 	getSignerName(void) const {return (m_SignerName);};
	inline bool					getIsSigned(void) const {return (m_isSigned);};
	int							getGradeReqSig(void) const{return (m_gradeReqSig);};
	int							getGradeReqExec(void) const{return (m_gradeReqExe);};
	void						beSigned(const Bureaucrat& signer);

	class GradeTooHighException : public std::exception
	{
	public:
		GradeTooHighException(const std::string nameForm, const int grade);
		~GradeTooHighException(void) _NOEXCEPT;
		inline virtual const char*	what() const _NOEXCEPT{return (m_message.c_str());};
	private:
		std::string	m_message;
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException(const std::string nameForm, const int grade);
		GradeTooLowException(const Bureaucrat& signer, const Form& form);
		~GradeTooLowException(void) _NOEXCEPT;
		inline virtual const char*	what() const _NOEXCEPT{return (m_message.c_str());};
	private:
		std::string	m_message;
	};

private:
	const std::string	m_name;
	bool				m_isSigned;
	std::string			m_SignerName;
	const int			m_gradeReqSig;
	const int			m_gradeReqExe;

private:
	void	setGrade(int grade);
	int		verifyGrade(int grade);
	void	verifySign(const Bureaucrat& signer);

public:
	Form& 	operator=(const Form& rhs);
};

std::ostream&	operator<<(std::ostream& os, const Form& rhs);

#endif
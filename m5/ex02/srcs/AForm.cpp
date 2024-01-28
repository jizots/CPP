#include "AForm.hpp"
#include "Libft.hpp"

AForm::AForm(void)
	:m_name("Nameless"),
	m_isSigned(false),
	m_SignerName(""),
	m_gradeReqSig(verifyGrade(1)),
	m_gradeReqExe(verifyGrade(1))
{
	Libft::print_colored_string_endl("Form Default constructor called", green);
};

AForm::AForm(const std::string& name, int grade_req_sig, int grade_req_exec)
	:m_name(name),
	m_isSigned(false),
	m_SignerName(""),
	m_gradeReqSig(verifyGrade(grade_req_sig)),
	m_gradeReqExe(verifyGrade(grade_req_exec))
{
	Libft::print_colored_string_endl("Form Constructor called", green);
};

AForm::AForm(const AForm& other)
	:m_name(other.m_name),
	m_isSigned(other.m_isSigned),
	m_SignerName(other.m_SignerName),
	m_gradeReqSig(other.m_gradeReqSig),
	m_gradeReqExe(other.m_gradeReqExe)
{
	Libft::print_colored_string_endl("Form Copy constructor called", green);
};

void	AForm::setGrade(int grade)
{
	if (150 < grade)
		throw (GradeTooLowException(getName(), grade));
	else if (grade < 1)
		throw (GradeTooHighException(getName(), grade));
};

int	AForm::verifyGrade(int grade)
{
	try
	{
		setGrade(grade);
		std::cout << getName() << ": " 
			<< Libft::get_colored_string("Success to be set", magenta) << std::endl;
		return (grade);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
};

void	AForm::verifySign(const Bureaucrat& signer)
{
	if (signer.getGrade() > this->getGradeReqSig() || this->getIsSigned())
		throw (GradeTooLowException(signer, *this));
	else
	{
		m_isSigned = true;
		m_SignerName = signer.getName();
		std::cout << signer.getName() << " signed " << getName() << std::endl; 
	}
};

void	AForm::verifyExe(const Bureaucrat& executor) const
{
	if (executor.getGrade() > this->getGradeReqExec() || this->getIsSigned() == false)
		throw (GradeTooLowException(executor, *this, getGradeReqExec()));
	else
		std::cout << executor.getName() << " executed " << getName() << std::endl; 
};


AForm::~AForm(void)
{
	Libft::print_colored_string_endl("Form destructor called", red);
};

void	AForm::beSigned(const Bureaucrat& signer)
{
	try
	{
		verifySign(signer);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
};

AForm& 	AForm::operator=(const AForm& rhs)
{
	(void)rhs;
	Libft::print_colored_string_endl("Form Copy assignment operator called", blue);
	Libft::print_colored_string_endl("But copy assignment can't allow.", yellow);
	return (const_cast<AForm&>(rhs));
};

/*GradeTooHigh class*/
AForm::GradeTooHighException::GradeTooHighException(const std::string nameAForm, const int grade)
	:m_message("(Form)TooHigh: " + nameAForm + " try set Requirement grade to " + std::to_string(grade))
{
	Libft::print_colored_string_endl("Form TooHigh constructor called", green);
};

AForm::GradeTooHighException::~GradeTooHighException(void) _NOEXCEPT
{
	Libft::print_colored_string_endl("Form TooHigh destructor called", red);
};

/*GradeTooLow class*/
AForm::GradeTooLowException::GradeTooLowException(const std::string nameAForm, const int grade)
	:m_message("(Form)TooLow: " + nameAForm + " try set Requirement grade to " + std::to_string(grade))
{
	Libft::print_colored_string_endl("Form TooLow constructor called", green);
};

AForm::GradeTooLowException::GradeTooLowException(const Bureaucrat& signer, const AForm& form)
{
	Libft::print_colored_string_endl("Form TooLow(sign) constructor called", green);
	if (form.m_isSigned)
		m_message = signer.getName() + " couldn't sign " + form.getName() + " because "
			+ "already signed...";
	else
		m_message = signer.getName() + " couldn't sign " + form.getName() + " because "
			+ "your Grade Too Low. Required Grade is " + std::to_string(form.getGradeReqSig());
};

AForm::GradeTooLowException::GradeTooLowException(const Bureaucrat& signer, const AForm& form, const int grade)
{
	Libft::print_colored_string_endl("Form TooLow(sign) constructor called", green);
	if (form.m_isSigned == false)
		m_message = signer.getName() + " couldn't execute " + form.getName() + " because "
			+ "not signed...";
	else
		m_message = signer.getName() + " couldn't execute " + form.getName() + " because "
			+ "your Grade Too Low. Required Grade is " + std::to_string(grade);
};

AForm::GradeTooLowException::~GradeTooLowException(void) _NOEXCEPT
{
	Libft::print_colored_string_endl("Form TooLow destructor called", red);
};

/* << operator */
std::ostream& operator<<(std::ostream& os, const AForm& rhs)
{
	os << rhs.getName() << ": Signer(" << rhs.getSignerName() << "), "
		<< "isSigned(" << rhs.getIsSigned() << "), "
		<< "gradeReqSig(" << rhs.getGradeReqSig() << "), "
		<< "gradeReqExe(" << rhs.getGradeReqExec() << ").";
	return (os);
}

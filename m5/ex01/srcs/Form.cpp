#include "Form.hpp"
#include "Libft.hpp"

Form::Form(void)
	:m_name("Nameless"),
	m_isSigned(false),
	m_SignerName(""),
	m_gradeReqSig(verifyGrade(1)),
	m_gradeReqExe(verifyGrade(1))
{
	Libft::print_colored_string_endl("Form Default constructor called", green);
};

Form::Form(const std::string& name, int grade_req_sig, int grade_req_exec)
	:m_name(name),
	m_isSigned(false),
	m_SignerName(""),
	m_gradeReqSig(verifyGrade(grade_req_sig)),
	m_gradeReqExe(verifyGrade(grade_req_exec))
{
	Libft::print_colored_string_endl("Form Constructor called", green);
};

Form::Form(const Form& other)
	:m_name(other.m_name),
	m_isSigned(other.m_isSigned),
	m_SignerName(other.m_SignerName),
	m_gradeReqSig(other.m_gradeReqSig),
	m_gradeReqExe(other.m_gradeReqExe)
{
	Libft::print_colored_string_endl("Form Copy constructor called", green);
};

void	Form::setGrade(int grade)
{
	if (150 < grade)
		throw (GradeTooLowException(getName(), grade));
	else if (grade < 1)
		throw (GradeTooHighException(getName(), grade));
};

int	Form::verifyGrade(int grade)
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

void	Form::verifySign(const Bureaucrat& signer)
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

Form::~Form(void)
{
	Libft::print_colored_string_endl("Form destructor called", red);
};

void	Form::beSigned(const Bureaucrat& signer)
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

Form& 	Form::operator=(const Form& rhs)
{
	(void)rhs;
	Libft::print_colored_string_endl("Form Copy assignment operator called", blue);
	Libft::print_colored_string_endl("But copy assignment can't allow.", yellow);
	return (const_cast<Form&>(rhs));
};

/*GradeTooHigh class*/
Form::GradeTooHighException::GradeTooHighException(const std::string nameForm, const int grade)
	:m_message("(Form)TooHigh: " + nameForm + " try set Requirement grade to " + std::to_string(grade))
{
	Libft::print_colored_string_endl("Form TooHigh constructor called", green);
};

Form::GradeTooHighException::~GradeTooHighException(void) _NOEXCEPT
{
	Libft::print_colored_string_endl("Form TooHigh destructor called", red);
};

/*GradeTooLow class*/
Form::GradeTooLowException::GradeTooLowException(const std::string nameForm, const int grade)
	:m_message("(Form)TooLow: " + nameForm + " try set Requirement grade to " + std::to_string(grade))
{
	Libft::print_colored_string_endl("Form TooLow constructor called", green);
};

Form::GradeTooLowException::GradeTooLowException(const Bureaucrat& signer, const Form& form)
{
	Libft::print_colored_string_endl("Form TooLow(sign) constructor called", green);
	if (form.m_isSigned)
		m_message = signer.getName() + " couldn't sign " + form.getName() + " because "
			+ "already signed...";
	else
		m_message = signer.getName() + " couldn't sign " + form.getName() + " because "
			+ "your Grade Too Low. Required Grade is " + std::to_string(form.getGradeReqSig());
};

Form::GradeTooLowException::~GradeTooLowException(void) _NOEXCEPT
{
	Libft::print_colored_string_endl("Form TooLow destructor called", red);
};

/* << operator */
std::ostream& operator<<(std::ostream& os, const Form& rhs)
{
	os << rhs.getName() << ": Signer(" << rhs.getSignerName() << "), "
		<< "isSigned(" << rhs.getIsSigned() << "), "
		<< "gradeReqSig(" << rhs.getGradeReqSig() << "), "
		<< "gradeReqExe(" << rhs.getGradeReqExec() << ").";
	return (os);
}
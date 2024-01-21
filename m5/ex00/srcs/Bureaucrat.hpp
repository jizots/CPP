#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat
{
private:
	void	setGrade(int grade);
	void	verifyGrade(int grade);

public:
	Bureaucrat(void);
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& other);
	~Bureaucrat(void);
	inline std::string	getName(void) const{return (m_name);};
	inline int			getGrade(void) const{return (m_grade);};
	inline void			incrementGrade(void){verifyGrade(getGrade() - 1);};
	inline void			decrementGrade(void){verifyGrade(getGrade() + 1);};
	class GradeTooHighException : std::exception
	{
	public:
		GradeTooHighException(const std::string& name, int grade)
			:m_ename(name), m_egrade(grade){};
		inline virtual const char*	what() const _NOEXCEPT
		{
			(void)m_egrade; (void)m_ename;
			return ("TooHigh");
		};

	private:
		const std::string&	m_ename;
		int					m_egrade;
	};

	class GradeTooLowException : std::exception
	{
	public:
		GradeTooLowException(const std::string& name, int grade)
			:m_ename(name), m_egrade(grade){};
		inline virtual const char*	what() const _NOEXCEPT
		{
			(void)m_egrade; (void)m_ename;
			return ("TooLow");
		};
	private:
		const std::string&	m_ename;
		int					m_egrade;
	};

private:
	std::string	m_name;
	int			m_grade;

public:
	void	operator=(const Bureaucrat& rhs);
};

#endif
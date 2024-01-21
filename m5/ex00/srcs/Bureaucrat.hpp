#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <stdexcept>
# include <iostream>

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
	class GradeTooHighException : public std::exception
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
		const std::string	m_ename;
		int					m_egrade;
	};

	class GradeTooLowException : public std::exception
	{
	public:
		GradeTooLowException(const std::string& name, int grade)
			:m_ename(name), m_egrade(grade){};
		inline virtual const char*	what() const _NOEXCEPT
		{
			std::string	ret(m_ename + ", " + std::to_string(m_egrade));
			std::cout << m_ename << std::endl;
			std::cout << m_egrade << std::endl;
			return (ret.c_str());
		};
	private:
		const std::string	m_ename;
		int					m_egrade;
	};

private:
	std::string	m_name;
	int			m_grade;

public:
	Bureaucrat&	operator=(const Bureaucrat& rhs);
};

#endif
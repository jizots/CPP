#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Bureaucrat
{
public:
	Bureaucrat(void);
	Bureaucrat(const std::string name, int grade);
	~Bureaucrat(void);
	std::string	getName(void);
	int			getGrade(void);
	void		incrementGrade(void);
	void		decrementGrade(void);

private:
	const std::string	m_name;
	int					m_grade;
};

#endif
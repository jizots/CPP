#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
class Bureaucrat;

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string& name);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	virtual ~RobotomyRequestForm(void);
	virtual void	execute(Bureaucrat const & executor) const;

private:
	void	robotomize(const std::string& target) const;

};

#endif

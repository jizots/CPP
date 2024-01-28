#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
class Bureaucrat;

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string& name);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	~PresidentialPardonForm(void);
	virtual void	execute(Bureaucrat const & executor) const;

private:
	void	pardon(const std::string& target) const;

};

#endif

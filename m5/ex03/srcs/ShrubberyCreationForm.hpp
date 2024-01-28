#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <string>
# include "AForm.hpp"
# include "Bureaucrat.hpp"
class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string& name);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm(void);
	virtual void	execute(Bureaucrat const & executor) const;

private:
	void	createFileManAscii(const std::string& target) const;

};

#endif

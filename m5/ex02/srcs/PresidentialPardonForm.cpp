#include <random>
#include "PresidentialPardonForm.hpp"
#include "Libft.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
	:AForm("NamelessPres", 25, 5)
{
	Libft::print_colored_string_endl("PresidentialPardonForm default constructor called", green);
};

PresidentialPardonForm::PresidentialPardonForm(const std::string& name)
	:AForm(name, 25, 5)
{
	Libft::print_colored_string_endl("PresidentialPardonForm constructor called", green);
};

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	:AForm(other)
{
	Libft::print_colored_string_endl("PresidentialPardonForm Copy constructor called", green);
};

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	Libft::print_colored_string_endl("PresidentialPardonForm destructor called", red);
};

void	PresidentialPardonForm::pardon(const std::string& target) const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
};

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	try
	{
		verifyExe(executor);
		pardon(getName());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}	
};

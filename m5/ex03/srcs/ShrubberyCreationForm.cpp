# include "ShrubberyCreationForm.hpp"
# include "Libft.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
	:AForm("NamelessSh", 145, 137)
{
	Libft::print_colored_string_endl("ShrubberyCreationForm default constructor called", green);
};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name)
	:AForm(name, 145, 137)
{
	Libft::print_colored_string_endl("ShrubberyCreationForm constructor called", green);
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	:AForm(other)
{
	Libft::print_colored_string_endl("ShrubberyCreationForm Copy constructor called", green);
};

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	Libft::print_colored_string_endl("ShrubberyCreationForm destructor called", red);
};

void	ShrubberyCreationForm::createFileManAscii(const std::string& target) const
{
	std::string	cmdString = "cat /usr/share/misc/ascii > " + target + "_shrubbery";
	system(cmdString.c_str());
};

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	try
	{
		verifyExe(executor);
		createFileManAscii(getName());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}	
};

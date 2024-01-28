#include <random>
#include "RobotomyRequestForm.hpp"
#include "Libft.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
	:AForm("NamelessRo", 72, 45)
{
	Libft::print_colored_string_endl("RobotomyRequestForm default constructor called", green);
};

RobotomyRequestForm::RobotomyRequestForm(const std::string& name)
	:AForm(name, 72, 45)
{
	Libft::print_colored_string_endl("RobotomyRequestForm constructor called", green);
};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	:AForm(other)
{
	Libft::print_colored_string_endl("RobotomyRequestForm Copy constructor called", green);
};

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	Libft::print_colored_string_endl("RobotomyRequestForm destructor called", red);
};

void	RobotomyRequestForm::robotomize(const std::string& target) const
{
	std::random_device	rnd;

	if ((rnd() % 2))
	{
		std::cout << target << " robotomized!: "
			<< "gagagagagagaga..." << std::endl;
	}
	else
		std::cout << target << Libft::get_colored_string(" failed robotomize.", yellow) << std::endl;
};

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	try
	{
		verifyExe(executor);
		robotomize(getName());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}	
};

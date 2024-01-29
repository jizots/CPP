#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "Libft.hpp"

int	main()
{
	std::cout << "----construct----" << std::endl;
	Bureaucrat b1("shachooo", 1);
	Bureaucrat b2("hira", 150);
	Intern someone;
	AForm *robo;
	AForm *shru;
	AForm *pres;
	try
	{
		robo = someone.makeForm("RobotomyRequest", "R2D2");	
		b1.signForm(*robo);
		b1.executeForm(*robo);
		robo->execute(b2);
		delete robo;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		shru = someone.makeForm("shrubbery  creation", "Shru");
		b1.signForm(*shru);
		b1.executeForm(*shru);
		delete shru;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		pres = someone.makeForm("Presidential onsha", "Shru");
		b1.signForm(*pres);
		b1.executeForm(*pres);
		delete pres;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q cpp05ex03");
}
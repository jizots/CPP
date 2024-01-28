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
	Intern someone;
	AForm *robo;
	AForm *shru;
	robo = someone.makeForm("RobotomyRequest", "R2D2");
	shru = someone.makeForm("shrubbery  creation", "Shru");

	std::cout << "----try sign, execute from Form----" << std::endl;
	b1.signForm(*robo);
	b1.executeForm(*robo);
	b1.signForm(*shru);
	b1.executeForm(*shru);

	std::cout << "----try sign, from Bureaucrat----" << std::endl;

	std::cout << "---- '<<' ----" << std::endl;

	std::cout << "---- '==' ----" << std::endl;

	delete robo;
	delete shru;
	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q cpp05ex03");
}
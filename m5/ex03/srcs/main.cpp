#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Libft.hpp"

int	main()
{
	std::cout << "----construct----" << std::endl;
	// AForm f1("f1", 1, 1);//error. Abstruct class can't make instance.
	ShrubberyCreationForm f1("ShrubForm");
	RobotomyRequestForm f2("R2D2");
	PresidentialPardonForm f4("horikeK");

	Bureaucrat b1("sataharu", 1);
	Bureaucrat b2("pisciner", 150);


	std::cout << "----try sign, execute from Form----" << std::endl;
	f1.execute(b1);
	f1.beSigned(b1);
	f2.beSigned(b1);
	f4.beSigned(b1);

	std::cout << "----try sign, from Bureaucrat----" << std::endl;
	b1.executeForm(f1);
	b1.executeForm(f2);
	b2.executeForm(f2);
	b1.executeForm(f4);

	std::cout << "---- '<<' ----" << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << f4 << std::endl;

	std::cout << "---- '==' ----" << std::endl;
	ShrubberyCreationForm f3("f3");
	f3 = f1;
	std::cout << f3 << std::endl;

	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q cpp05ex02");
}
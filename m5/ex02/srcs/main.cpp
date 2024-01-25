#include "Bureaucrat.hpp"
#include "Libft.hpp"

int	main()
{
	std::cout << "----construct----" << std::endl;
	Bureaucrat b1("b1", 1);
	Bureaucrat b2("b2", 150);
	Form f1("f1", 1, 1);
	Form f2("f2", 150, 150);
	Form f3("f3", 151, 151);//error TooLow form
	Form f4("f4", -1, 1);//error TooHigh form

	std::cout << f1 << std::endl;
	std::cout << f3 << std::endl;

	std::cout << "----try sign, from Form----" << std::endl;
	f1.beSigned(b2);//error TooLow grade
	f1.beSigned(b1);
	f1.beSigned(b1);//error already signed
	std::cout << f1 << std::endl;

	std::cout << "----try sign, from Bureaucrat----" << std::endl;
	b1.signForm(f1);//error already signed
	b2.signForm(f2);
	std::cout << f2 << std::endl;

	std::cout << "---- '<<' ----" << std::endl;
	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q cpp05ex01");
}
#include "Bureaucrat.hpp"

int	main()
{
	std::cout << "----construct----" << std::endl;
	Bureaucrat b1;
	Bureaucrat b2("b2", 1);
	Bureaucrat b3("b3", 151);
	Bureaucrat b4("b4", 0);
	Bureaucrat b6(b2);//copy
	// Bureaucrat b5("b5", 2147483648);//compile error

	std::cout << "----increment or decrement----" << std::endl;
	b1.decrementGrade();//error
	b1.incrementGrade();
	b2.decrementGrade();
	b2.incrementGrade();
	b2.incrementGrade();//error
	b6.decrementGrade();

	std::cout << "---- '<<' ----" << std::endl;
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << b3 << std::endl;
	std::cout << b4 << std::endl;
	std::cout << b6 << std::endl;
	return (0);
}
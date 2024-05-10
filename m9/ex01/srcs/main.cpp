#include "RPN.hpp"

#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error. Invalid number of arguments" << std::endl;
		return (1);
	}
	try
	{
		std::cout << "--- Basic test ---" << std::endl;
		RPN culculator(av[1]);
		std::cout << "--- Copy constructor ---" << std::endl;
		RPN c2(culculator);
		std::cout << "--- Assignation operator ---" << std::endl;
		RPN c3 = culculator;
		std::cout << "--- Const Class ---" << std::endl;
		const RPN c4(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return (1);
	}
	catch(const std::string& e)
	{
		std::cout << e << '\n';
		return (1);
	}
	catch(const char* e)
	{
		std::cout << e << '\n';
		return (1);
	}
	
}
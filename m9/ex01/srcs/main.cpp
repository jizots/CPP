#include "RPN.hpp"

#include <iostream>

//https://spica-git.github.io/gh-projects/demo/rpn.html - RPN calculator

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
		RPN culculator;
		std::cout << culculator.Calculation(std::string(av[1])) << std::endl;
		std::cout << "--- Copy constructor ---" << std::endl;
		RPN c2(culculator);
		std::cout << "--- Assignation operator ---" << std::endl;
		RPN c3 = culculator;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
		return (1);
	}
	return (0);
}
#include "Libft.hpp"
#include "ScalarConverter.hpp"
#include <cmath>

/*
 C++ has four cast.
 static_cast: ex.float to int, int to float. Must verify overflow from big type to little type.
 const_cast: Add or Remove const attribute. Will not use in this exercise.
 dynamic_cast: 
 reinterpret_cast:
*/


int main(int ac, char **av)
{
	// ScalarConverter a; //compile error. cause Default constructor declaration at privete attribute.
	std::string	literal;

	if (ac != 2)
	{
		Libft::print_colored_string_endl("Error. Only one args accept.", red, std::cerr);
		return (1);
	}
	literal = av[1];
	if (literal.empty())
	{
		Libft::print_colored_string_endl("Error. Argument is invalid literal.", red, std::cerr);
		return (1);
	}
	ScalarConverter::convert(literal);
	std::cout << std::endl;
	std::cout << "------------- my test -------------" << std::endl;
	std::istringstream iss(".5");
	char c = 'a';
	int i = 'a';
	float f = 'a';
	double d = 'a';
	std::cout << "char: " << c << ", int: " << i <<", float: " << f << ", double: " << d << std::endl;
	iss >> f;
	std::cout << f <<std::endl;
	return (0);
}

/*
./convert 0
char: Non displayable
int: 0
float: 0.0f
double: 0.0
./convert nan
char: impossible
int: impossible
float: nanf
double: nan
./convert 42.0f
char: '*'
int: 42
float: 42.0f
double: 42.0

-inf
inf
nan

*/
#include "Libft.hpp"
#include "ScalarConverter.hpp"
#include <cmath>

/*
 C++ has four cast.
 static_cast: ex.float to int, int to float. Must verify overflow from big type to little type.
 const_cast: Add or Remove const attribute.
 dynamic_cast: Use for polymorphism(;cast to correct class(type)). If it is not polymorphism, return null.
 reinterpret_cast: Convert any type to any type. It is not safe. Only use when recast to same type.
 https://learn.microsoft.com/ja-jp/cpp/cpp/casting-operators?view=msvc-170
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
	std::cout << "-----> a <-----" << std::endl;
	ScalarConverter::convert("a");
	std::cout << "-----> 31 <-----" << std::endl;
	ScalarConverter::convert("31"); //ascii but unprintable
	std::cout << "-----> 126 <-----" << std::endl;
	ScalarConverter::convert("126"); //ascii printable limit
	std::cout << "-----> 2147483647 <-----" << std::endl;
	ScalarConverter::convert("2147483647"); // int max
	std::cout << "-----> 2147483648 <-----" << std::endl;
	ScalarConverter::convert("2147483648"); // int overflow
	std::cout << "-----> -2147483648 <-----" << std::endl;
	ScalarConverter::convert("-2147483648"); // int min
	std::cout << "-----> -2147483649 <-----" << std::endl;
	ScalarConverter::convert("-2147483649"); // int overflow

	std::cout << std::numeric_limits<float>::min() << std::endl;
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
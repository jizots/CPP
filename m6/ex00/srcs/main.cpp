#include "Libft.hpp"
#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	std::string	literal;
	if (ac != 2)
	{
		Libft::print_colored_string_endl("Error. Only one args accept.", red, std::cerr);
		return (1);
	}
	literal = av[1];
	if (literal.empty() || Libft::is_string_composed_with_func(literal, std::isspace) == true)
	{
		Libft::print_colored_string_endl("Error. Argument is invalid literal.", red, std::cerr);
		return (1);
	}
	ScalarConverter::convert(literal);
	// ScalarConverter a; //compile error. cause Default constructor declaration at privete attribute.
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
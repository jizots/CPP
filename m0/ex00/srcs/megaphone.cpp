#include <iostream>
#include <ctype.h>

std::string	str_toupper(const std::string& str)
{
	std::string	ret_string = str;

	if (str.empty())
		return ("");
	for (size_t i = 0; i < str.length(); ++i)
		ret_string[i] = std::toupper(static_cast<unsigned char>(ret_string[i]));
	return (ret_string);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	else
	{
		for (int i = 1; av[i]; i++)
			std::cout << str_toupper(av[i]);
	}
	std::cout << std::endl;
	return (0);
}
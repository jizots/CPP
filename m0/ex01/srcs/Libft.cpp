#include "Libft.hpp"

std::string Libft::get_colored_string(const std::string& msg, Font_Color font_color)
{
	const std::string color_codes[] = {
		"\033[30m", "\033[31m", "\033[32m", "\033[33m",
		"\033[34m", "\033[35m", "\033[36m", "\033[37m"
    };
	const std::string	reset_color = "\033[0m";
	return color_codes[font_color] + msg + reset_color;
}

void	Libft::print_colored_string_endl(const std::string& msg, Font_Color font_color)
{
	std::cout << Libft::get_colored_string(msg, font_color) << std::endl;
}

bool	Libft::is_string_composed_with_chars(const std::string& str, const std::string& expected_set)
{
	if (str.empty() || expected_set.empty())
		return (false);
	for (std::string::size_type i = 0; i < str.length(); ++i)
	{
		if (std::strchr(expected_set.c_str(), str[i]) == NULL)
			return (false);
	}
	return (true);
}

bool	Libft::is_string_composed_with_func(const std::string& str, int (*f)(int))
{
	if (str.empty())
		return (false);
	for (std::string::size_type i = 0; i < str.length(); ++i)
	{
		if (!f(str[i]))
			return (false);
	}
	return (true);
}

std::string	Libft::get_first_n_charactors(const std::string& str,const size_t n)
{
	return (str.substr(0, n));
}

std::string	Libft::end_with_c_over_n(const std::string& str, const char c, const size_t n)
{
	if (str.length() > n)
		return (str.substr(0, n - 1) + c);
	else
		return (str);
}

int	Libft::ft_atoi(std::string& str)
{
	std::stringstream	ss;
	int					num;

	ss << str;
	ss >> num;
	return (num);
}

int	Libft::getline_wrap(std::string& str)
{
	if (!std::getline(std::cin, str))
	{
		if (std::cin.eof())
			return (1);
		else if (std::cin.fail())
			return (-1);
	}
	return (0);
}
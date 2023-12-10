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

bool	Libft::is_string_composedof(const std::string& str, const std::string& expected_set)
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

bool	Libft::is_string_composed_f(const std::string& str, int (*f)(int))
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

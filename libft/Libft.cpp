#include "Libft.hpp"

std::string Libft::get_colored_string(const std::string& msg, Font_Color font_color)
{
	const std::string color_codes[] = {
		"\033[30m", "\033[31m", "\033[32m", "\033[33m",
		"\033[34m", "\033[35m", "\033[36m", "\033[37m",
		"\033[38;5;94m"
    };
	const std::string	reset_color = "\033[0m";
	return color_codes[font_color] + msg + reset_color;
}

void	Libft::print_colored_string_endl(const std::string& msg, Font_Color font_color, std::ostream& stream)
{
	stream << Libft::get_colored_string(msg, font_color) << std::endl;
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

int	Libft::ft_isascii(int c)
{
	return (0 <= c && c <= 127);
}

int	Libft::ft_atoi(std::string& str)
{
	std::stringstream	ss;
	int					num;

	ss << str;
	ss >> num;
	return (num);
}

int	Libft::getline_wrap(std::istream& is, std::string& str)
{
	if (!std::getline(is, str))
	{
		if (std::cin.eof())
		{
			std::cerr << "End Of File detected." << std::endl;
			return (1);
		}
		else if (std::cin.fail())
		{
			std::cerr << strerror(errno) << std::endl;
			return (-1);
		}
	}
	return (0);
}

std::vector<std::string> Libft::splitByChars(const std::string& src, const std::string& chars)
{
	std::vector<std::string> splitedStr;
	size_t i = 0;
	size_t wc = 0;
	bool hasDelimiter = false;

	for (; i < src.size(); ++i)
	{
		if (std::strchr(chars.c_str(), static_cast<int>(src[i])))
		{
			if (wc)
				hasDelimiter = true;
		}
		else
			++wc;
		if (hasDelimiter && wc)
		{
			splitedStr.push_back(std::string(src, i - wc, wc));
			wc = 0;
			hasDelimiter = false;
		}
	}
	if (wc)
		splitedStr.push_back(std::string(src, i - wc, wc));
	return (splitedStr);
};

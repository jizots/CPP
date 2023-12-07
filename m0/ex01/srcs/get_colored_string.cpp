#include "libft.hpp"

std::string get_colored_string(const std::string& msg, Font_Color font_color)
{
	const std::string color_codes[] = {
		"\033[30m", "\033[31m", "\033[32m", "\033[33m",
		"\033[34m", "\033[35m", "\033[36m", "\033[37m"
    };
	const std::string	reset_color = "\033[0m";

	return color_codes[font_color] + msg + reset_color;
}
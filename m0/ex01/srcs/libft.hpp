#ifndef LIBFT_HPP
# define LIBFT_HPP

/*----include----*/
# include <string>

/*----define----*/
enum Font_Color
{
	black,
	red,
	green,
	yellow,
	blue,
	magenta,
	cyan,
	white
};

enum Contact_Item
{
	first_name, last_name, nickname, phone_number, darkest_secret
};

/*----Prototype----*/
/***
 * Stream
 ***/
std::string get_colored_string(const std::string& msg, Font_Color font_color);

#endif
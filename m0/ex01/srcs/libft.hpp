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

class Libft
{
public:
    /**
     * Return Colored message.
     * @param msg Message what want to colored.
     * @param font_color Font color
     * @return Colored message
     */
	static std::string get_colored_string(const std::string& msg, Font_Color font_color);

    /**
     * Verify string is composed with expected string charactors.
     * @param str String to be checked.
     * @param expected_set Charactors to be expected component.
     * @return Return True if the string consists only of expected characters.
     */
	static bool	is_string_composedof(const std::string& str, const std::string& expected_set);

    /**
     * Checks if a string is constructed based on a given function
     * @param str String to be checked.
     * @param f Function that check string. (ex. isalpha, isprint)
     * @return Return True if the string comply with (f)unction.
     */
	static bool	is_string_composed_f(const std::string& str, int (*f)(int));
private:
};

#endif
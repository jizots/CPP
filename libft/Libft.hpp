#ifndef LIBFT_HPP
# define LIBFT_HPP

/*----include----*/
# include <iostream>
# include <string>
# include <sstream>
# include <cerrno>
# include <vector>

/*----enum----*/
enum Font_Color
{
	black,
	red,
	green,
	yellow,
	blue,
	magenta,
	cyan,
	white,
	brown
};

/*----define----*/

class Libft
{
public:
	/**
	 * Get colored string.
	 * @param msg Message what want to colored.
	 * @param font_color Font color
	 * @return Colored string
	 */
	static std::string	get_colored_string(const std::string& msg, Font_Color font_color);

	/**
	 * Print colored string to std::cout with endline.
	 * @param msg Message what want to colored.
	 * @param font_color Font color
	 * @param stream Output steam. std::cout or std::cerr
	 */
	static void			print_colored_string_endl(const std::string& msg, Font_Color font_color, std::ostream& stream);

	/**
	 * Verify string is composed with expected string charactors.
	 * @param str String to be checked.
	 * @param expected_set Charactors to be expected component.
	 * @return Return True if the string consists only of expected characters.
	 */
	static bool	is_string_composed_with_chars(const std::string& str, const std::string& expected_set);

	/**
	 * Checks if a string is constructed based on a given function
	 * @param str String to be checked.
	 * @param f Function that check string. (ex. isalpha, isprint)
	 * @return Return True if the string comply with (f)unction.
	 */
	static bool	is_string_composed_with_func(const std::string& str, int (*f)(int));

	/**
	 * Get first n charactors from string.
	 * @param str String to be checked.
	 * @param n Number of charactors to get.
	 * @return Return first n charactors from string.
	 */
	static std::string	get_first_n_charactors(const std::string& str, const size_t n);
	static std::string	end_with_c_over_n(const std::string& str, const char c, const size_t n);

	/**
	 * Check if the character is in the ASCII code.
	 * @param c Character to be checked.
	 * @return Return True if the character is in the ASCII code.
	 */
	static int	ft_isascii(int c);
	static int	ft_atoi(std::string& str);

	/**
	 * Get line from std::cin.
	 * @param is std::cin
	 * @param str String to be stored.
	 * @return Return 1 if success, 0 if EOF, -1 if error.
	 */
	static int	getline_wrap(std::istream& is, std::string& str);

	static std::vector<std::string> splitByChars(const std::string& src, const std::string& chars);

	template<typename RangeType, typename ValueType>
	static bool isWithinRange(ValueType value){
		return (std::numeric_limits<RangeType>::lowest() <= value
				&& value <= std::numeric_limits<RangeType>::max());};

	template <typename T>
	static bool isUnsigned(){ return (true); };

	template <>
	bool isUnsigned<uint8_t>(){ return (true); };

	template <>
	bool isUnsigned<uint16_t>(){ return (true); };

	template <>
	bool isUnsigned<uint32_t>(){ return (true); };

	template <>
	bool isUnsigned<uint64_t>(){ return (true); };

	template <typename T>
	static bool isNumericType(const std::string& literal)
	{
		if (isUnsigned<T>() && literal.find('-') != std::string::npos)
			return (false);
		std::istringstream iss(literal);
		T t;

		iss >> t;
		if (iss.fail() || !iss.eof())
			return (false);
		return (true);
	};

	template <typename T>
	static T toNumericType(const std::string& literal)
	{
		std::istringstream iss(literal);
		T t;

		iss >> t;
		if (iss.fail() || !iss.eof())
			throw ("Error: Argument is invalid literal => " + literal);
		return (t);
	};

private:
	Libft(void);
	Libft(const Libft& other);
};

#endif
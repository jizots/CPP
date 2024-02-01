#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <sstream>
# include <stdexcept>
# define type_char		0
# define type_int		1
# define type_float		2
# define type_double	3


class ScalarConverter
{
public:
	static void	convert(const std::string& literal);

	class ConvertImpossibleException : public std::exception
	{
	public:
		inline ConvertImpossibleException(const std::string& msg):m_msg(msg){};
		inline virtual ~ConvertImpossibleException(void) _NOEXCEPT{};
		inline virtual const char* what() const _NOEXCEPT{return (m_msg.c_str());};
	private:
		std::string	m_msg;
	};

private:
	ScalarConverter(void);
	~ScalarConverter(void);
	static void	analyzeLiteralType(const std::string& literal);
	static bool	isChar(const std::string& literal);
	static bool	isInt(const std::string& literal);
	static bool	isFloat(const std::string& literal);
	static bool	isDouble(const std::string& literal);
	static bool	isNum(const std::string& str);
	static bool	isFloatingPointNum(const std::string& str);
	static void	printAsChar(void);
	static void	printAsInt(void);
	static void	printAsFloat(void);
	static void	printAsDouble(void);

	static char		m_val_char;
	static int		m_val_int;
	static float	m_val_float;
	static double	m_val_double;
	static unsigned char	m_type;
};

/*
　The ScalarConverter class is designed to be non-instantiable, as its constructor is private. 
　This design implies that there are no opportunities to copy instances of this class, 
　thus making the definition of a copy constructor and copy assignment operator unnecessary.
 */

#endif
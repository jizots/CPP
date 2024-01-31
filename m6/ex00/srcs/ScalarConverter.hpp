#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <sstream>
# include <stdexcept>

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
	static void	toChar(const std::string& literal);
	static void	toInt(const std::string& literal);
	static void	toFloat(const std::string& literal);
	static void	toDouble(const std::string& literal);

	static char		m_val_char;
	static int		m_val_int;
	static float	m_val_float;
	static double	m_val_double;
};

/*
　The ScalarConverter class is designed to be non-instantiable, as its constructor is private. 
　This design implies that there are no opportunities to copy instances of this class, 
　thus making the definition of a copy constructor and copy assignment operator unnecessary.
 */

#endif
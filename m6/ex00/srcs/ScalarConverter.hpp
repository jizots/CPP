#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
public:
	static void	convert(const std::string& literal);

private:
	ScalarConverter(void);
	~ScalarConverter(void);
	static void	toChar();
	static void	toInt();
	static void	toFloat();
	static void	toDouble();
};

/*
　The ScalarConverter class is designed to be non-instantiable, as its constructor is private. 
　This design implies that there are no opportunities to copy instances of this class, 
　thus making the definition of a copy constructor and copy assignment operator unnecessary.
 */

#endif
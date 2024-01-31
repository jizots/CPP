#include "ScalarConverter.hpp"
#include <cmath>
#include "Libft.hpp"

char	ScalarConverter::m_val_char = 0;
int		ScalarConverter::m_val_int = 0;
float	ScalarConverter::m_val_float = 0;
double	ScalarConverter::m_val_double = 0;

void	ScalarConverter::toChar(const std::string& literal)
{
	std::istringstream	iss(literal);

	std::cout << "char: ";
	iss >> ScalarConverter::m_val_char;
	if (iss)
	{
		return ;
	}
	else
	{
		throw (ScalarConverter::ConvertImpossibleException("Error"));
	}
};

void	ScalarConverter::toInt(const std::string& literal)
{
	std::istringstream	iss(literal);

	std::cout << "int: ";
	iss >> ScalarConverter::m_val_int;

	if (iss)
	{
		return ;
	}
	else
	{
		throw (ScalarConverter::ConvertImpossibleException("Error"));
	}
};

void	ScalarConverter::toFloat(const std::string& literal)
{
	std::istringstream	iss(literal);

	std::cout << "float: ";
	iss >> ScalarConverter::m_val_float;

	if (iss)
	{
		return ;
	}
	else
	{
		throw (ScalarConverter::ConvertImpossibleException("Error"));
	}
};

void	ScalarConverter::toDouble(const std::string& literal)
{
	std::istringstream	iss(literal);

	std::cout << "double: ";
	iss >> ScalarConverter::m_val_double;

	if (iss)
	{
		return ;
	}
	else
	{
		throw (ScalarConverter::ConvertImpossibleException("Error"));
	}
};


void	ScalarConverter::convert(const std::string& literal)
{
	// ScalarConverter a; //compile error. Constructor 'exist but Undefined'.
	// (void)a; // if constructor not exist in headerfile, Nothing error when create instance.

	try
	{
		toChar(literal);
		std::cout << "'" << ScalarConverter::m_val_char << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		toInt(literal);
		std::cout << ScalarConverter::m_val_int << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		toFloat(literal);
		std::cout << ScalarConverter::m_val_float << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		toDouble(literal);
		std::cout << ScalarConverter::m_val_double << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
};

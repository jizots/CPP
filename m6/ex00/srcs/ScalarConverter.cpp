#include "ScalarConverter.hpp"
#include "Libft.hpp"
#include <cmath>
#include <limits>
#include <iomanip>

char			ScalarConverter::m_val_char = 0;
int				ScalarConverter::m_val_int = 0;
float			ScalarConverter::m_val_float = 0;
double			ScalarConverter::m_val_double = 0;
unsigned char	ScalarConverter::m_type = 0;

void	ScalarConverter::printAsChar(void)
{
	std::cout << "char: ";
	if ((ScalarConverter::m_type >> type_char) & 1U)
	{
		if (std::isprint(static_cast<int>(ScalarConverter::m_val_char)))
			std::cout << "'" << ScalarConverter::m_val_char << "'" << std::endl;
		else
			throw (ScalarConverter::ConvertImpossibleException("Non displayable"));
	}
	else
		throw (ScalarConverter::ConvertImpossibleException("Impossible"));
	return ;
};

void	ScalarConverter::printAsInt(void)
{
	std::cout << "int: ";
	if ((ScalarConverter::m_type >> type_int) & 1U)
		std::cout << ScalarConverter::m_val_int << std::endl;
	else
		throw (ScalarConverter::ConvertImpossibleException("Impossible"));
	return ;
};

void	ScalarConverter::printAsFloat(void)
{
	std::cout << "float: ";
	if ((ScalarConverter::m_type >> type_float) & 1U)
		std::cout << std::fixed << std::setprecision(1)
			<< ScalarConverter::m_val_float << "f" << std::endl;
	else
		throw (ScalarConverter::ConvertImpossibleException("Impossible"));
	return ;
};

void	ScalarConverter::printAsDouble(void)
{
	std::cout << "double: ";
	if ((ScalarConverter::m_type >> type_double) & 1U)
		std::cout << std::fixed << std::setprecision(1)
			<< ScalarConverter::m_val_double << std::endl;
	else
		throw (ScalarConverter::ConvertImpossibleException("Impossible"));
	return ;
};

bool	ScalarConverter::isChar(const std::string& literal)
{
	std::istringstream	iss(literal);
	
	iss >> ScalarConverter::m_val_char;
	return (literal.size() == 1 && std::isdigit(static_cast<int>(literal[0])) == false);
}

bool	ScalarConverter::isNum(const std::string& str)
{
	size_t	i = 0;
	bool	hasDigits = false;

	for ( ;i < str.size() && std::isspace(static_cast<int>(str[i])); ++i)
		i++;
	if (i < str.size() && (str[i] == '+' || str[i] == '-'))
		i++;
	for ( ;i < str.size() && std::isdigit(static_cast<int>(str[i])); ++i)
		hasDigits = true;
	return (hasDigits && i == str.size());
}

bool	ScalarConverter::isInt(const std::string& literal)
{
	std::istringstream	iss(literal);
	iss >> ScalarConverter::m_val_int;

	return (iss && isNum(literal));
}

bool	ScalarConverter::isFloatingPointNum(const std::string& str)
{
	size_t	i = 0;
	bool	hasDigits = false;
	bool	hasPeriod = false;

	for ( ;i < str.size() && std::isspace(static_cast<int>(str[i])); ++i)
		;
	if (i < str.size() && (str[i] == '+' || str[i] == '-'))
		i++;
	for ( ;i < str.size() && std::isdigit(static_cast<int>(str[i])); ++i)
		hasDigits = true;
	if (i < str.size() && str[i] == '.')
	{
		hasPeriod = true;
		i++;
	}
	for ( ;i < str.size() && std::isdigit(static_cast<int>(str[i])); ++i)
		hasDigits = true;
	return (hasDigits && i == str.size());
}

bool	ScalarConverter::isFloat(const std::string& literal)
{
	std::istringstream	iss(literal);

	iss >> ScalarConverter::m_val_float;
	if (std::isnan(ScalarConverter::m_val_float) || std::isinf(ScalarConverter::m_val_float))
		return (true);
	iss.str("");
	iss.clear();
	ScalarConverter::m_val_float = 0;
	if (literal[literal.size() - 1] != 'f')
		return (false);

	std::string	substr(literal.substr(0, literal.size() - 1));

	iss.str(substr);
	iss >> ScalarConverter::m_val_float;
	return (iss	&& isFloatingPointNum(substr));
}

bool	ScalarConverter::isDouble(const std::string& literal)
{
	std::istringstream	iss(literal);

	iss >> ScalarConverter::m_val_double;
	return (iss
			&& (isFloatingPointNum(literal)
				|| std::isnan(ScalarConverter::m_val_double)
				|| std::isinf(ScalarConverter::m_val_double)));
}

void	ScalarConverter::analyzeLiteralType(const std::string& literal)
{
	if (isChar(literal))
	{
		ScalarConverter::m_type = (1 << type_char);
		ScalarConverter::m_type += (1 << type_int);
		ScalarConverter::m_val_int = static_cast<int>(ScalarConverter::m_val_char);
		ScalarConverter::m_type += (1 << type_float);
		ScalarConverter::m_val_float = static_cast<float>(ScalarConverter::m_val_char);
		ScalarConverter::m_type += (1 << type_double);
		ScalarConverter::m_val_double = static_cast<double>(ScalarConverter::m_val_char);
	}
	else if (isInt(literal))
	{
		ScalarConverter::m_type = (1 << type_int);
		if (Libft::isWithinRange<unsigned char, int>(ScalarConverter::m_val_int))
		{
			ScalarConverter::m_type += (1 << type_char);
			ScalarConverter::m_val_char = static_cast<unsigned char>(ScalarConverter::m_val_int);
		}
		ScalarConverter::m_type += (1 << type_float);
		ScalarConverter::m_val_float = static_cast<float>(ScalarConverter::m_val_int);
		ScalarConverter::m_type += (1 << type_double);
		ScalarConverter::m_val_double = static_cast<double>(ScalarConverter::m_val_int);
	}
	else if (isFloat(literal))
	{
		ScalarConverter::m_type = (1 << type_float);
		if (Libft::isWithinRange<unsigned char, float>(ScalarConverter::m_val_float))
		{
			ScalarConverter::m_type += (1 << type_char);
			ScalarConverter::m_val_char = static_cast<unsigned char>(ScalarConverter::m_val_float);
		}
		if (Libft::isWithinRange<int, float>(ScalarConverter::m_val_float))
		{
			ScalarConverter::m_type += (1 << type_int);
			ScalarConverter::m_val_int = static_cast<int>(ScalarConverter::m_val_float);
		}
		ScalarConverter::m_type += (1 << type_double);
		ScalarConverter::m_val_double = static_cast<double>(ScalarConverter::m_val_float);
	}
	else if (isDouble(literal))
	{
		ScalarConverter::m_type = (1 << type_double);
		if (Libft::isWithinRange<unsigned char, double>(ScalarConverter::m_val_double))
		{
			ScalarConverter::m_type += (1 << type_char);
			ScalarConverter::m_val_char = static_cast<unsigned char>(ScalarConverter::m_val_double);
		}
		if (Libft::isWithinRange<int, double>(ScalarConverter::m_val_double))
		{
			ScalarConverter::m_type += (1 << type_int);
			ScalarConverter::m_val_int = static_cast<int>(ScalarConverter::m_val_double);
		}
		if (Libft::isWithinRange<float, double>(ScalarConverter::m_val_double))
		{
			ScalarConverter::m_type += (1 << type_float);
			ScalarConverter::m_val_float = static_cast<float>(ScalarConverter::m_val_double);
		}
	}
};

void	ScalarConverter::convert(const std::string& literal)
{
	// ScalarConverter a; //compile error. Constructor 'exist but Undefined'.
	// (void)a; // if constructor not exist in headerfile, Nothing error when create instance.

	analyzeLiteralType(literal);
	try
	{
		printAsChar();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		printAsInt();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		printAsFloat();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		printAsDouble();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
};

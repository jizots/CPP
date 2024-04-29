#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>
#include <algorithm>
#include <ctime>

BitcoinExchange::BitcoinExchange(const std::string& filePath)
{
	inputExchangeRate("data.csv");
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{

};

BitcoinExchange::~BitcoinExchange(void)
{

};

float BitcoinExchange::getExchangeRate(const std::string& exchangeDate) const
{

};

void 	BitcoinExchange::inputExchangeRate(const std::string& filePath)
{
	std::ifstream	ifs(filePath);

	if (ifs.fail())
		throw ("failed to open: " + filePath);
	else
	{
		std::string line;
		while (std::getline(ifs, line))
		{
			if (isCsvLine(line))
				addMapByCSVLine(line);
		}
	}
};

void	BitcoinExchange::addMapByCSVLine(const std::string& line)
{
	std::string::size_type pos = line.find(",");
	std::string date = line.substr(0, pos);
	float value = isNumericType<float>(line.substr(pos + 1));

	m_exchangeRate.insert(std::pair<std::string, float>(date, value));
};

const bool	BitcoinExchange::isCsvLine(const std::string& line)
{
	std::string::size_type count = 0;
	std::string::size_type pos = 0;

	while (pos < line.size() && std::string::npos != (pos = line.find(',', pos)))
	{
		++count;
		++pos;
	}
	if (count != (CSV_ITEM - 1))
		return (false);
	return (true);
};

const bool	BitcoinExchange::isValidDataFormat(const std::string& date)
{
	//expect yyyy-mm-dd
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	if (!isStringComposedWithFunc(date.substr(0, 4), std::isdigit)
		|| !isStringComposedWithFunc(date.substr(5, 2), std::isdigit)
		|| !isStringComposedWithFunc(date.substr(8), std::isdigit))
		return (false);

	//check effective date
	struct tm inputTime;
	std::stringstream ss;
	int val;

	ss << date.substr(0, 4);
	ss >> val;
	if (ss.fail())
		throw ("unexpected error: " + date);
	inputTime.tm_year = val - 1900;
	ss.str("");

	ss << date.substr(5, 2);
	ss >> val;
	if (ss.fail())
		throw ("unexpected error: " + date);
	if (val < 1 && 12 < val)
		return (false);
	inputTime.tm_mon = val - 1;
	ss.str("");

	ss << date.substr(8);
	ss >> val;
	if (ss.fail())
		throw ("unexpected error: " + date);
	if (val < 1 && 31 < val)
		return (false);
	inputTime.tm_mday = val;
	ss.str("");
	
	return (true);
};

static bool	isStringComposedWithFunc(const std::string& str, int (*f)(int))
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


BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{

};
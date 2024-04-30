#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>

BitcoinExchange::BitcoinExchange(const std::string& filePath)
{
	inputExchangeRate("data.csv");
	outputExchangeResult(filePath);
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
	bool isHead = true;

	if (ifs.fail())
		throw ("failed to open: " + filePath);
	else
	{
		std::string line;
		while (true)
		{
			if (!std::getline(ifs, line))
			{
				if (ifs.bad())
					throw ("ifs.bad() occured.");
				else if (!ifs.eof())
					throw ("!ifs.eof() detected.");
				else
					break ;
			}
			if (isHead)
			{
				handleCsvHeader(line);
				isHead = false;
			}
			else
			{
				if (isCsvLine(line))
					addMapByCSVLine(line);
				else
					throw ("CSV format error.");
			}
		}
	}
	return ;
};

void	BitcoinExchange::addMapByCSVLine(const std::string& line)
{
	std::string::size_type pos = line.find(",");
	std::string date = line.substr(0, pos);
	bool isInserted;

	if (!isValidDateFormat(date))
		throw ("Not effective date: " + line);
	float value = isNumericType<float>(line.substr(pos + 1));

	isInserted = (m_exchangeRate.insert(std::pair<std::string, float>(date, value))).second;
	if (!isInserted)
		throw ("Date duplicated: " + line);
	return ;
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

const bool	BitcoinExchange::isValidDateFormat(const std::string& date)
{
	//expect yyyy-mm-dd
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	if (!isStringComposedWithFunc(date.substr(0, 4), std::isdigit)
		|| !isStringComposedWithFunc(date.substr(5, 2), std::isdigit)
		|| !isStringComposedWithFunc(date.substr(8), std::isdigit))
		return (false);

	//check date
	struct tm inputTime;
	std::stringstream ss;
	int val;

	ss << date.substr(0, 4);
	ss >> val;
	if (ss.fail())
		throw ("unexpected error: " + date);
	m_date.year = val;
	ss.str("");

	ss << date.substr(5, 2);
	ss >> val;
	if (ss.fail())
		throw ("unexpected error: " + date);
	m_date.month = val;
	ss.str("");

	ss << date.substr(8);
	ss >> val;
	if (ss.fail())
		throw ("unexpected error: " + date);
	m_date.day = val;
	ss.str("");

	if (!isEffectiveDate(m_date.year, m_date.month, m_date.day))
		return (false);	
	return (true);
};

bool BitcoinExchange::isEffectiveDate(const int year, const int month, const int day)
{
	bool isLeap = false;
	bool isBigMonth = false;
	bool isFeb = false;

	if (isLeapYear(year))
		isLeap = true;
	if (year <= 0)
		return (false);
	switch (month)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			isBigMonth = true;
			break;
		case 2:
			isFeb = true;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			break ;
		default:
			return (false);
	}
	if (isBigMonth && 1 <= day && day <= 31)
		return (true);
	else if (isFeb && isLeap && 1 <= day && day <=29)
		return (true);
	else if (isFeb && !isLeap && 1 <= day && day <= 28)
		return (true);
	else if (!isBigMonth && 1 <= day && day <= 30)
		return (true);
	else
		return (false);
};

bool BitcoinExchange::isLeapYear(const int year)
{
	if ((year % 4) == 0 && ((year % 100) != 0 || (year % 400) == 0))
		return (true);
	else
		return (false);
};

bool	BitcoinExchange::isStringComposedWithFunc(const std::string& str, int (*f)(int))
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

void  BitcoinExchange::outputExchangeResult(const std::string& filePath)
{
	std::ifstream	ifs(filePath);
	bool isHead = true;

	if (ifs.fail())
		throw ("failed to open: " + filePath);
	else
	{
		std::string line;
		while (true)
		{
			if (!std::getline(ifs, line))
			{
				if (ifs.bad())
					throw ("ifs.bad() occured.");
				else if (!ifs.eof())
					throw ("!ifs.eof() detected.");
				else
					break ;
			}
			if (isHead)
			{
				handleCsvHeader(line);
				isHead = false;
			}
			else
			{
				if (isCsvLine(line))
					addMapByCSVLine(line);
				else
					throw ("CSV format error.");
			}
		}
	}
	return ;
};

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{

};

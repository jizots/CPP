#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>
#include <algorithm>
#include <iostream>

BitcoinExchange::BitcoinExchange(const std::string& filePath)
	:m_filePath(filePath)
{
	handleLineFromFile("data.csv", &BitcoinExchange::handleCsvToMap);
	if (m_exchangeRate.size() == 0)
		throw ("CSV was not exist");
	handleLineFromFile(m_filePath, &BitcoinExchange::handleInputToOutput);
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	:m_filePath(other.m_filePath),
	 m_exchangeRate(other.m_exchangeRate)
{
	handleLineFromFile(m_filePath, &BitcoinExchange::handleInputToOutput);
};

BitcoinExchange::~BitcoinExchange(void)
{};

bool BitcoinExchange::isHead = true;

void	BitcoinExchange::handleLineFromFile(const std::string& filePath, void (BitcoinExchange::*func)(const std::string& line))
{
	std::ifstream	ifs(filePath);

	if (ifs.fail())
		throw ("failed to open: " + filePath);
	else
	{
		std::string line;
		while (std::getline(ifs, line))
			(this->*func)(line);
		if (ifs.bad())
			throw ("ifs.bad() occured.");
		else if (!ifs.eof())
			throw ("!ifs.eof() detected.");
	}
	isHead = true;
	return ;
};

void	BitcoinExchange::handleCsvToMap(const std::string& line)
{
	{
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

void	BitcoinExchange::handleCsvHeader(const std::string& line)
{
	if (!isCsvLine(line))
		throw ("CSV format error.");
}

void	BitcoinExchange::addMapByCSVLine(const std::string& line)
{
	std::string::size_type pos = line.find(",");
	std::string date = line.substr(0, pos);
	bool isInserted;

	if (!isValidDateFormat(date))
		throw ("Not effective date: " + line);
	double value = isNumericType<double>(line.substr(pos + 1));

	isInserted = (m_exchangeRate.insert(std::pair<std::string, double>(date, value))).second;
	if (!isInserted)
		throw ("Date duplicated: " + line);
	return ;
};

void	BitcoinExchange::handleInputToOutput(const std::string& line)
{
	if (isHead)
	{
		// Ignore header
		isHead = false;
	}
	else
	{
		try
		{
			if(isEffectiveInput(line))
			{
				double rate = getExchangeRate(m_targetDate);
				std::cout << m_targetDate;
				std::cout << " => ";
				std::cout << m_targetAmount;
				std::cout << " = ";
				std::cout << (m_targetAmount * rate) << std::endl;
			}
			else
				std::cout << "Error: bad input => " << line << std::endl;
		}
		catch(const std::string& e)
		{
			std::cout << e << '\n';
		}
	}
}

double BitcoinExchange::getExchangeRate(const std::string& exchangeDate) const
{
	std::map<std::string, double>::const_iterator itr = m_exchangeRate.find(exchangeDate);

	if (itr != m_exchangeRate.end())
		return (itr->second);

	itr = m_exchangeRate.lower_bound(exchangeDate);
	if (itr->first == m_exchangeRate.begin()->first && exchangeDate < itr->first)
		throw ("Error: bad input => " + exchangeDate);
	else
	{
		--itr;
		return (itr->second);
	}
};

bool	BitcoinExchange::isEffectiveInput(const std::string& line)
{
	//verify date
	std::string::size_type start = line.find_first_not_of(WHITE_SPACE, 0);
	if (start == std::string::npos)
		return (false);
	std::string::size_type end = line.find_first_of(WHITE_SPACE + std::string("|"), start);
	if (end == std::string::npos || start == end)
		return (false);
	end -= 1;
	m_targetDate = line.substr(start, end - start + 1);
	if (!isValidDateFormat(m_targetDate))
		throw ("Error: bad input => " + m_targetDate);

	//verify double value
	start = line.find_first_of("|", end + 1);
	if (start == std::string::npos)
		return (false);
	start = line.find_first_not_of(WHITE_SPACE, start + 1);
	if (start == std::string::npos)
		return (false);
	end = line.find_first_of(WHITE_SPACE, start);
	if (end == std::string::npos)
		end = line.size() - 1;
	else
		end -= 1;
	m_targetAmount = isNumericType<double>(line.substr(start, end - start + 1));
	if (m_targetAmount < 0)
		throw ("Error: not a positive number => " + line.substr(start, end - start + 1));
	if (1000 < m_targetAmount)
		throw ("Error: too large a number => " + line.substr(start, end - start + 1));
	return (true);
};

bool	BitcoinExchange::isCsvLine(const std::string& line)
{
	std::string::size_type count = 0;
	std::string::size_type pos = 0;

	while (pos < line.size() && std::string::npos != (pos = line.find(',', pos)))
	{
		++count;
		++pos;
	}
	if (count != (NUM_ITEMS_PER_LINE - 1))
		return (false);
	return (true);
};

bool	BitcoinExchange::isValidDateFormat(const std::string& date)
{
	//expect yyyy-mm-dd
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	if (!isStringComposedWithFunc(date.substr(0, 4), std::isdigit)
		|| !isStringComposedWithFunc(date.substr(5, 2), std::isdigit)
		|| !isStringComposedWithFunc(date.substr(8), std::isdigit))
		return (false);

	//check date
	std::stringstream ss;
	int val;

	ss << date.substr(0, 4);
	ss >> val;
	if (ss.fail())
		throw ("unexpected error: year " + date);
	m_date.year = val;
	ss.str("");
	ss.clear(std::stringstream::goodbit);

	ss << date.substr(5, 2);
	ss >> val;
	if (ss.fail())
		throw ("unexpected error: month " + date);
	m_date.month = val;
	ss.str("");
	ss.clear(std::stringstream::goodbit);

	ss << date.substr(8);
	ss >> val;
	if (ss.fail())
		throw ("unexpected error: day " + date);
	m_date.day = val;
	ss.str("");
	ss.clear(std::stringstream::goodbit);

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
	else if (!isFeb && !isBigMonth && 1 <= day && day <= 30)
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

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{
	if (this == &rhs)
		return (*this);
	m_exchangeRate = rhs.m_exchangeRate;
	m_filePath = rhs.m_filePath;
	return (*this);
};
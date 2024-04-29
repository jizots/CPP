#include "BitcoinExchange.hpp"
#include <fstream>
#include <string>
#include <algorithm>

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

	m_exchangeRate.insert(std::make_pair<std::string, float>(date, value));
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

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& rhs)
{

};
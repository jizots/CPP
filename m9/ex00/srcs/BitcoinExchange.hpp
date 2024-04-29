#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <sstream>
# define CSV_ITEM 2
class BitcoinExchange
{
public:
	BitcoinExchange(const std::string& filePath);
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange(void);

	float getExchangeRate(const std::string& exchangeDate) const;

private:
	std::map<std::string, float> m_exchangeRate;
	std::string m_targetDate;
	float m_targetAmount;

private:
	BitcoinExchange(void);
	void 				inputExchangeRate(const std::string& filePath);
	void				addMapByCSVLine(const std::string& line);
	const bool			isCsvLine(const std::string& line);
	template <typename T>
	T isNumericType(const std::string& literal)
	{
		std::istringstream iss(literal);
		T t;

		iss >> t;
		if (iss.fail() || !iss.eof())
			throw std::invalid_argument("Error. Argument is invalid literal.");
		return (t);
	};

public:
	BitcoinExchange& operator=(const BitcoinExchange& rhs);

};

#endif
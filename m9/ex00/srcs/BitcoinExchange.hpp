#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <sstream>
# define NUM_ITEMS_PER_LINE 2
# define WHITE_SPACE "\t\n\v\f\r "

struct Date{
	int year;
	int month;
	int day;
};

class BitcoinExchange
{
public:
	BitcoinExchange(const std::string& filePath);
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange(void);

	void  outputExchangeResult(const std::string& filePath);
	float getExchangeRate(const std::string& exchangeDate) const;

private:
	std::map<std::string, float> m_exchangeRate;
	Date	m_date;
	float	m_targetAmount;

private:
	BitcoinExchange(void);
	void 		handleLineFromFile(const std::string& filePath, void (BitcoinExchange::*func)(const std::string& line));
	void		handleCsvToMap(const std::string& line);
	void		handleCsvHeader(const std::string& line);
	void		addMapByCSVLine(const std::string& line);
	void		handleInputToOutput(const std::string& line);
	const bool	isEffectiveInput(const std::string& line);
	const bool	isCsvLine(const std::string& line);
	const bool	isValidDateFormat(const std::string& date);
	static bool	isEffectiveDate(const int year, const int month, const int day);
	static bool	isLeapYear(const int year);
	static bool	isStringComposedWithFunc(const std::string& str, int (*f)(int));
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
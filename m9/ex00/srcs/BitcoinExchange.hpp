#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <sstream>
# define NUM_ITEMS_PER_LINE 2
# define WHITE_SPACE "\t\n\v\f\r "

class BitcoinExchange
{
public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange(void);
	double 	getExchangeRate(const std::string& exchangeDate) const;
	void 	handleLineFromFile(const std::string& filePath,
			void (BitcoinExchange::*func)(const std::string& line, const bool isHead));
	void	handleCsvToMap(const std::string& line, const bool isHead);
	void	handleInputToOutput(const std::string& line, const bool isHead);
	const std::map<std::string, double>&	getExchangeRateData(void) const;

private:
	std::map<std::string, double>	m_exchangeRate;

private:
	void	handleCsvHeader(const std::string& line);
	void	addMapByCSVLine(const std::string& line);
	void  	outputExchangeResult(const std::string& filePath);
	bool	isEffectiveInput(const std::string& line, std::string& targetDate, double& targetAmount);
	bool	isCsvLine(const std::string& line);
	bool	isValidDateFormat(const std::string& date);
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
			throw ("Error: Argument is invalid literal => " + literal);
		return (t);
	};

public:
	BitcoinExchange& operator=(const BitcoinExchange& rhs);

};

#endif
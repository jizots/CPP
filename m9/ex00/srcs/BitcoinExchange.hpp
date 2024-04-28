#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>

class BitcoinExchange
{
public:
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange& other);
	~BitcoinExchange(void);

private:

public:
	BitcoinExchange& operator=(const BitcoinExchange& rhs);
};

#endif
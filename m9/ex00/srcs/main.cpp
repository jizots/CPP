#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error. Invalid number of arguments." << std::endl;
		return (1);
	}
	try
	{
		std::cout << "+++ basic test +++" << std::endl; 
		BitcoinExchange exchange;
		exchange.handleLineFromFile("data.csv", &BitcoinExchange::handleCsvToMap);
		exchange.handleLineFromFile(argv[1], &BitcoinExchange::handleInputToOutput);
		std::cout << std::endl; 

		std::cout << "+++ copy & assingment test +++" << std::endl; 
		BitcoinExchange ex2(exchange);
		std::cout << std::endl; 
		ex2 = exchange;
		std::cout << ex2.getExchangeRate("2012-12-31") << std::endl;
		std::cout << std::endl;

		std::cout << "+++ empty test +++" << std::endl;
		BitcoinExchange empty;
		std::cout << empty.getExchangeRateData().size() << std::endl;
		try
		{
			std::cout << empty.getExchangeRate("2012-12-31") << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}	 
		std::cout << std::endl;
		 
		std::cout << "+++ append data test +++" << std::endl;
		exchange.handleLineFromFile("append.csv", &BitcoinExchange::handleCsvToMap);
		std::cout << exchange.getExchangeRate("2012-12-31") << std::endl;
		// BitcoinExchange compile_error();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	return (0);
}
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
		BitcoinExchange exchange(argv[1]);
		std::cout << exchange.getExchangeRate("2021-01-01") << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	catch(const std::string& e)
	{
		std::cout << e << '\n';
	}
	
	return (0);
}
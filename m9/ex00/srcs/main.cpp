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
		std::cout << "+++++++++++++++++++++++" << std::endl; 
		BitcoinExchange exchange(argv[1]);
		std::cout << std::endl; 
		std::cout << "+++++++++++++++++++++++" << std::endl; 
		BitcoinExchange ex2(exchange);
		std::cout << std::endl; 
		std::cout << "+++++++++++++++++++++++" << std::endl; 
		ex2 = exchange;
		std::cout << ex2.getExchangeRate("2012-12-31") << std::endl;
		std::cout << std::endl; 
		std::cout << "+++++++++++++++++++++++" << std::endl;
		// BitcoinExchange compile_error();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	catch(const char* e)
	{
		std::cout << e << '\n';
	}
	catch(const std::string& e)
	{
		std::cout << e << '\n';
	}
	return (0);
}
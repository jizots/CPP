#include <iostream>
#include "Span.hpp"

int main() {
	try
	{
		std::cout << "-- subject test --" << std::endl;
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		// sp.addNumber(11);//too many element added
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << std::endl;

		std::cout << "-- my test --" << std::endl;
		{
			std::cout << "[copy constructor]" << std::endl;
			Span copy(sp);
			std::cout << copy.shortestSpan() << std::endl;
			std::cout << copy.longestSpan() << std::endl;
			std::cout << std::endl;
		}
		{
			std::cout << "[copy assignment]" << std::endl;
			Span copy(5);
			// Span copy(3);//error
			copy = sp;
			std::cout << copy.shortestSpan() << std::endl;
			std::cout << copy.longestSpan() << std::endl;
			std::cout << std::endl;
		}
		{
			unsigned int size = 10;
			std::cout << "[addManyNumbers]" << std::endl;
			Span sp = Span(size);
			sp.addManyNumbers(size);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
			std::cout << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q cpp08ex01");
}
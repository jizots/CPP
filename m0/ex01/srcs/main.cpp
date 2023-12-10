#include <iostream>
#include <ctype.h>
#include <iomanip>
#include "Libft.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"

void	main_loop(PhoneBook& book)
{
	std::string	input;

	while(1)
	{
		std::cout << "PhoneBook> ";
		if (!std::getline(std::cin, input) || std::cin.eof())
			break;
		else if (input == "ADD")
			book.PhoneBook::add();
		else if (input == "SEARCH")
			book.PhoneBook::search();
		else if (input == "EXIT")
		{
			std::cout << Libft::get_colored_string("bye!", green) << std::endl;
			return ;
		}
		else if (!input.empty())
			std::cout << "No function: " << Libft::get_colored_string(input, red) << std::endl;
	}
}

int main(int ac, char **av)
{
	PhoneBook	book;

	(void)av;
	if (1 < ac)
	{
		std::cout << Libft::get_colored_string("Error. Program can't accept arguments.", red) << std::endl;
		return (-1);
	}
	book.init_book();
	main_loop(book);
	return (0);
}

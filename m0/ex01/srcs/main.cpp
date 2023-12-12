#include "PhoneBook.hpp"

extern std::string	_contact_item[];

void	main_loop(PhoneBook& book)
{
	std::string	input;

	while(1)
	{
		std::cout << "PhoneBook> ";
		if (Libft::getline_wrap(input) || input == "EXIT")
		{
			Libft::print_colored_string_endl("Oh! bye forever!", green);
			return ;
		}
		else if (input == "ADD")
			book.PhoneBook::add();
		else if (input == "SEARCH")
			book.PhoneBook::search();
		else if (!input.empty())
		{
			std::cout << "No function: ";
			Libft::print_colored_string_endl(input, red);
		}
	}
}

int main(int ac, char **av)
{
	PhoneBook	book;

	(void)av;
	if (1 < ac)
	{
		Libft::print_colored_string_endl("Error. Program can't accept arguments.", red);
		return (-1);
	}
	book.init_book();
	main_loop(book);
	return (0);
}

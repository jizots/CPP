#include <iostream>
#include <ctype.h>
#include <iomanip>
#include "libft.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"

int	set_index(PhoneBook& book)
{
	int	oldest;

	if (book.volume < 7)
		return (book.volume);
	oldest = 0;
	for (int i = 1; i < 8; ++i)
	{
		if (book.phone_book[oldest].time_register > book.phone_book[i].time_register)
			oldest = i;
	}
	return (oldest);
}

void	to_contact(Contact& tmp_contact, int i, std::string input)
{
	switch (i)
	{
	case first_name:
		tmp_contact.first_name = input;
		break;
	case last_name:
		tmp_contact.last_name = input;
		break;
	case nickname:
		tmp_contact.nickname = input;
		break;
	case phone_number:
		tmp_contact.phone_number = input;
		break;
	case darkest_secret:
		tmp_contact.darkest_secret = input;
		break;
	}
}

void	to_phonebook(PhoneBook& book, Contact& tmp_contact)
{
	book.phone_book[tmp_contact.index].first_name = tmp_contact.first_name;
	book.phone_book[tmp_contact.index].last_name = tmp_contact.last_name;
	book.phone_book[tmp_contact.index].nickname = tmp_contact.nickname;
	book.phone_book[tmp_contact.index].phone_number = tmp_contact.phone_number;
	book.phone_book[tmp_contact.index].darkest_secret = tmp_contact.darkest_secret;
	book.phone_book[tmp_contact.index].time_register = tmp_contact.time_register;
}

void	adding_loop(Contact& tmp_contact)
{
	std::string	contact_item[] = {
		"[first name]", "[last name]", "[nickname]", "[phone number]", "[darkest secret]"
	};
	std::string	input;
	int			i;

	i = 0;
	while(i < 5)
	{
		std::cout << "	" << contact_item[i] << " > ";
		if (!std::getline(std::cin, input) || std::cin.eof())
			break;
		else if (input.empty())
			continue;
		else
		{
			to_contact(tmp_contact, i, input);
			i++;
		}
	}
}

void	add(PhoneBook& book)
{
	Contact	tmp_contact;

	tmp_contact.index = set_index(book);
	tmp_contact.time_register = clock();
	std::cout << get_colored_string("Mode: Add", blue) << std::endl;
	adding_loop(tmp_contact);
	to_phonebook(book, tmp_contact);
	if (book.volume < 8)
		book.volume += 1;
	std::cout << get_colored_string("Success!", green) << std::endl;
}

void	search(PhoneBook& book)
{
	std::cout << get_colored_string("Mode: Search", blue) << std::endl;
	for (int i = 0; i < 8; ++i)
	{
		std::cout << book.phone_book[i].index << "|" << book.phone_book[i].first_name << std::endl;
	}
}

void	main_loop(PhoneBook& book)
{
	std::string	input;

	while(1)
	{
		std::cout << "PhoneBook> ";
		if (!std::getline(std::cin, input) || std::cin.eof())
			break;
		else if (input == "ADD")
			add(book);
		else if (input == "SEARCH")
			search(book);
		else if (input == "EXIT")
		{
			std::cout << get_colored_string("bye!", green) << std::endl;
			exit (0);
		}
		else if (!input.empty())
			std::cout << "No function: " << get_colored_string(input, red) << std::endl;
	}
}

int main(int ac, char **av)
{
	PhoneBook	book;

	(void)av;
	if (1 < ac)
	{
		std::cout << get_colored_string("Error. Program can't accept arguments.", red) << std::endl;
		return (-1);
	}
	for (int i = 0; i < 8; i++)
	{
		book.phone_book[i].index = i;
		book.volume = 0;
	}
	main_loop(book);
	return (0);
}

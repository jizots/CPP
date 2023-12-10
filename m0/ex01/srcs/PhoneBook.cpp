#include "PhoneBook.hpp"

int		PhoneBook::get_volume()
{
	return (m_volume);
}

void	PhoneBook::set_volume(int volume)
{
	this->m_volume = volume;
}

void	PhoneBook::init_book()
{
	for (int i = 0; i < 8; ++i)
	{
		this->m_book[i].Contact::set_index(i);
	}
	set_volume(0);
}

int	PhoneBook::get_oldest_index()
{
	int	oldest;

	if (this->m_volume < 7)
		return (this->m_volume);
	oldest = 0;
	for (int i = 1; i < 8; ++i)
	{
		if (this->m_book[oldest].Contact::get_time_register() > this->m_book[i].Contact::get_time_register())
			oldest = i;
	}
	return (oldest);
}

void	PhoneBook::add_to_phonebook(Contact& tmp_contact)
{
	this->m_book[tmp_contact.Contact::get_index()].to_contact(0, tmp_contact.Contact::get_fname());
	this->m_book[tmp_contact.Contact::get_index()].to_contact(1, tmp_contact.Contact::get_lname());
	this->m_book[tmp_contact.Contact::get_index()].to_contact(2, tmp_contact.Contact::get_nickname());
	this->m_book[tmp_contact.Contact::get_index()].to_contact(3, tmp_contact.Contact::get_phonenumber());
	this->m_book[tmp_contact.Contact::get_index()].to_contact(4, tmp_contact.Contact::get_darkest_secret());
	this->m_book[tmp_contact.Contact::get_index()].set_time_register(tmp_contact.get_time_register());
}

void	PhoneBook::add()
{
	Contact	tmp_contact;

	std::cout << Libft::get_colored_string("Mode: Add", blue) << std::endl;
	tmp_contact.Contact::set_index(this->get_oldest_index());
	tmp_contact.Contact::set_time_register(clock());
	if (tmp_contact.Contact::adding_loop() == -1)
		return ;
	PhoneBook::add_to_phonebook(tmp_contact);
	if (PhoneBook::get_volume() < 8)
		this->PhoneBook::set_volume(this->get_volume() + 1);
	std::cout << Libft::get_colored_string("Success!", green) << std::endl;
}

void	PhoneBook::search()
{
	std::cout << Libft::get_colored_string("Mode: Search", blue) << std::endl;
	for (int i = 0; i < 8; ++i)
	{
		std::cout << this->m_book[i].get_index() << "|" << this->m_book[i].get_fname() << std::endl;
	}
}

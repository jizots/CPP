#include "PhoneBook.hpp"

int		PhoneBook::get_volume()
{
	return (m_volume);
}

void	PhoneBook::set_volume(int volume)
{
	if (volume < 0)
	{
		std::cout << "volume can't set minus: " << volume << std::endl; 
		return ;
	}
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
	int	index;

	index = tmp_contact.Contact::get_index();
	for (int data_id = 0; data_id <= darkest_secret; ++data_id)
		this->m_book[index].set_contact(data_id, tmp_contact.Contact::get_contact(data_id));
	this->m_book[index].set_time_register(tmp_contact.get_time_register());
}

void	PhoneBook::add()
{
	Contact	tmp_contact;
	
	Libft::print_colored_string_endl("Mode: Add", blue);
	tmp_contact.Contact::add_loop(this->PhoneBook::get_oldest_index(), clock());
		this->PhoneBook::add_to_phonebook(tmp_contact);
	if (PhoneBook::get_volume() < 8)
		this->PhoneBook::set_volume(this->get_volume() + 1);
	Libft::print_colored_string_endl("Success!", green);
}

void	PhoneBook::display_summary_Contact()
{
	std::string	item_data;

	std::cout << std::setw(10) << "index" << '|';
	for (int data_id = first_name; data_id <= nickname; ++data_id)
		std::cout << std::setw(10) << Libft::end_with_c_over_n(contact_item[data_id], '.', 10) << '|';
	std::cout << std::endl;
	for (int index = 0; index < 8; ++index)
	{
		std::cout << std::setw(10) << std::to_string(index) << '|';
		for (int data_id = 0; data_id <= nickname; ++data_id)
		{
			item_data = Libft::end_with_c_over_n(this->m_book[index].Contact::get_contact(data_id), '.', 10);
			std::cout << std::setw(10) << item_data <<'|';
		}
		std::cout << std::endl;
	}
}

void	PhoneBook::display_detail_Contact(int index)
{
	for (int data_id = first_name; data_id <= darkest_secret; ++data_id)
	{
		std::cout << contact_item[data_id] << ": ";
		std::cout << this->m_book[index].get_contact(data_id) << std::endl;
	}
}

void	PhoneBook::search_loop()
{
	std::string	input;
	int			flag_digit;

	while (1)
	{
		std::cout << "  " << " input index less than " << this->get_volume() << " > ";
		if (Libft::getline_wrap(input))
		{
			Libft::print_colored_string_endl("Oh! bye forever!", green);
			exit (0);
		}
		flag_digit = Libft::is_string_composed_with_func(input, std::isdigit);
		if (flag_digit == false)
			Libft::print_colored_string_endl("  Use only numeric.", red);
		else if (this->get_volume() - 1 < Libft::ft_atoi(input))
			Libft::print_colored_string_endl("  No data available.", red);
		else if (!input.empty())
		{
			this->display_detail_Contact(Libft::ft_atoi(input));
			break ;
		}
	}
}

void	PhoneBook::search()
{
	Libft::print_colored_string_endl("Mode: Search", blue);
	PhoneBook::display_summary_Contact();
	PhoneBook::search_loop();
}

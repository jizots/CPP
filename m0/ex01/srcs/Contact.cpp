#include "Contact.hpp"

const std::string	contact_item[] = {
		"first name", "last name", "nickname", "phone number", "darkest secret"
};

int		Contact::get_index()
{
	return (this->m_index);
}

clock_t		Contact::get_time_register()
{
	return (this->m_time_register);
}

std::string	Contact::get_contact(int data_id)
{
	switch (data_id)
	{
	case first_name:
		return (this->m_first_name);
		break;
	case last_name:
		return (this->m_last_name);
		break;
	case nickname:
		return (this->m_nickname);
		break;
	case phone_number:
		return (this->m_phone_number);
		break;
	case darkest_secret:
		return (this->m_darkest_secret);
		break;
	default:
		return("");
	}
}

void	Contact::set_index(int index)
{
	if (index < 0)
	{
		std::cout << "index can't set minus: " << index << std::endl; 
		return ;
	}
	this->m_index = index;
}

void	Contact::set_time_register(clock_t time)
{
	this->m_time_register = time;
}

void	Contact::set_contact(int data_id, std::string data_string)
{
	switch (data_id)
	{
	case first_name:
		this->m_first_name = data_string;
		break;
	case last_name:
		this->m_last_name = data_string;
		break;
	case nickname:
		this->m_nickname = data_string;
		break;
	case phone_number:
		this->m_phone_number = data_string;
		break;
	case darkest_secret:
		this->m_darkest_secret = data_string;
		break;
	}
}

int	Contact::add_loop(int index, clock_t time)
{
	std::string	input;
	int			data_id;

	this->Contact::set_index(index);
	this->Contact::set_time_register(time);
	data_id = first_name;
	while(data_id <= darkest_secret)
	{
		std::cout << "  " << contact_item[data_id] << " > ";
		if (!std::getline(std::cin, input) || std::cin.eof())
		{
			Libft::print_colored_string_endl("Oh! bye forever!", green);
			exit (0);
		}
		else if (input.empty() || Libft::is_string_composed_with_func(input, std::isspace) == true)
			continue;
		else if (data_id == phone_number && Libft::is_string_composed_with_func(input, std::isdigit) == false)
			Libft::print_colored_string_endl("  Use only numeric.", red);
		else if (Libft::is_string_composed_with_func(input, std::isprint) == true
				&& input.find('^') != std::string::npos)
			Libft::print_colored_string_endl("  Cant use '^'.", red);
		else
			this->Contact::set_contact(data_id++, input);
	}
	this->Contact::set_contact(data_id, input);
	return (0);
}

#include "Contact.hpp"

void	Contact::set_index(int index)
{
	this->m_index = index;
}

void	Contact::set_time_register(clock_t time)
{
	this->m_time_register = time;
}

int		Contact::get_index()
{
	return (this->m_index);
}

clock_t	Contact::get_time_register()
{
	return (this->m_time_register);
}

std::string	Contact::get_fname()
{
	return (this->m_first_name);
}

std::string	Contact::get_lname()
{
	return (this->m_last_name);
}

std::string	Contact::get_nickname()
{
	return (this->m_nickname);
}

std::string	Contact::get_phonenumber()
{
	return (this->m_phone_number);
}

std::string	Contact::get_darkest_secret()
{
	return (this->m_darkest_secret);
}

void	Contact::to_contact(int data_id, std::string data_string)
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

int	Contact::adding_loop()
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
			return (-1);
		else if (input.empty())
			continue;
		else if (i == phone_number && Libft::is_string_composed_f(input, std::isdigit) == false)
			std::cout << Libft::get_colored_string("  Use only numeric.", red) << std::endl;
		else
		{
			this->Contact::to_contact(i, input);
			i++;
		}
	}
	this->Contact::to_contact(i, input);
	return (0);
}

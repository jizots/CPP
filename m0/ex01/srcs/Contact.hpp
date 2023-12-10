#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <time.h>
# include "Libft.hpp"

enum Contact_Item
{
	first_name, last_name, nickname, phone_number, darkest_secret, time_to_register
};

//'class'はC言語でいう構造体(struct)のようなもの。
//'public'で定義された変数の中身は、他の関数(mainとか)からアクセスして表示したりできる。
class Contact
{
public:
	void		set_index(int index);
	void		set_time_register(clock_t time);
	int			get_index();
	clock_t		get_time_register();
	std::string	get_fname();
	std::string	get_lname();
	std::string	get_nickname();
	std::string	get_phonenumber();
	std::string	get_darkest_secret();
	void		to_contact(int data_id, std::string data_string);
	int			adding_loop();
private:
	int			m_index;
	clock_t		m_time_register;
	std::string	m_first_name;
	std::string	m_last_name;
	std::string	m_nickname;
	std::string	m_phone_number;
	std::string	m_darkest_secret;
};

#endif
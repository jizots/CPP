#ifndef CONTACT_HPP
# define CONTACT_HPP

/*----include----*/
# include <string>
# include <time.h>
# include "Libft.hpp"

/*----enum----*/
enum Contact_Item
{
	first_name, last_name, nickname, phone_number, darkest_secret, time_to_register
};

/*----global----*/
extern const std::string	contact_item[];

/*----define----*/
//'class'はC言語でいう構造体(struct)のようなもの。
//'public'で定義された変数の中身は、他の関数(mainとか)からアクセスして表示したりできる。

/*
 * Contactには、個人情報が入っている。
*/
class Contact
{
public:
	int			get_index();
	void		set_index(int index);
	clock_t		get_time_register();
	void		set_time_register(clock_t time);
	std::string	get_contact(int data_id);
	void		set_contact(int data_id, std::string data_string);
	int			add_loop(int index, clock_t time);
	bool		is_string_fit_standard(std::string& str, int data_id);
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
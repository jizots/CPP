#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <ctype.h>
# include <iomanip>
# include "Contact.hpp"
# include "Libft.hpp"

extern std::string	_contact_item[];

class PhoneBook
{
public:
	void	init_book();
	void	add();
	void	search();
private:
	Contact	m_book[8];
	int		m_volume;
	int		get_oldest_index();
	void	add_to_phonebook(Contact& tmp_contact);
	void	set_volume(int volume);
	int		get_volume();
	void	display_summary_Contact();
	void	search_loop();
};

#endif
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "Libft.hpp"

class PhoneBook
{
public:
	void	init_book();
	int		get_volume();
	int		get_oldest_index();
	void	add_to_phonebook(Contact& tmp_contact);
	void	add();
	void	search();
private:
	Contact	m_book[8];
	int		m_volume;
	void	set_volume(int volume);
};

#endif
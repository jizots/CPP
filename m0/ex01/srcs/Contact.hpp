#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <time.h>

//'class'はC言語でいう構造体(struct)のようなもの。
//'public'で定義された変数の中身は、他の関数(mainとか)からアクセスして表示したりできる。
class Contact
{
public:
	int			index;
	clock_t		time_register;
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;

private:

};

#endif
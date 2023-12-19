#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
public:
	const std::string&	getType(void);
	void				setType(const std::string& _new_type);

	Weapon(void);
	Weapon(const std::string& new_type);

private:
	std::string m_type;
};


#endif

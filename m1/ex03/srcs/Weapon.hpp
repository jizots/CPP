#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon
{
public:
	const std::string&	getType();
	void				setType(std::string _new_weapon);

	Weapon(void);
	Weapon(std::string name);

private:
	std::string m_namewapon;
};


#endif

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
public:
	void		set_name(std::string name);
	std::string	get_name(void);
	void		announce(void);

	// Zombie();
	~Zombie( void );

private:
	std::string m_name;
};

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

#endif

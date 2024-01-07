#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class ClapTrap
{
public:
	ClapTrap(void);
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	~ClapTrap(void);
	ClapTrap&	operator=(const ClapTrap& rhs);
	virtual void	attack(const std::string& target);
	void			takeDamage(unsigned int amount);
	void			beRepaired(unsigned int amount);
	const std::string&	get_name(void);
	void				set_Hit_points(const unsigned int points);
	unsigned int		get_Hit_points(void) const;
	void				set_Energy_points(const unsigned int points);
	unsigned int		get_Energy_points(void) const;
	void				set_Attack_damage(const unsigned int points);
	unsigned int		get_Attack_damage(void) const;

private:
	std::string			m_name;
	unsigned int		m_Hit_points;
	unsigned int		m_Energy_points;
	unsigned int		m_Attack_damage;
};

#endif
#include "Weapon.hpp"

Weapon::Weapon(const std::string& new_type)
{
	m_type = new_type;
}

void	Weapon::setType(const std::string& _new_type)
{
	m_type = _new_type;
}

const std::string&	Weapon::getType(void)
{
	return (Weapon::m_type);
}

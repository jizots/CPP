#include "Character.hpp"
#include "Libft.hpp"

Character::Character(void)
	:ICharacter("Nameless")
{
	Libft::print_colored_string_endl("Character default constructor called", green);
	for (int i = 0; i < 4; ++i)
		m_slot[i] = NULL;
}

Character::Character(const std::string& name)
	:ICharacter(name)
{
	Libft::print_colored_string_endl("Character constructor(with name) called", green);
	for (int i = 0; i < 4; ++i)
		m_slot[i] = NULL;
}

Character::Character(const Character& other)
	:ICharacter(other.getName())
{
	Libft::print_colored_string_endl("Character copy constructor(with type) called", green);
	copySlot(other);
}

Character::~Character()
{
	Libft::print_colored_string_endl("Character Destructor called", red);
	clearSlot();
}

Character&	Character::operator=(const Character& rhs)//clear is correct? unequip?
{
	Libft::print_colored_string_endl("Character copy assingnment called", blue);
	m_name = rhs.m_name;
	clearSlot();
	copySlot(rhs);
	return (*this);
}

std::string const&	Character::getName() const
{
	return (m_name);
}

void	Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		Libft::print_colored_string_endl("materia is NULL!", yellow);
		return ;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (m == m_slot[i])
		{
			Libft::print_colored_string_endl("materia that is already equiped!", yellow);
			return ;
		}
	}	
	if (AMateria::isFloor(m) == true)
	{
		Libft::print_colored_string_endl("The materia on the floor!", yellow);
		return ;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (m_slot[i] == NULL)
		{
			m_slot[i] = m;
			return ;
		}
	}
	Libft::print_colored_string_endl("slot is full! Drop to Floor", yellow);
	AMateria::addToFloor(m);
}

void	Character::unequip(int idx)
{
	if (idx < 0 || 4 < idx)
	{
		Libft::print_colored_string_endl("id is out of Index", yellow);
		return ;
	}
	if (m_slot[idx] == NULL)
	{
		Libft::print_colored_string_endl("slot is already NULL.", magenta);
		return ;
	}
	AMateria::addToFloor(m_slot[idx]);
	m_slot[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || 4 < idx)
	{
		std::cout << Libft::get_colored_string("id is out of Index ", yellow)
			<< target.getName() << ",s slot#" << idx << std::endl;
		return ;
	}
	if (m_slot[idx] == NULL)
	{
		std::cout << Libft::get_colored_string("NULL slot!! ", yellow)
			<< target.getName() << ",s slot#" << idx << std::endl;
		return ;
	}
	m_slot[idx]->AMateria::use(target);
}

void	Character::copySlot(const Character& src)
{
	for (int i = 0; i < 4; ++i)
	{
		if (src.m_slot[i] != NULL)
			m_slot[i] = src.m_slot[i]->clone();
		else
			m_slot[i] = NULL;
	}
}

void	Character::clearSlot(void)//is correct? if have address with non-new, it's cause crash.
{
	Libft::print_colored_string_endl("Character clearSlot called", yellow);
	for (int i = 0; i < 4; ++i)
		delete m_slot[i];
	for (int i = 0; i < 4; ++i)
		m_slot[i] = NULL;
}

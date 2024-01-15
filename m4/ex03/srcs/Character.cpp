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
		if (m_slot[i] == NULL)
		{
			m_slot[i] = m;
			return ;
		}
	}
	Libft::print_colored_string_endl("slot is full!", yellow);
}

void	Character::unequip(int idx)// Is when delete materia??
{
	if (idx < 0 || 4 < idx)
	{
		Libft::print_colored_string_endl("id is out of Index", yellow);
		return ;
	}
	if (m_slot[idx] == NULL)
		Libft::print_colored_string_endl("slot is already NULL.", magenta);
	m_slot[idx] = NULL;
}

void	Character::use(int idx, Character& target)
{
	if (target.m_slot[idx] == NULL)
	{
		std::cout << Libft::get_colored_string("NULL slot!! ", yellow)
			<< target.Character::getName() << ",s slot#" << idx << std::endl;
		return ;
	}
	target.m_slot[idx]->AMateria::use(target);	
}

void	Character::copySlot(const Character& src)
{
	for (int i = 0; i < 4; ++i)
	{
		if (src.m_slot[i] != NULL)
			m_slot[i] = src.m_slot[i]->AMateria::clone();
		else
			m_slot[i] = NULL;
	}
}

void	Character::clearSlot(void)//is correct? if have address with non-new, it's cause crash.
{
	delete [] m_slot;
	for (int i = 0; i < 4; ++i)
		m_slot[i] = NULL;
}
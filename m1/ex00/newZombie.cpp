#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie  *new_Zombie;

	new_Zombie = new (std::nothrow) Zombie;
	if (new_Zombie != NULL)
		new_Zombie->Zombie::set_name(name);
	else
		std::cout << name << ": allocation faild!" << std::endl;
	return (new_Zombie);
}
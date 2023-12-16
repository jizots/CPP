#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie  *new_Zombie;

	new_Zombie = new (std::nothrow) Zombie;
	if (new_Zombie == NULL)
		std::cout << name << ": allocation faild!" << std::endl;
	else
		new_Zombie->Zombie::set_name(name);
	return (new_Zombie);
}

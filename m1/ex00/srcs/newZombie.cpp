#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie  *_new;

	_new = new (std::nothrow) Zombie(name);
	if (_new == NULL)
		std::cout << name << ": allocation faild!" << std::endl;
	return (_new);
}

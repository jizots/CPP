#include "Zombie.hpp"

void	randomChump( std::string name )
{
	Zombie  *_new;

	_new = newZombie(name);
	if (_new != NULL)
    {
		_new->Zombie::announce();
		delete _new;
    }
}

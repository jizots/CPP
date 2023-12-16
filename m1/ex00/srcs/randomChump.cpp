#include "Zombie.hpp"

void	randomChump( std::string name )
{
    Zombie  *new_zomb;

    new_zomb = newZombie(name);
    new_zomb->Zombie::announce();

    delete new_zomb;
}
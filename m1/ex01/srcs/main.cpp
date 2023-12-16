#include "Zombie.hpp"
#include "libc.h"

int	main()
{
	int	num_zom = 5;
	Zombie *_start;

	_start = zombieHorde(num_zom, "new");
	for (int i = 0; i < num_zom; ++i)
		(*_start).Zombie::announce();
	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q Moar");
}
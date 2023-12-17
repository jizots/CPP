#include "Zombie.hpp"
#include "libc.h"

/*配列のallocationとメモリ解放を学ぶ課題*/
int	main()
{
	int	num_zom = 5;
	Zombie *_start;

	_start = zombieHorde(num_zom, "new");
	std::cout << "start -> address: " << &(_start[0]) << std::endl;
	for (int i = 0; i < num_zom; ++i)
	{
		std::cout << "index: " << i << ", ";
		(_start[i]).Zombie::announce();
	}
	delete [] _start;
	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q Moar");
}
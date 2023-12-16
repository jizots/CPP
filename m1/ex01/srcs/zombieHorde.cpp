#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie  *_newHorde;

	if (N <= 0)
	{
		std::cout << "Born!Born!Born!Born!Born!Born!Born!Born!Born!Born!Born!" << std::endl;
		return (NULL);
	}
	try
	{
		_newHorde = new Zombie[N];
		std::cout << "new -> start address: " << &(_newHorde[0]) << std::endl;
		for ()
	}
	catch(std::bad_alloc)
	{
		std::cout << "Memory allocation failed!" << std::endl;
		return (NULL);
	}
	return (_newHorde);
}

#include "Zombie.hpp"
#include "libc.h"

int	main()
{
	Zombie	foo;

	std::cout << "---using announs(void)---" << std::endl;
	foo.Zombie::set_name("Foo");
	foo.Zombie::announce();
	std::cout << std::endl;
/*************************************/
	Zombie* new_foo;

	std::cout << "---using newZombie(std::string name)---" << std::endl;
	new_foo =  newZombie("new_foo");
	new_foo->Zombie::announce();
	std::cout << std::endl;
	delete new_foo;
/*************************************/
	std::cout << "---using randomChump(std::string name)---" << std::endl;
	randomChump("foofoo");

	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q a.out");
}
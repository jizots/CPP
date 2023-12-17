#include "Zombie.hpp"
#include "libc.h"

/*allocationとメモリ解放を学ぶ課題。加えてコントストラクタとデストラクタの挙動もまなべる。*/
int	main()
{
/*************************************/
	Zombie	foo("foo");
	// Zombie	hoge1;

	std::cout << "---using default---" << std::endl;
	foo.Zombie::announce();
	std::cout << std::endl;
	std::cout << std::endl;
/*************************************/
	Zombie* new_foo;

	std::cout << "---using newZombie(std::string name)---" << std::endl;
	new_foo =  newZombie("new_foo");
	if (new_foo != NULL)
	{
		new_foo->Zombie::announce();
		std::cout << std::endl;
		delete new_foo;
	}
	std::cout << std::endl;
/*************************************/
	std::cout << "---using randomChump(std::string name)---" << std::endl;
	randomChump("foofoo");

	std::cout << std::endl;
	std::cout << std::endl;
	return (0);
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q BraiiiiiiinnnzzzZ");
}
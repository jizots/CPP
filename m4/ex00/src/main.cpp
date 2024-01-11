#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>
#include <new>

int main()
{
	const Animal* meta = new(std::nothrow) Animal();
	const Animal* j = new(std::nothrow) Dog();
	const Animal* i = new(std::nothrow) Cat();
	if (meta == NULL || j == NULL || i == NULL)
	{
		std::cout << "allocation failed." << std::endl;
		std::exit;
	}
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	return 0;
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q cpp04ex00");
}
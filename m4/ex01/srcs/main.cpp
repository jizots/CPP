#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Libft.hpp"

# define ARRAY_SIZE 4

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	std::cout << std::endl;
	std::cout << "*****************My test******************" << std::endl;
	Animal *array[ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; ++i)
	{
		if (i < (ARRAY_SIZE / 2))
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}

	for (int i = 0; i < ARRAY_SIZE; ++i)
		delete array[i];

	return 0;
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q cpp04ex01");
}
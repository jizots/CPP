#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Libft.hpp"

# define ARRAY_SIZE 4

int main()
{
	// const Animal* h = new Animal();//make error
	const Animal* dog = new(std::nothrow) Dog();
	const Animal* cat = new(std::nothrow) Cat();
	if (dog == NULL || cat == NULL)
	{
		std::cerr << "allocation failed." << std::endl;
		std::exit(EXIT_FAILURE);
	}

	std::cout << "m_type of Class Dog's: " << dog->getType() << " " << std::endl;
	std::cout << "m_type of Class Cat's: " << cat->getType() << " " << std::endl;
	std::cout << "Cat's sound: ";
	cat->makeSound();
	std::cout << "Dog's sound: ";
	dog->makeSound();

	
	delete dog;
	delete cat;

	std::cout << std::endl;
	return 0;
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q cpp04ex02");
}
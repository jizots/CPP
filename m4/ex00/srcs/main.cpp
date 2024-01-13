#include <iostream>
#include <new>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Libft.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new(std::nothrow) Animal();
	const Animal* j = new(std::nothrow) Dog();
	const Animal* i = new(std::nothrow) Cat();
	if (meta == NULL || j == NULL || i == NULL)
	{
		Libft::print_colored_string_endl("allocation failed.", red);
		std::exit(EXIT_FAILURE);
	}
	
	std::cout << "m_type of Class Animal's: " << meta->getType() << " " << std::endl;
	std::cout << "m_type of Class Dog's: " << j->getType() << " " << std::endl;
	std::cout << "m_type of Class Cat's: " << i->getType() << " " << std::endl;
	std::cout << "Cat's sound: ";
	i->makeSound(); //will output the cat sound!
	std::cout << "Dog's sound: ";
	j->makeSound();
	std::cout << "Animal's sound: ";
	meta->makeSound();

	std::cout << std::endl;
	std::cout << "*****************My test******************" << std::endl;
	Animal copied(*j);
	std::cout << "m_type of Class Animal's: " << copied.getType() << " " << std::endl;
	// Cat	popy(copied); // Error. Derived can't initialize by Base.
	copied = *i;
	std::cout << "m_type of Class Animal's: " << copied.getType() << " " << std::endl;

	const WrongAnimal* met = new(std::nothrow) WrongAnimal();
	const WrongAnimal* k = new(std::nothrow) WrongCat();
	if (met == NULL || k == NULL)
	{
		Libft::print_colored_string_endl("allocation failed.", red);
		std::exit(EXIT_FAILURE);
	}

	std::cout << "m_type of Class WrongAnimal's: " << met->getType() << " " << std::endl;
	std::cout << "m_type of Class WrongCat's: " << k->getType() << " " << std::endl;
	std::cout << "WrongCat's sound: ";
	k->makeSound(); //will output the cat sound!
	std::cout << "WrongAnimal's sound: ";
	met->makeSound();


	delete meta;
	delete j;
	delete i;
	delete met;
	delete k;
	return 0;
}

__attribute__((destructor))
static void destructor()
{
	system("leaks -q cpp04ex00");
}
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Libft.hpp"

int main() 
{
	std::cout << "-----Subject test-----" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);


	ICharacter* bob = new Character("bob"); 
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob; 
	delete me;
	delete src;
	std::cout << std::endl;

	std::cout << "-----My test (case using floor or invalid argument)-----" << std::endl;
	src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure()); //Too many materia

	me = new Character("me");
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(tmp);
	me->equip(NULL); //NULL
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	
	bob = new Character("bob"); 
	// bob->equip(tmp); // case crash. But it's can't avoid. So Class can't notice equiped by other character.
	tmp = src->createMateria(" ");
	me->equip(tmp); // Invalid type
	tmp = src->createMateria("ice");
	me->equip(tmp); // Full

	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	bob->use(0, *bob); //No materia
	bob->use(-1, *bob);	//Invalid index

	// Ice crash;
	// bob->equip(&crash); //cause crash. But it's can't avoid. So Class can't notice using new or not.
	// src->learnMateria(&crash);

	delete bob; 
	delete me; 
	delete src;
	AMateria::clearFloor();
	std::cout << std::endl;

	std::cout << "-----My test (case copy function)-----" << std::endl;
	MateriaSource *msrc = new MateriaSource();
	msrc->learnMateria(new Ice());
	msrc->learnMateria(new Cure());
	MateriaSource *src2 = new MateriaSource(*msrc);
	*src2 = *src2;
	me = new Character("copyme");
	tmp = src2->createMateria("ice");
	me->equip(tmp);
	me->use(0, *me);
	ICharacter *non_slot = new Character("non_slot");
	*non_slot = *me; // ICharacter has no slot. So it's not copy slot.
	non_slot->use(0, *non_slot);
	Character *from = new Character("from");
	tmp = src2->createMateria("cure");
	from->equip(tmp);
	from->use(0, *from);
	Character *to = new Character("to");
	*to = *from; // Character has slot. So it's copy slot.
	to->use(0, *to);

	delete msrc;
	delete me;
	delete non_slot;
	delete src2;
	delete from;
	delete to;

	return 0;
}

/*
	$> clang++ -W -Wall -Werror *.cpp
	$> ./a.out | cat -e
	* shoots an ice bolt at bob *$
	* heals bob's wounds *$
*/

__attribute__((destructor))
static void destructor()
{
	system("leaks -q cpp04ex03");
}
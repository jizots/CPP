#include <iostream>
#include "FragTrap.hpp"

int main( void )
{
	FragTrap	a("nop");
	a.attack("target");
	a.beRepaired(10);
	a.beRepaired(UINT32_MAX);
	a.takeDamage(5);
	a.takeDamage(10);
	a.highFivesGuys();
	FragTrap	b("#15");
	b = a;
	b.attack("sataharu");
	return 0;
}

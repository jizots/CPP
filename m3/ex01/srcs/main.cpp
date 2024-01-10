#include <iostream>
#include "ScavTrap.hpp"

int main( void )
{
	ScavTrap	a("nop");
	a.attack("target");
	a.beRepaired(10);
	a.beRepaired(UINT32_MAX);
	a.takeDamage(5);
	a.takeDamage(100);
	a.guardGata();
	ScavTrap	b("sataharu");
	b = a;
	b.attack("nop");
	return 0;
}


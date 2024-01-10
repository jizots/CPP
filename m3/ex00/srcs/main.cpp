#include <iostream>
#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap	a("nop");
	a.attack("target");
	a.beRepaired(10);
	a.beRepaired(UINT32_MAX);
	a.takeDamage(5);
	a.takeDamage(UINT32_MAX);
	ClapTrap b(a);
	b = a;
	b.attack("a");
	return 0;
}

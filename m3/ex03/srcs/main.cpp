#include <iostream>
#include "DiamondTrap.hpp"

int main( void )
{
	DiamondTrap	a("nop");
	a.attack("target");
	a.beRepaired(10);
	a.beRepaired(UINT32_MAX);
	a.takeDamage(5);
	a.takeDamage(100);
	a.whoAmI();
	DiamondTrap b("sataharu");
	b = a;
	b.attack("nop");
	return 0;
}

/* Expected result
 ClapTrap::name (parameter of the constructor + "_clap_name" suffix) 
• Hit points (FragTrap) -> 100
• Energy points (ScavTrap) -> 50
• Attack damage (FragTrap) -> 30
• attack() (Scavtrap)
*/

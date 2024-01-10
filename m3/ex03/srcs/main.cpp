#include <iostream>
#include "DiamondTrap.hpp"

int main( void )
{
	DiamondTrap	a("nop");
	// a.attack("target");
	a.ScavTrap::beRepaired(10);
	a.ScavTrap::beRepaired(UINT32_MAX);
	a.FragTrap::takeDamage(5);
	a.FragTrap::takeDamage(UINT32_MAX);
	a.whoAmI();
	return 0;
}

/* Expected result
Default constructor called
Copy constructor called
Copy assignment operator called // <-- This line may be missing depending on your implementation
getRawBits member function called
Default constructor called
Copy assignment operator called
getRawBits member function called
getRawBits member function called
0
getRawBits member function called
0
getRawBits member function called
0
Destructor called
Destructor called
Destructor called
*/

#include <iostream>
#include "FragTrap.hpp"

int main( void )
{
	FragTrap	a("nop");
	a.attack("target");
	a.beRepaired(10);
	a.beRepaired(UINT32_MAX);
	a.takeDamage(5);
	a.takeDamage(UINT32_MAX);
	a.highFivesGuys();
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

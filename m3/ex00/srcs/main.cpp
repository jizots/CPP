#include <iostream>
#include "ClapTrap.hpp"

int main( void )
{
	ClapTrap	a("1");
	a.attack("target");
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

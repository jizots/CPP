#include <iostream>
#include "Fixed.hpp"

int main( void )
{
	std::cout << "-----------My test-----------" << std::endl;
	Fixed c(-1);
	Fixed d(-1);
	std::cout << "d > c:" << (d > c) << std::endl;
	std::cout << "d < c:" << (d < c) << std::endl;
	std::cout << "d >= c:" << (d >= c) << std::endl;
	std::cout << "d <= c:" << (d <= c) << std::endl;
	std::cout << "d == c:" << (d == c) << std::endl;
	std::cout << "d != c:" << (d != c) << std::endl;
	std::cout << "d + c:" << (d + c) << std::endl;
	std::cout << "d + c + 0.5:" << (d + c + 0.5f) << std::endl;
	std::cout << "d - c:" << (d - c) << std::endl;
	std::cout << "d * c:" << (d * c) << std::endl;
	std::cout << "d / c:" << (d / c) << std::endl;


	std::cout << "-----------Subject test-----------" << std::endl;
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << std::endl;

	std::cout << "-----------My test-----------" << std::endl;
	std::cout << --a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << Fixed::min( const_cast<Fixed&>(a), b ) << std::endl;
	std::cout << Fixed::min( a, b ) << std::endl;
	std::cout << Fixed::max( const_cast<Fixed&>(a), b ) << std::endl;
	Fixed e(1.2f);
	std::cout << Fixed::max( a, e ) << std::endl;

	return 0;
}

/* Expected result
$> ./a.out
0
0.00390625
0.00390625
0.00390625
0.0078125
10.1016
10.1016
$>
*/

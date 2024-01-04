#include <iostream>
#include "Point.hpp"

int main( void )
{
	Point	a(0.0f, 0.0f);
	Point	b(10.0f, 0.0f);
	Point	c(0.0f, 10.0f);

	Point	point(0.0f, 0.0f);
	std::cout << bsp(a, b, c, point) << std::endl;
	Point	point1(3.0f, 4.0f);
	std::cout << bsp(a, b, c, point1) << std::endl;
	Point	point2(3.0f, -4.0f);
	std::cout << bsp(a, b, c, point2) << std::endl;
	Point	point3(6.0f, 6.0f);
	std::cout << bsp(a, b, c, point3) << std::endl;
	Point	point4(-3.0f, 4.0f);
	std::cout << bsp(a, b, c, point4) << std::endl;
	Point	point5(-3.0f, -4.0f);
	std::cout << bsp(a, b, c, point5) << std::endl;

	std::cout << "Point change" << std::endl;
	Point	a1(20.0f, 20.0f);
	Point	b1(-20.0f, 20.0f);
	Point	c1(-20.0f, -20.0f);
	std::cout << bsp(a1, b1, c1, point) << std::endl;
	std::cout << bsp(a1, b1, c1, point1) << std::endl;
	std::cout << bsp(a1, b1, c1, point2) << std::endl;
	std::cout << bsp(a1, b1, c1, point3) << std::endl;
	std::cout << bsp(a1, b1, c1, point4) << std::endl;
	std::cout << bsp(a1, b1, c1, point5) << std::endl;

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

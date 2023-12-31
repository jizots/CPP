#include "Fixed.hpp"

std::ostream& operator<<(std::ostream& os, const Fixed& rhs)
{
	os << rhs.Fixed::toFloat();
	return (os);
}

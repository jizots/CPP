#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(const Fixed& other)
{
	*this = other;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	if (8388607 < num)
	{
		std::cout << "Error: Overflow. Set below 8388607." << std::endl;
		exit(1);
	}
	else if (num < -8388608)
	{
		std::cout << "Error: Underflow. Set above -8388608." << std::endl;
		exit(1);
	}
	setRawBits(num * (1 << m_frac_bits));
}

/*0.00390625 ~ 0.99609375は'0.00390625'刻みの範囲で表現できる。*/
Fixed::Fixed(const float num)
{
	int				shift;
	unsigned int	exponent = m_frac_bits;

	shift = 1;
	while (exponent--)
		shift *= 2;
	setRawBits(static_cast<int>(roundf(num * shift)));
}

int	Fixed::getRawBits(void) const
{
	return (m_fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	m_fixed_point = raw;
}

Fixed::~Fixed(void)
{
}

float	Fixed::toFloat( void ) const
{
	float	ret;
	int		shift;
	unsigned int	exponent = m_frac_bits;

	ret = static_cast<float>(this->m_fixed_point);
	shift = 1;
	while (exponent--)
		shift *= 2;
	ret = ret / shift;
	return (ret);
}

int		Fixed::toInt( void ) const
{
	int				shift;
	unsigned int	exponent = m_frac_bits;

	shift = 1;
	while (exponent--)
		shift *= 2;
	return (roundf(m_fixed_point / shift));
}

/*----------Comparison Operator----------*/
Fixed& Fixed::operator=(const Fixed& rhs)
{
	setRawBits(rhs.m_fixed_point);
	return (*this);
}

bool	Fixed::operator>(const Fixed& rhs)
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed& rhs)
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed& rhs)
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed& rhs)
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed& rhs)
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed& rhs)
{
	return (this->getRawBits() != rhs.getRawBits());
}

/*----------Arithmetic Operator----------*/
float	Fixed::operator+(const Fixed& rhs)
{
	return (this->toFloat() + rhs.toFloat());
}

float	Fixed::operator-(const Fixed& rhs)
{
	return (this->toFloat() - rhs.toFloat());
}

float	Fixed::operator*(const Fixed& rhs)
{
	return (this->toFloat() * rhs.toFloat());
}

float	Fixed::operator/(const Fixed& rhs)
{
	return (this->toFloat() / rhs.toFloat());
}

/*----------Increment & Decrement----------*/
Fixed&	Fixed::operator++()
{
	setRawBits(++m_fixed_point);
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp = *this;
	this->setRawBits(++m_fixed_point);
	return (temp);
}

Fixed&	Fixed::operator--()
{
	setRawBits(--m_fixed_point);
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp = *this;
	this->setRawBits(--m_fixed_point);
	return (temp);
}

/*----------Min & Max----------*/
Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	std::cout << "Non-const Arg called" << std::endl;
	if (a <= b)
		return (a);
	return (b);
}

Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (const_cast<Fixed&>(a) <= b)
		return (const_cast<Fixed&>(a));
	return (const_cast<Fixed&>(b));
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	std::cout << "Non-const Arg called" << std::endl;
	if (a >= b)
		return (a);
	return (b);	
}

Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (const_cast<Fixed&>(a) >= b)
		return (const_cast<Fixed&>(a));
	return (const_cast<Fixed&>(b));
}


std::ostream& operator<<(std::ostream& os, const Fixed& rhs)
{
	os << rhs.Fixed::toFloat();
	return (os);
}

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
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
	std::cout << "Float constructor called" << std::endl;
	setRawBits(static_cast<int>(roundf(num * (1 << m_frac_bits))));
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(rhs.m_fixed_point);
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (m_fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	m_fixed_point = raw;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

float	Fixed::toFloat( void ) const
{
	float	ret;

	ret = static_cast<float>(this->m_fixed_point);
	ret = ret / (1 << m_frac_bits);
	return (ret);
}

int		Fixed::toInt( void ) const
{
	return (roundf(m_fixed_point / (1 << m_frac_bits)));
}

std::ostream& operator<<(std::ostream& os, const Fixed& rhs)
{
	os << rhs.Fixed::toFloat();
	return (os);
}

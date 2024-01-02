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
	int				shift;
	unsigned int	exponent = m_frac_bits;

	std::cout << "Float constructor called" << std::endl;
	shift = 1;
	while (exponent--)
		shift *= 2;
	setRawBits(static_cast<int>(roundf(num * shift)));
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

std::ostream& operator<<(std::ostream& os, const Fixed& rhs)
{
	os << rhs.Fixed::toFloat();
	return (os);
}

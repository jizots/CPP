#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(other.getRawBits());
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(num << m_frac_bits);
}

Fixed::Fixed(const float num)
{
	unsigned int	shift;
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
	setRawBits(rhs.getRawBits());
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
	float			ret;
	unsigned int	shift;
	unsigned int	exponent = m_frac_bits;

	ret = static_cast<float>(this->m_fixed_point);
	shift = 1;
	while (exponent--)
		shift *= 2;
	ret = static_cast<int>(roundf(m_fixed_point / shift));
	return (ret);
}

int		Fixed::toInt( void ) const
{
	return (m_fixed_point >> m_frac_bits);
}

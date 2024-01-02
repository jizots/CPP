#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

class Fixed
{
public:
	Fixed(void);
	Fixed(const Fixed& other);
	Fixed(const int num);
	Fixed(const float num);
	~Fixed(void);
	int				getRawBits(void) const;
	void			setRawBits(int const raw);
	float			toFloat( void ) const;
	int				toInt( void ) const;
	Fixed&			operator=(const Fixed& rhs);
	bool			operator>(const Fixed& rhs);
	bool			operator<(const Fixed& rhs);
	bool			operator>=(const Fixed& rhs);
	bool			operator<=(const Fixed& rhs);
	bool			operator==(const Fixed& rhs);
	bool			operator!=(const Fixed& rhs);
	float			operator+(const Fixed& rhs);
	float			operator-(const Fixed& rhs);
	float			operator*(const Fixed& rhs);
	float			operator/(const Fixed& rhs);
	Fixed&			operator++();
	Fixed			operator++(int);
	Fixed&			operator--();
	Fixed			operator--(int);
	static	Fixed&	min(Fixed& a, Fixed& b);
	static	Fixed&	min(const Fixed& a, const Fixed& b);
	static	Fixed&	max(Fixed& a, Fixed& b);
	static	Fixed&	max(const Fixed& a, const Fixed& b);

private:
	int					m_fixed_point;
	static const int	m_frac_bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& rhs);

#endif
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
	Fixed& operator=(const Fixed& rhs);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;

private:
	int					m_fixed_point;
	static const int	m_frac_bits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& rhs);

#endif
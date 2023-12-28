#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class Fixed
{
public:
	Fixed(void);
	Fixed(const Fixed& other);
	~Fixed(void);
	Fixed& operator=(const Fixed& rhs);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

private:
	int					m_fixed_point;
	static const int	m_frac_bits = 8;
};

#endif
#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
public:
	Point(void);
	Point(const float x, const float y);
	Point(const Point& other);
	Point&	operator=(const Point& rhs);
	const Fixed&	get_point_x() const;
	const Fixed&	get_point_y() const;

	~Point(void);

private:
	Fixed const	m_x;
	Fixed const	m_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif

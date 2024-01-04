#ifndef VECTOR2DFIXED_HPP
# define VECTOR2DFIXED_HPP

# include <math.h>
# include "Point.hpp"
class Vector2DFixed
{
public:
	float	get_radian(Point& const point2d);
	float	get_digree(Point& const point2d);
	float	get_magnitude(Point& const point2d);	
private:
	Point&	point;
};

#endif
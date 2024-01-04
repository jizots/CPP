#include "Vector2DFixed.hpp"

float	get_radian(Point& const point2d)
{
	return (
		atan2((point2d.Point::get_point_y()).Fixed::toFloat(),
				(point2d.Point::get_point_x()).Fixed::toFloat())
	);
}

float	get_digree(Point& const point2d)
{
	return (
		get_radian(point2d)
		* 180 / M_PI
	);
}

float	get_magnitude(Point& const point2d)
{
	return (
		sqrt(
			pow((point2d.Point::get_point_x()).Fixed::toFloat(), 2)
			+ pow((point2d.Point::get_point_y()).Fixed::toFloat(), 2)
		)
	);
}

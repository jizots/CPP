#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Point	ab(b.get_point_x().toFloat() - a.get_point_x().toFloat(),
				b.get_point_y().toFloat() - a.get_point_y().toFloat());
	Point	ap(point.get_point_x().toFloat() - a.get_point_x().toFloat(),
				point.get_point_y().toFloat() - a.get_point_y().toFloat());
	Point	bc(c.get_point_x().toFloat() - b.get_point_x().toFloat(),
				c.get_point_y().toFloat() - b.get_point_y().toFloat());
	Point	bp(point.get_point_x().toFloat() - b.get_point_x().toFloat(),
				point.get_point_y().toFloat() - b.get_point_y().toFloat());
	Point	ca(a.get_point_x().toFloat() - c.get_point_x().toFloat(),
				a.get_point_y().toFloat() - c.get_point_y().toFloat());
	Point	cp(point.get_point_x().toFloat() - c.get_point_x().toFloat(),
				point.get_point_y().toFloat() - c.get_point_y().toFloat());

	float	cross_ab_ap = ab.get_point_x().toFloat() * ap.get_point_y().toFloat()
					- ab.get_point_y().toFloat() * ap.get_point_x().toFloat();
	float	cross_bc_bp = bc.get_point_x().toFloat() * bp.get_point_y().toFloat()
					- bc.get_point_y().toFloat() * bp.get_point_x().toFloat();
	float	cross_ca_cp = ca.get_point_x().toFloat() * cp.get_point_y().toFloat()
					- ca.get_point_y().toFloat() * cp.get_point_x().toFloat();
	
	if (cross_ab_ap >= 0 && cross_bc_bp >= 0 && cross_ca_cp >= 0)
		return (true);
	else if (cross_ab_ap <= 0 && cross_bc_bp <= 0 && cross_ca_cp <= 0)
		return (true);
	return (false);
}

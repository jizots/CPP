# include "Point.hpp"

Point::Point(void):m_x(0), m_y(0)
{
}

Point::Point(const float x, const float y):m_x(x),m_y(y)
{
}

Point::Point(const Point& other):m_x(other.m_x), m_y(other.m_y)
{
	std::cout << "Copy constructor called" << std::endl;
}

Point&	Point::operator=(const Point& rhs)
{
	std::cout << "Error: Copy assingment can't use; '='" << std::endl;
	return (*this);
}

Point::~Point(void)
{
	std::cout << "Destructor called" << std::endl;
}


#include <iostream>
#include "Point.hpp"

Point::Point( void ): x(0), y(0) {
//	std::cout << "Default Point constructor called" << std::endl;
}

Point::Point( Fixed const x, Fixed const y ): x(x), y(y) {
//	std::cout << "Param Point constructor called" << std::endl;
}

Point::Point( Point const &point ): x(point.x), y(point.y) {
//	std::cout << "Point copy constructor called" << std::endl;
	*this = point;
}

Point	&Point::operator=( Point const &point ){
//	std::cout << "Point copy assignment operator called" << std::endl;
	(void) point;
	return *this;
}

Point::~Point( void ) {
//	std::cout << "Point destructor called" << std::endl;
}

Fixed const	Point::getX( void ) const {
	return this->x;
}

Fixed const Point::getY( void ) const {
	return this->y;
}

bool	Point::operator==( Point const &point ) const {
	return (this->getX() == point.getX()) && (this->getY() == point.getY());
}

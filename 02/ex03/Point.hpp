#ifndef __POINT_H__
# define __POINT_H__

# include "Fixed.hpp"

class	Point {
	private:
		Fixed const	x;
		Fixed const	y;

	public:
		Point( void );
		Point( Fixed const x, Fixed const y );
		Point( Point const &point );
		Point & operator = ( Point const &point);
		~Point( void );

		Fixed const	getX( void ) const;
		Fixed const	getY( void ) const;

		bool	operator==( Point const &point ) const;
};
#endif /*__POINT_H__*/

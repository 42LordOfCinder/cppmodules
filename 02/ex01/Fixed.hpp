#ifndef __FIXED_H__
# define __FIXED_H__

# include <ostream>

class	Fixed {
	private:
		int					value;
		static int const	fracBit = 8;
	public:
		Fixed( void );
		Fixed( const int param );
		Fixed( const float param );
		Fixed( const Fixed &fixed );
		Fixed & operator = ( const Fixed &fixed );
		~Fixed( void );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream &operator << ( std::ostream &out, Fixed const &fixed );

#endif /*__FIXED_H__*/

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

		bool	operator>( Fixed const &fixed ) const;
		bool	operator<( Fixed const &fixed ) const;
		bool	operator>=( Fixed const &fixed ) const;
		bool	operator<=( Fixed const &fixed ) const;
		bool	operator==( Fixed const &fixed ) const;
		bool	operator!=( Fixed const &fixed ) const;

		float	operator+( Fixed const &fixed ) const;
		float	operator-( Fixed const &fixed ) const;
		float	operator*( Fixed const &fixed ) const;
		float	operator/( Fixed const &fixed ) const;

		Fixed	operator++( void );
		Fixed	operator--( void );
		Fixed	operator++( int );
		Fixed	operator--( int );

		static Fixed		&min( Fixed &f1, Fixed &f2 );
		static Fixed const	&min( Fixed const &f1, Fixed const &f2);
		static Fixed		&max( Fixed &f1, Fixed &f2);
		static Fixed const	&max( Fixed const &f1, Fixed const &f2);
};

std::ostream &operator << ( std::ostream &out, Fixed const &fixed );

#endif /*__FIXED_H__*/

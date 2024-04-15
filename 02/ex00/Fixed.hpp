#ifndef __FIXED_H__
# define __FIXED_H__

class	Fixed {
	private:
		int					value;
		static int const	fracBit = 8;
	public:
		Fixed( void );
		Fixed( const Fixed &fixed );
		Fixed & operator = ( const Fixed &fixed );
		~Fixed( void );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};
#endif /*__FIXED_H__*/

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed( void ): value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int param ): value(param << Fixed::fracBit) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float param ): value(roundf(param * (1 << Fixed::fracBit))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed( const Fixed &fixed ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed &Fixed::operator=( const Fixed &fixed ) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed) {
		this->setRawBits(fixed.getRawBits());
	}
	return *this;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits( void ) const {
	return this->value;
}

void	Fixed::setRawBits( int const raw ) {
	this->value = raw;
}

float	Fixed::toFloat( void ) const {
	return (float)this->value / (float)(1 << this->fracBit);
}

int	Fixed::toInt( void ) const {
	return this->value >> this->fracBit;
}

std::ostream &operator << ( std::ostream &out, Fixed const &fixed) {
	out << fixed.toFloat();
	return out;
}

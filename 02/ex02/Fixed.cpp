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

bool	Fixed::operator>( Fixed const &fixed ) const {
	return this->toFloat() > fixed.toFloat();
}

bool	Fixed::operator<( Fixed const &fixed ) const {
	return this->toFloat() < fixed.toFloat();
}

bool	Fixed::operator>=( Fixed const &fixed ) const {
	return this->toFloat() >= fixed.toFloat();
}

bool	Fixed::operator<=( Fixed const &fixed ) const {
	return this->toFloat() <= fixed.toFloat();
}

bool	Fixed::operator==( Fixed const &fixed ) const {
	return this->toFloat() == fixed.toFloat();
}

bool	Fixed::operator!=( Fixed const &fixed ) const {
	return this->toFloat() != fixed.toFloat();
}

float	Fixed::operator+( Fixed const &fixed ) const {
	return this->toFloat() + fixed.toFloat();
}

float	Fixed::operator-( Fixed const &fixed ) const {
	return this->toFloat() - fixed.toFloat();
}

float	Fixed::operator*( Fixed const &fixed ) const {
	return this->toFloat() * fixed.toFloat();
}

float	Fixed::operator/( Fixed const &fixed ) const {
	return this->toFloat() / fixed.toFloat();
}

Fixed	Fixed::operator++( void ) {
	this->value++;
	return *this;
}

Fixed	Fixed::operator--( void ) {
	this->value--;
	return *this;
}

Fixed	Fixed::operator++( int ) {
	Fixed	tmp(*this);
	this->value++;
	return tmp;
}

Fixed	Fixed::operator--( int ) {
	Fixed	tmp(*this);
	this->value--;
	return tmp;
}

Fixed	&Fixed::min( Fixed &f1, Fixed &f2 ) {
	if (f1 <= f2)
		return f1;
	else
		return f2;
}

Fixed const	&Fixed::min( Fixed const &f1, Fixed const &f2 ) {
	if (f1 <= f2)
		return f1;
	else
		return f2;
}

Fixed	&Fixed::max( Fixed &f1, Fixed &f2 ) {
	if (f1 >= f2)
		return f1;
	else
		return f2;
}

Fixed const	&Fixed::max( Fixed const &f1, Fixed const &f2 ) {
	if (f1 >= f2)
		return f1;
	else
		return f2;
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

#include "ScalarConverter.hpp"
#include <climits>
#include <stdlib.h>
#include <iostream>

ScalarConverter::ScalarConverter(void) {};

ScalarConverter::ScalarConverter(ScalarConverter &sc) {(void) sc;};

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &sc) {(void) sc; return *this;};

ScalarConverter::~ScalarConverter(void) {};

bool	isChar(std::string literal) {
	if (literal.empty())
		return false;
	if (literal.length() != 1)
		return false;
	if (isdigit(literal[0]))
		return false;
	return true;
}

void	convChar(std::string literal) {
	char	c = static_cast<char>(literal[0]);
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

bool	isInt(std::string literal) {
	if (literal.empty())
		return false;
	int	i = 0;
	if (literal[i] == '-')
		i++;
	for (; i < static_cast<int>(literal.length()); i++)
		if (!isdigit(literal[i]))
			return false;
	return true;
}

void	convInt(std::string literal) {
	long	l = std::atol(literal.c_str());

	std::cout << "char: ";
	if (l < 0 || l > 127)
		std::cout << "impossible" << std::endl;
	else if (isprint(l))
		std::cout << "'" << static_cast<char>(l) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if (l < INT_MIN || l > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(l) << std::endl;
	std::cout << "float: " << static_cast<float>(l) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(l) << ".0" << std::endl;
}

bool	isFloat(std::string literal) {
	if (literal.empty())
		return false;
	int	i = 0;
	if (literal[i] == '-')
		i++;
	bool	dot = false;
	for (; i < static_cast<int>(literal.length() - 1); i++) {
		if (!isdigit(literal[i])) {
			if (literal[i] == '.' && !dot && i != static_cast<int>(literal.length()) - 2)
				dot = true;
			else
				return false;
		}
	}
	if (literal[i] != 'f')
		return false;
	return dot;
}

void	convFloat(std::string literal) {
	float	f = std::atof(literal.c_str());
	bool	full = (f - static_cast<int>(f)) > 0;

	std::cout << "char: ";
	if (f < 0 || f > 127)
		std::cout << "impossible" << std::endl;
	else if (isprint(f))
		std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if (static_cast<long>(f) < INT_MIN || static_cast<long>(f) > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << (full ? "f" : ".0f") << std::endl;
	std::cout << "double: " << static_cast<double>(f) << (full ? "" : ".0") << std::endl;
}

bool	isDouble(std::string literal) {
	if (literal.empty())
		return false;
	int	i = 0;
	if (literal[i] == '-')
		i++;
	bool	dot = false;
	for (; i < static_cast<int>(literal.length()); i++) {
		if (!isdigit(literal[i])) {
			if (literal[i] == '.' && !dot && i != static_cast<int>(literal.length()) - 1)
				dot = true;
			else
				return false;
		}
	}
	return dot;
}

void	convDouble(std::string literal) {
	float	d = static_cast<double>(std::atof(literal.c_str()));
	bool	full = (d - static_cast<int>(d)) > 0;

	std::cout << "char: ";
	if (d < 0 || d > 127)
		std::cout << "impossible" << std::endl;
	else if (isprint(d))
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
	std::cout << "int: ";
	if (static_cast<long>(d) < INT_MIN || static_cast<long>(d) > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<double>(d) << (full ? "f" : ".0f") << std::endl;
	std::cout << "double: " << d << (full ? "" : ".0") << std::endl;
}

bool	isPseudo(std::string literal) {
	return (literal == "nan" || literal == "nanf" || literal == "+inf" || literal == "+inff"
		|| literal == "-inf" || literal == "-inff");
}

void	convPseudo(std::string literal) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (literal == "nan" || literal == "nanf")
	{
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "-inf" || literal == "-inff")
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}	
}

void	ScalarConverter::convert(std::string literal) {
	if (isChar(literal))
		convChar(literal);
	else if (isInt(literal))
		convInt(literal);
	else if (isFloat(literal))
		convFloat(literal);
	else if (isDouble(literal))
		convDouble(literal);
	else if (isPseudo(literal))
		convPseudo(literal);
	else
		std::cerr << "invalid input" << std::endl;
}

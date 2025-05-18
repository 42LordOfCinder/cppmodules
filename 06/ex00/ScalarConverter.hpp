#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class	ScalarConverter {
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter &sc);
	public:
		ScalarConverter	&operator=(ScalarConverter const &sc);
		~ScalarConverter(void);

		static void	convert(std::string literal);
};

#endif

#include <string>
#include <iostream>

int	main(void) {
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Adress of the string variable: " << &str << std::endl;
	std::cout << "Adress held by the pointer: " << stringPTR << std::endl;
	std::cout << "Adress held by the reference: " << &stringREF << std::endl;

	std::cout << "Value of the string variable: " << str << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;
	return 0;
}

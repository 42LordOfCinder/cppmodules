#include <iostream>
#include "RPN.hpp"

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	for (size_t i = 0; argv[1][i]; i++) {
		char	c = argv[1][i];
		if (!std::isspace(c) && !std::isdigit(c) && c != '+'
			&& c != '-' && c != '*' && c != '/') {
			std::cout << "Error" << std::endl;
			return 1;
		}
	}
	RPN	rpn;
	if (!rpn.solve(argv[1])) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return	0;
}

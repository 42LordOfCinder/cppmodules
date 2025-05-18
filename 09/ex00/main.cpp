#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int	main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: expected one argument" << std::endl;
		return 1;
	}
	BitcoinExchange	b;
	if (!b.loadData() || !b.loadInput(argv[1])) {
		return 1;
	}
	b.process();
	return 0;
}

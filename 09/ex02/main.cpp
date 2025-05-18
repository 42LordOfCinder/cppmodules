#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>

int	main(int argc, char **argv) {
	PmergeMe	pmm;
	
	if (argc < 2 || !pmm.parse(argv + 1)) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	clock_t	start = clock();
	pmm.getDeq();
	pmm.sortDeq(1);
	clock_t	end = clock();
	double	durationDeq = double(end - start) / CLOCKS_PER_SEC * 1000000;
	start = clock();
	pmm.getVec();
	pmm.sortVec(1);
	end = clock();
	double	durationVec = double(end - start) / CLOCKS_PER_SEC * 1000000;
	pmm.print();
	std::cout << "Time to process a range of " << pmm.getSize() << " elements with std::vector: " << durationVec << "us" << std::endl;
	std::cout << "Time to process a range of " << pmm.getSize() << " elements with std::deque: " << durationDeq << "us" << std::endl;
	return 0;
}

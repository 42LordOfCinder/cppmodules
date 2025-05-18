#include "iter.hpp"
#include <iostream>

int	main(void) {
	int		intArr[8] = {2, 4, 6, 8, 9, 20, 40, 56};
	char	charArr[4] = {'a', 'b', 'c', 'd'};
	::iter(intArr, 8, ::printPlusOne);
	::iter(charArr, 4, ::printPlusOne);
}

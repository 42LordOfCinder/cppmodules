#include "Serializer.hpp"
#include <iostream>

int	main(void) {
	Data	*d = new Data;
	d->var1 = 69;
	d->var2 = "nice";
	std::cout << "Before:" << std::endl << "var1: " << d->var1 << std::endl;
	std::cout << "var2: " << d->var2 << std::endl << "ptr: " << d << std::endl << std::endl;
	std::cout << "Serialization..." << std::endl;
	uintptr_t	i = Serializer::serialize(d);
	std::cout << "uintptr_t: " << i << std::endl;
	std::cout << "Deserialization..." << std::endl << std::endl;
	Data	*d1 = Serializer::deserialize(i);
	std::cout << "After:" << std::endl << "var1: " << d1->var1 << std::endl;
	std::cout << "var2: " << d1->var2 << std::endl << "ptr: " << d1 << std::endl;
	delete d;
	return 0;
}

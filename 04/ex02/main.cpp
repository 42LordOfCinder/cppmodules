#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main( void ) {
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	const Animal	*arr[100];
	for ( int i = 0; i < 100; i++ ) {
		if (i % 2)
			arr[i] = new Dog();
		else
			arr[i] = new Cat();
	}

	for ( int i = 0; i < 100; i++ )
		delete arr[i];

	Dog	rhinoceros;
	Dog rhinoceros2(rhinoceros);

	std::cout << rhinoceros.getBrain() << std::endl;
	std::cout << rhinoceros2.getBrain() << std::endl;

	return 0;
}

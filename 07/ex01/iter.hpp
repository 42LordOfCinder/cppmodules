#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T>
void	printPlusOne(T c) {
	std::cout << c + 1 << std::endl;
}

template<typename T>
void	iter(T *arr, int size, void(*f) (T &)) {
	if (!arr || !f)
		return ;
	for (int i = 0; i < size; i++)
		f(arr[i]);
}

#endif

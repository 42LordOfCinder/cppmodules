#ifndef ARRAY_HPP
# define ARRAY_HPP

template<class T>
class	Array {
	private:
		T				*_arr;
		unsigned int	_size;
	public:
		Array(void);
		Array(unsigned int size);
		Array(Array<T> const &ar);
		Array	&operator=(Array<T> const &ar);
		~Array(void);
		T	&operator[](unsigned int i);
		unsigned int	size(void) const;
		class	InvalidIndexException : public std::exception {
			public:
				virtual const char	*what() const throw();
		};
};

template<class T>
Array<T>::Array(void): _size(0) {
	this->_arr = new T[0];
}

template<class T>
Array<T>::Array(unsigned int size): _size(size) {
	T	*base = new T();
	this->_arr = new T[size];
	for (unsigned int i = 0; i < size; i++)
		this->_arr[i] = *base;
	delete base;
}

template<class T>
Array<T>::Array(Array const &ar) {
	this->_arr = NULL;
	*this = ar;
}

template<class T>
Array<T>::~Array(void) {
	delete[] this->_arr;
}

template<class T>
Array<T>	&Array<T>::operator=(Array<T> const &ar) {
	if (this->_arr)
		delete[] this->_arr;
	this->_size = ar.size();
	this->_arr = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_arr[i] = ar._arr[i];
	return *this;
}

template <class T>
T	&Array<T>::operator[](unsigned int i) {
	if (i >= this->_size)
		throw Array<T>::InvalidIndexException();
	return this->_arr[i];
}

template <class T>
unsigned int	Array<T>::size() const {
	return (this->_size);
}

template <class T>
const char	*Array<T>::InvalidIndexException::what() const throw() {
	return "index out of bonds";
}

#endif

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

class	NotFoundException : public std::exception {
	public:
		virtual const char	*what() const throw() {
			return ("not found");
		}
};

template<typename T>
typename T::iterator	easyfind(T &c, int i) {
	typename T::iterator	it = std::find(c.begin(), c.end(), i);
	if (it == c.end())
		throw NotFoundException();
	return (it);
}

#endif

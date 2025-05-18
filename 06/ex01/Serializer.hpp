#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <stdint.h>

class Serializer {
	private:
		Serializer(void);
		Serializer(Serializer &sz);
	public:
		Serializer	&operator=(Serializer const &sz);
		~Serializer(void);
		static uintptr_t	serialize(Data* ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif

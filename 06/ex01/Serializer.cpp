#include "Serializer.hpp"

Serializer::Serializer(void) {};

Serializer::Serializer(Serializer &sz) {(void) sz;};

Serializer	&Serializer::operator=(Serializer const &sz) {(void) sz; return *this;};

Serializer::~Serializer(void) {};

uintptr_t	Serializer::serialize(Data *ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data	*Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data *>(raw);
}

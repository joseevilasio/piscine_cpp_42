#include "Serializer.hpp"
#include "Data.hpp"

Serializer::Serializer(void) {}

Serializer&	Serializer::operator=(const Serializer& rhs)
{
	return (*this);
}

Serializer::Serializer(const Serializer& rhs) {*this=rhs;}

Serializer::~Serializer(void) {}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
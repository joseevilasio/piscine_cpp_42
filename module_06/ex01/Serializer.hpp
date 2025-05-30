#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

struct  Data;

class Serializer
{
	private:
		Serializer(void);
		Serializer&	operator=(const Serializer& rhs);
		Serializer(const Serializer& rhs);
		~Serializer(void);

	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif //SERIALIZER_HPP
#include "Serializer.hpp"
#include "Data.hpp"

int	main(void)
{
	Data nbr(42);
	Data* nbr_ptr = &nbr;

	std::cout << "[DATA] value: " << nbr._value << std::endl;
	std::cout << "[DATA] memory_address: " << nbr_ptr << std::endl;

	uintptr_t nbr_serialized = Serializer::serialize(nbr_ptr);
	Data* nbr_deserialized = Serializer::deserialize(nbr_serialized);

	std::cout << "[DATA - Serialized] uintptr_t: " << nbr_serialized << std::endl;
	std::cout << "[DATA - Deserialized]: memory_address: " << nbr_deserialized << std::endl;
	std::cout << "[DATA - Deserialized]: value: " << nbr_deserialized->_value << std::endl;

	if (nbr_deserialized == nbr_ptr)
		std::cout << "nbr_deserialized == nbr_ptr\n";
	else
		std::cout << "nbr_deserialized != nbr_ptr\n";

	return (0);
}
#include "Serializer.hpp"
#include "Data.hpp"

int	main(void)
{
	Data form("Bob", 42);
	Data* form_ptr = &form;

	std::cout << "[DATA] name: " << form._name << std::endl;
	std::cout << "[DATA] age: " << form._age << std::endl;
	std::cout << "[DATA] memory_address: " << form_ptr << std::endl;

	uintptr_t form_serialized = Serializer::serialize(form_ptr);
	Data* form_deserialized = Serializer::deserialize(form_serialized);

	std::cout << "[DATA - Serialized] uintptr_t: " << form_serialized << std::endl;
	std::cout << "[DATA - Deserialized]: memory_address: " << form_deserialized << std::endl;

	std::cout << "[DATA - Deserialized]: name: " << form_deserialized->_name << std::endl;
	std::cout << "[DATA - Deserialized]: age: " << form_deserialized->_age << std::endl;

	if (form_deserialized == form_ptr)
		std::cout << "form_deserialized == form_ptr\n";
	else
		std::cout << "form_deserialized != form_ptr\n";

	return (0);
}
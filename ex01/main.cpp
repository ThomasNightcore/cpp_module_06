#include "Serializer.hpp"
#include <iostream>
#include "stdint.h"

int main(void)
{
	Data data = {.age = 99, .name = "Grandma"};
	std::cout << "elements of first Data structure: .name = \'" << data.name << "\'"
			  << ", .age = \'" << data.age << "\'" << std::endl;
	std::cout << "Address: " << &data << std::endl;

	std::cout << " * serializing..." << std::endl;
	uintptr_t ptr = Serializer::serialize(&data);
	std::cout << "Serialized address: " << ptr << std::endl;

	std::cout << " * deserializing..." << std::endl;
	Data* deserialized_data = Serializer::deserialize(ptr);
	std::cout << "Deserialized address: " << ptr << std::endl;
	std::cout << "Deserialized data elements: \'" << deserialized_data->name << "\'"
			  << ", .age = \'" << deserialized_data->age << "\'" << std::endl;

	return 0;
}
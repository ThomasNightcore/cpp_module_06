#ifndef __SERIALIZER_HPP__
# define __SERIALIZER_HPP__

#include "stdint.h"

typedef struct {
	int age;
	const char* name;
} Data;

class Serializer {
public:
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);

private:
	Serializer(void);
	Serializer(const Serializer& other);
	~Serializer(void);
	Serializer operator=(const Serializer& other);
};

#endif

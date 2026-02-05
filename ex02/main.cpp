
#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

static Base* generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:
			std::cout << "generated A" << std::endl;
			return new A();
		case 1:
			std::cout << "generated B" << std::endl;
			return new B();
		case 2:
			std::cout << "generated C" << std::endl;
			return new C();
		default:
			std::cout << "There was an error generating a random Base member..." << std::endl;
			return NULL;
	}
}

static void indetify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	if (a != NULL)
	{
		std::cout << p << " identifed as A" << std::endl;
		return;
	}
	B* b = dynamic_cast<B*>(p);
	if (b != NULL)
	{
		std::cout << p << " identifed as B" << std::endl;
		return;
	}
	C* c = dynamic_cast<C*>(p);
	if (c != NULL)
	{
		std::cout << p << " identifed as C" << std::endl;
		return;
	}

	std::cout << "Error: could not identify a subtype of " << p << std::endl;
}

static void indetify(Base& p)
{
	try 
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "identifed as C" << std::endl;
		return;
	} 
	catch (...) { }
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "identifed as B" << std::endl;
		return;
	} 
	catch (...) { }
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "identifed as C" << std::endl;
		return;
	} 
	catch (...) { }
	std::cout << "Error: could not identify a subtype for the given reference" << std::endl;
}

int main(void)
{
	// different seed every time
	std::srand(std::time(0)); 

	Base* one = generate();
	Base* two = generate();
	Base* three = generate();

	std::cout << "Testing with pointers..." << std::endl;
	indetify(one);
	indetify(two);
	indetify(three);


	std::cout << std::endl << "Testing now with reference..." << std::endl;
	std::cout << "Indentifying " << one << ": ";
	indetify(*one);
	std::cout << "Indentifying " << two << ": ";
	indetify(*two);
	std::cout << "Indentifying " << three << ": ";
	indetify(*three);


	std::cout << std::endl << "Testing with NULL..." << std::endl;
	indetify(NULL);

	delete one;
	delete two;
	delete three;
}

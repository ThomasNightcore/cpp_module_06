#include "ScalarConverter.hpp"
#include <iostream>

/*
#include <sstream>

static void test_int(void)
{
	return;
	std::cout << std::endl << " ============ INT Tests: ============ " << std::endl;
	ScalarConverter::convert("+1");
	ScalarConverter::convert("8");
	ScalarConverter::convert("+37");
	ScalarConverter::convert("-37");
	ScalarConverter::convert("-12453");
	ScalarConverter::convert("-12453999999999"); // Underflow
	ScalarConverter::convert("88888888888"); // Overflow
}

static void test_char(void)
{
	std::cout << std::endl << " ============ CHAR Tests: ============ " << std::endl;
	ScalarConverter::convert("a");
	ScalarConverter::convert("{");
	ScalarConverter::convert("1"); // will however be parsed as integer...
}

static void test_float(void)
{
	return;
	std::cout << std::endl << " ============ FLOAT Tests: ============ " << std::endl;
	ScalarConverter::convert("+1.012f");
	ScalarConverter::convert("-1.032f");
	ScalarConverter::convert("199999999999.032f"); // with int overflow
	ScalarConverter::convert("-25689325798.032f"); // with int underflow
	ScalarConverter::convert("9999999999999999999999999999999999999999999999999999999999999999.089f"); // Overflow
	ScalarConverter::convert("0.000000000000000000000000000000000000000000000000000000000000000000000001f"); // Underflow
}

static void test_double(void)
{
	return;
	std::cout << std::endl << " ============ DOUBLE Tests: ============ " << std::endl;
	ScalarConverter::convert("+1.0");
	ScalarConverter::convert("341.35132");
	ScalarConverter::convert("-1.0");
	ScalarConverter::convert("199999999999.032"); // with int overflow
	ScalarConverter::convert("-25689325798.032"); // with int underflow
	ScalarConverter::convert("9999999999999999999999999999999999999999999999999999999999999999.032"); // with float overflow
	ScalarConverter::convert("0.000000000000000000000000000000000000000000000000000000000000000000000001"); // with float underflow
	ScalarConverter::convert("99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999888888888888888889999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999.089"); // Overflow
	ScalarConverter::convert("0.000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001"); // Underflow
}

static void test_pseudo_literals(void)
{
	return;
	std::cout << std::endl << " ============ PSEUDO LITERALS Tests: ============ " << std::endl;
	ScalarConverter::convert("-inf");
	ScalarConverter::convert("+inf");
	ScalarConverter::convert("-inff");
	ScalarConverter::convert("+inff");
	ScalarConverter::convert("nan");
	ScalarConverter::convert("nanf");
}

static void test_errors(void)
{
	return;
	std::cout << std::endl << " ============ ERROR Tests: ============ " << std::endl;
	ScalarConverter::convert("102531fd");
	ScalarConverter::convert("10d2531");
	ScalarConverter::convert("99999d854.8848");
	ScalarConverter::convert("102.d");
	ScalarConverter::convert("a.1235f");
	ScalarConverter::convert("error");
}

static void run_tests(void)
{
	// INT
	test_int();

	// CHAR
	test_char();

	// FLOAT
	test_float();

	// DOUBLE
	test_double();

	// PSEUDO_LITERALS
	test_pseudo_literals();

	// ERRORS
	test_errors();
}
*/

int main(int argc, char **argv) 
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert [literal]" << std::endl;
		return 0;
	}

	ScalarConverter::convert(std::string(argv[1]));
	return 0;
}

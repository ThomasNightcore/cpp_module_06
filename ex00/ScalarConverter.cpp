
#include "ScalarConverter.hpp"
#include <cctype>
#include <string>
#include <iostream>

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter(void)
{
}

static void print(const std::string& type, const std::string& val)
{
    std::cout << type << ": " << val << std::endl;
}

static void printChar(double val)
{
    std::string res;
    if (val < 0 || val > 127)
    {
        char c = static_cast<char>(val);
        res = std::isprint(c) ? std::string(1, c) : "impossible";
    }
    else
        res = "impossible";
    print("double", res);
}

static void printInt(double val)
{
    std::string res;
    print("int", res);
}

static void printFloat(double val)
{
    std::string res;
    print("float", res);
}

static void printDouble(double val)
{
}

void ScalarConverter::convert(const std::string& str)
{
    double val;

    val = 0;

    printChar(val);
    printInt(val);
    printFloat(val);
    printDouble(val);
}

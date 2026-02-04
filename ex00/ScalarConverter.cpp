
#include "ScalarConverter.hpp"
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cerrno>
#include <iomanip>
#include <sstream>
#include <string>
#include <iostream>

std::string ScalarConverter::s_err_reason = "";
bool ScalarConverter::s_has_err = false;

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

/* ###################
 * #  Printing Util  #
 * ################### */

static void print(const std::string& type, const std::string& val)
{
    std::cout << type << ": " << val << std::endl;
}

static void print(char c)
{
    std::cout << "char: " << c << std::endl;
}

static void print(int i)
{
    std::cout << "int: " << i << std::endl;
}

static void print(float f)
{
    std::cout << "float: " << std::fixed << std::setprecision(1) << f << 'f' << std::endl;
}

static void print(double d)
{
    std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}


/* ####################
 * #  Printing Logic  #
 * #################### */


void ScalarConverter::printFromChar(char val)
{
    if (s_has_err)
        return;
    print(val);
    // if (!std::isdigit(val))
    // {
    //     print("int", "impossible");
    //     print("float", "impossible");
    //     print("double", "impossible");
    //     return;
    // }
    print(static_cast<int>(val));
    print(static_cast<float>(val));
    print(static_cast<double>(val));
}

void ScalarConverter::printFromInt(int val)
{
    if (s_has_err)
        return;
    // Char
    if (val < 0 || val > 127) 
        print("char", "impossible");
    else if (!std::isprint(val))
        print("char", "non displayable");
    else
        print(static_cast<char>(val));

    print(val);
    print(static_cast<float>(val));
    print(static_cast<double>(val));
}

void ScalarConverter::printFromFloat(float val)
{
    if (s_has_err)
        return;
    // Char
    if (val < 0 || val > 127) 
        print("char", "impossible");
    else if (!std::isprint(val))
        print("char", "non displayable");
    else
        print(static_cast<char>(val));
    // Int
    if (val > static_cast<float>(INT_MAX) || val < static_cast<float>(INT_MIN))
        print("int", "impossible");
    else
        print(static_cast<int>(val));

    print(val);
    print(static_cast<double>(val)); // Double
}

void ScalarConverter::printFromDouble(double val)
{
    if (s_has_err)
        return;
    // Char
    if (val < 0 || val > 127) 
        print("char", "impossible");
    else if (!std::isprint(val))
        print("char", "non displayable");
    else
        print(static_cast<char>(val));
    // Int
    if (val > static_cast<double>(INT_MAX) || val < static_cast<double>(INT_MIN))
        print("int", "impossible");
    else
        print(static_cast<int>(val));
    // Float
    if (val > static_cast<double>(FLT_MAX) || val < static_cast<double>(FLT_MIN))
        print("float", "impossible");
    else
        print(static_cast<float>(val));
    // Double
    print(val);
}

void ScalarConverter::printFromPseudoLiteral(const std::string& str)
{
    print("char", "impossible");
    print("int", "impossible");

    if (str == "+inf" || str == "-inf")
    {
        print("float", str + "f");
        print("double", str);
        return;
    }
    if (str == "+inff" || str == "-inff")
    {
        print("float", str);
        print("double", str.substr(0, 4));
        return;
    }
    print("float", "nanf");
    print("double", "nan");
}



template<typename T>
T ScalarConverter::convertToType(const std::string& str)
{
    T res;
    std::stringstream ss(str);
    ss >> res;

    if (ss.fail() || !ss.eof())
    {
        print("char", "impossible");
        print("int", "impossible");
        print("float", "impossible");
        print("double", "impossible");
        s_has_err = true;
        return 0;
    }
    return res;
}

ScalarConverter::e_type ScalarConverter::getType(const std::string& str)
{
    if (str == "+inf" || str == "-inf" ||
        str == "+inff" || str == "-inff" ||
        str == "nan" || str == "nanf")
        return PSEUDO_LITERAL;
    if (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]))
        return CHAR;
    unsigned long i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (std::isdigit(str[i]))
        i++;
    if (i == str.length())
        return INT;
    if (str[i++] != '.')
    {
        std::stringstream ss;
        ss << "Invalid char at input str pos " << (i - 1);
        s_err_reason = ss.str();
        return ERROR;
    }
    while (std::isdigit(str[i]))
        i++;
    if (i == str.length())
        return DOUBLE;
    if (str[i] == 'f' && i + 1 == str.length())
        return FLOAT;
    std::stringstream ss;
    ss << "Invalid char at input str pos " << (i - 1);
    s_err_reason = ss.str();
    return ERROR;
}

void ScalarConverter::convert(const std::string& str)
{
    s_has_err = false;
    s_err_reason = "";
    //std::cout << '\n' << "./convert " << str << std::endl;
    switch (getType(str)) {
        case CHAR:
            printFromChar(str[0]);
            break;
        case INT:
            printFromInt(convertToType<int>(str));
            break;
        case FLOAT:
            printFromFloat(convertToType<float>(str.substr(0, str.length() - 1)));
            break;
        case DOUBLE:
            printFromDouble(convertToType<double>(str));
            break;
        case PSEUDO_LITERAL:
            printFromPseudoLiteral(str);
            break;
        case ERROR:
            std::cout << "Error, could not parse the input \"" << str 
                      << "\" because: " << s_err_reason << std::endl;
            return;
    }
}

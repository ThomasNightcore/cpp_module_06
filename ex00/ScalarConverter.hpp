#ifndef __SCALARCONVERTER_HPP__
# define __SCALARCONVERTER_HPP__

#include <string>

class ScalarConverter 
{
public:
	static void convert(const std::string& str);
private:
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter(void);
};

#endif

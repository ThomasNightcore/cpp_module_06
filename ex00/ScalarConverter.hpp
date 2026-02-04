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

	static std::string s_err_reason;
	static bool s_has_err;

	typedef enum {
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		PSEUDO_LITERAL,
		ERROR
	} e_type;

	template<typename T>
	static T convertToType(const std::string& str);
	static e_type getType(const std::string& str);
	static void printFromChar(char val);
	static void printFromInt(int val);
	static void printFromFloat(float val);
	static void printFromDouble(double val);
	static void printFromPseudoLiteral(const std::string& str);
};

#endif

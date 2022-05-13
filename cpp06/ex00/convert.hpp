#include <iostream>
#include <limits>
// #include <cstdlib>
// #include <cwctype>
// #include <typeinfo>
// #include <exception>

// #include "get_type.cpp"
// #include "conversions.cpp"
// #include "utils.cpp"

# define INFF std::numeric_limits<float>::infinity()
# define NEG_INFF - std::numeric_limits<float>::infinity()
# define INF std::numeric_limits<double>::infinity()
# define NEG_INF - std::numeric_limits<double>::infinity()

// get_type
int		get_type(std::string literal);

// conversions
void	char_conversion(int type, std::string literal);
void	int_conversion(int type, std::string literal);
void	float_conversion(int type, std::string literal);
void	double_conversion(int type, std::string literal);

// utils
int			error(std::string msg);
std::string	decimal_check(std::string literal);
std::string	decimal_useless_zero_remove(std::string literal);
std::string	integer_useless_zero_remove(std::string literal);
bool		int_overflow(std::string literal);
std::string get_int_part(std::string literal);
std::string	itoa(int const num);
std::string	itoaf(float const num);

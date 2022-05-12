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

// utils
int		error(std::string msg);
std::string	zero_check(std::string literal);
bool	int_overflow(std::string literal);

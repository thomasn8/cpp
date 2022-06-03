#include "convert.hpp"
#include <sstream>

int	error(std::string msg)
{
	std::cout << msg << std::endl;
	exit(-1);
}

std::string	decimal_append(std::string literal)
{
	int i = 0;
	int j = 0;
	int	decimal = 0;
	std::string first_deci = ".";

	while (literal[i])
	{
		if (literal[i] == '.' && iswdigit(literal[i + 1]))
		{
			decimal++;
			while (literal[i + 1 + j])
			{
				if (literal[i + 1 + j] != '0')
					first_deci += literal[i + 1 + j];
				j++;
			}
			first_deci += literal[i + 1];
		}
		i++;
	}
	if (decimal == 0 || first_deci == ".0")
		return ".0";
	if (decimal > 1)
		return "ERROR";
	return "";
}

std::string	decimal_useless_zero_remove(std::string literal)
{
	int len = literal.length();
	int i = len - 2;

	while (literal[i] == '0' && literal[i - 1] != '.')
	{
		literal.erase(i, 1);
		i--;
	}
	if (literal[literal.length() - 1] == 'f')
		literal.erase(literal.length() - 1, 1);
	return literal;
}

std::string	integer_useless_zero_remove(std::string literal)
{
	int i = 0;
	int j = 0;

	if (literal != "0" && literal != "-0")
	{
		if (literal[i] == '-')
			i++;
		while (literal[i + j] == '0')
			j++;
		if (literal[0] == '-')
			literal.erase(1, j);
		else
			literal.erase(0, j);
	}
	return literal;
}

bool	int_overflow(std::string literal)
{
	int		len;
	long	num;
	int		digit;
	char	digit2;

	if (literal == "0" || literal == "-0")	// for 0, -0, 000**, -000**, etc
		return false;
	literal = integer_useless_zero_remove(literal);
	len = literal.length();
	num = atoi(literal.c_str());
	if ((literal[0] == '-' && num > 0) ||
		(literal[0] != '-' && num < 0))		// for 2147483648 and multiples
		return true;
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		len--;
		digit = num % 10;
		digit2 = literal.c_str()[len];
		// std::cout << atoi(&digit2) << " vs " << digit << std::endl;
		if (atoi(&digit2) != digit)
			return true;
		num /= 10;
	}
	if (literal[0] == '-')
		len--;
	if (len > 0)							// for 8589934592 (= 2147483648 * 4)
		return true;
	return false;
}

std::string get_int_part(std::string literal)
{
	int	i = 0;

	while (literal[i] != '.')
		i++;
	literal.erase(literal.begin() + i, literal.end());
	return literal;
}

std::string	itoa(int const num)
{
	std::stringstream	out;
	out << num;
	return out.str();
}

std::string	itoaf(float const num)
{
	std::stringstream	out;
	out << num;
	return out.str();
}

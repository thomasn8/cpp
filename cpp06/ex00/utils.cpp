#include "convert.hpp"

int	error(std::string msg)
{
	std::cout << msg << std::endl;
	exit(-1);
}

std::string	zero_check(std::string literal)
{
	int i = 0;
	int j = 0;

	if (literal[i] == '-')
		i++;
	while (literal[i + j] == '0')
		j++;
	if (literal[0] == '-')
		literal.erase(1, j);
	else
		literal.erase(0, j);
	return literal;
}

bool	int_overflow(std::string literal)
{
	int		len;
	long	num;
	int		digit;
	char	digit2;

	if (literal == "0" || literal == "-0")				// for 0, -0, 000**, -000**, etc
		return false;
	literal = zero_check(literal);
	len = literal.length();
	num = atoi(literal.c_str());
	if ((literal[0] == '-' && num > 0) ||
		(literal[0] != '-' && num < 0))					// for 2147483648 and multiples
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
	if (len > 0)										// for 8589934592 (= 2147483648 * 4)
		return true;
	return false;
}

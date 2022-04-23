#include <iostream>
#include <cmath>

std::string	convertIntPart(int const num)
{
	int			n;
	int			r;
	std::string bits;

	n = (int)num;
	while (n)
	{
		r = n % 2;
		if (r == 1)
			bits += '1';
		else
			bits += '0';
		n /= 2;
	}
	if (bits.length() == 0)
		bits += '0';
	return bits;
}

int main()
{
	int n1 = 85;
	int n2 = 0;

	std::cout << convertIntPart(n1) << std::endl;
	std::cout << convertIntPart(n2) << std::endl;

	return 0;
}
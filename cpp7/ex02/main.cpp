#include "Array.hpp"

int main()
{
	Array<> empty_array;
	std::cout << empty_array << std::endl;
	// empty_array[0] = 1;											// Tentative d'accès à de la mémoire non-attribuée
	std::cout << std::endl;

	Array<int> int_array = Array<int>(3);
	std::cout << int_array << std::endl;
	std::cout << "int_array[0] = " << int_array[0] << std::endl;
	int_array[0] = 1;
	std::cout << "int_array[0] = " << int_array[0] << std::endl;
	std::cout << "int_array[1] = " << int_array[1] << std::endl;
	int_array[1] = 2;
	std::cout << "int_array[1] = " << int_array[1] << std::endl;
	std::cout << "int_array[2] = " << int_array[2] << std::endl;
	int_array[2] = 3;
	std::cout << "int_array[2] = " << int_array[2] << std::endl;
	std::cout << std::endl;
	
	Array<float> float_array = Array<float>(2);
	std::cout << float_array << std::endl;
	std::cout << "float_array[0] = " << float_array[0] << std::endl;
	float_array[0] = 1.111f;
	std::cout << "float_array[0] = " << float_array[0] << std::endl;
	std::cout << "float_array[1] = " << float_array[1] << std::endl;
	float_array[1] = 2.222;
	std::cout << "float_array[1] = " << float_array[1] << std::endl;
	std::cout << std::endl;

	Array<char> char_array = Array<char>(5);
	std::cout << char_array << std::endl;
	std::cout << "char_array[0] = " << char_array[0] << std::endl;
	char_array[0] = 'a';
	std::cout << "char_array[0] = " << char_array[0] << std::endl;
	std::cout << "char_array[3] = " << char_array[2] << std::endl;
	char_array[2] = 'c';
	std::cout << "char_array[3] = " << char_array[2] << std::endl;
	std::cout << "char_array[5] = " << char_array[5] << std::endl;	// Tentative d'accès à de la mémoire non-attribuée
	char_array[5] = 'f';
	std::cout << "char_array[5] = " << char_array[5] << std::endl;
	std::cout << std::endl;
	
	return 0;
}

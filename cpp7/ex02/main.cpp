#include "Array.hpp"

int main()
{
	std::cout << std::endl;
	Array<> empty_array;	// (fonctionne que si on précise un default type dans le template)
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

	Array<int> int_array_cpy(int_array);
	for (unsigned int i = 0; i < int_array_cpy.size(); i++)
		std::cout << "int_array_cpy[" << i << "] = " << int_array_cpy[i] << std::endl;
	Array<int> int_array_cpy_2 = int_array;
	for (unsigned int i = 0; i < int_array_cpy_2.size(); i++)
		std::cout << "int_array_cpy_2[" << i << "] = " << int_array_cpy_2[i] << std::endl;
	std::cout << std::endl;

	std::cout << "int_array[1] = " << int_array[1] << std::endl;
	int_array[1] = 10;
	std::cout << "Index 1 modified in original int_array: 2 -> 10 " << std::endl;
	std::cout << "int_array[1] = " << int_array[1] << std::endl;
	std::cout << "Shouldn't affect int_array_cpy: " << std::endl;
	std::cout << "int_array_cpy[1] = " << int_array_cpy[1] << std::endl;
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
	// std::cout << "char_array[5] = " << char_array[5] << std::endl;	// Tentative d'accès à de la mémoire non-attribuée
	// char_array[5] = 'f';												// Tentative d'accès à de la mémoire non-attribuée
	// std::cout << "char_array[5] = " << char_array[5] << std::endl;	// Tentative d'accès à de la mémoire non-attribuée
	std::cout << std::endl;
	
	return 0;
}

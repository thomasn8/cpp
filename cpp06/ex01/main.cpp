#include "Data.hpp"

/* 	
	Utilisez serialize() sur l’adresse de l’objet Data et 
	passez la valeur de retour obtenue à deserialize(). 

	Ensuite, assurez-vous que le retour de deserialize()
	est identique au pointeur d’origine.
*/

uintptr_t serialize(Data* ptr)
{
	
}

Data* deserialize(uintptr_t raw)
{
	
}

int main()
{
	Data data;

	uintptr_t ret1;
	Data *ret2;

	ret1 = serialize(&data);
	std::cout << "serialize(ptr): " << ret1 << std::endl;

	ret2 = deserialize(ret1);
	std::cout << "deserialize(ret1): " << ret2 << std::endl;

	return 0;
}

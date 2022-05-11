#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

// structure non-vide (comporte des variables membres)
struct Data
{

};

// Elle prend un pointeur et convertit celui-ci vers le type d’entier non-signé uintptr_t
uintptr_t serialize(Data* ptr);

// Elle prend un entier non-signé en paramètre et le convertit en pointeur sur Data
Data* deserialize(uintptr_t raw);

#endif

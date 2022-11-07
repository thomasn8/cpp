#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

/* 
	FONCTIONS POUR FAIRE LA DEMO
*/
template<typename T>
void	add_one(T tab)
{
	*tab = *tab + 1;
	std::cout << *tab << " ";
}

template<typename T>
void	display_value(T tab)
{
	std::cout << *tab << " ";
}

/* 
	FONCTION DEMANDÉE DANS LE SUJET 
*/
template<typename T>
void iter(T const & tab, size_t size, void (*my_function)(T const & tab))
{
	for (size_t i = 0; i < size; i++)
		my_function(&tab[i]);
}

#endif

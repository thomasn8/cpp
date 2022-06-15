#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void	add_one(T ptr)
{
	*ptr += 1;
}

template<typename T>
void iter(T tab, size_t size, void (*my_function)(T tab))
{
	for (size_t i = 0; i < size; i++)
		my_function(&tab[i]);
}

#endif

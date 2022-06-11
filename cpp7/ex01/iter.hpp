#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void	add_one(T ptr)
{
	*ptr += 1;
}

template<typename T>
void iter(T tab, size_t size, void (*ft)(T tab))
{
	for (size_t i = 0; i < size; i++)
		ft(&tab[i]);
}

#endif

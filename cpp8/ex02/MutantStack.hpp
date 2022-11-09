#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include "Iterator.hpp"

template <typename T = int>
class MutantStack : public std::stack<int>
{
	public:
	
		typedef T * pointer;
		typedef	iterator<T>	iterator;

		iterator begin() const 
		{
			// on prend l'adresse du dernier élément de la stack: &this->top()
			// et on lui soustrait la size+1 
			// pour tomber sur l'adresse du premier
			return iterator(const_cast<pointer>(&this->top()) - this->size() + 1);
		}

		iterator end() const 
		{
			// même chose sauf qu'on prend juste le dernier élément
			// et on créer un iterator sur l'adresse juste après (Returns an iterator referring to the past-the-end element)
			return iterator(const_cast<pointer>(&this->top()) + 1);
		}
};

#endif

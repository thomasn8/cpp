#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"
#include <iostream>
using namespace std;

/* 
Les piles sont implémentées en tant qu'adaptateurs de conteneur, qui sont des classes utilisant un objet encapsulé d'une classe de conteneur spécifique comme conteneur sous-jacent, fournissant un ensemble spécifique de fonctions membres pour accéder à ses éléments. Les éléments sont poussés/supprimés depuis l'arrière du conteneur spécifique, qui est connu comme le sommet de la pile.
*/

namespace ft
{
	template <class T, class Container = ft::vector<T> > 
	class stack
	{
		public :
		typedef T				value_type;
		typedef Container		container_type;
		typedef unsigned int	size_type;

		explicit stack(const container_type & ctnr = container_type()) : 
		_ctnr(ctnr), _ctnr_ptr(&_ctnr) {}
		~stack() {}

		bool empty() const { return _ctnr_ptr->empty(); }
		size_type size() const { return _ctnr_ptr->size(); }
		value_type & top() { return _ctnr_ptr->back(); }
		const value_type & top() const { return _ctnr_ptr->back(); }

		void push(const value_type & val) { _ctnr_ptr->push_back(val); }
		void pop() { _ctnr_ptr->pop_back(); }
		void swap(stack & x) { _ctnr_ptr->swap(*(x.getCntrPtr())); }

		container_type * getCntrPtr() const { return _ctnr_ptr; }

		private :
		container_type _ctnr;
		container_type * _ctnr_ptr;
	};

// NON MEMBER FUNCTION
	template <class T, class Container>
  	void swap (stack<T,Container> & x, stack<T,Container> & y) { x.swap(y); }

// RELATIONAL OPERATORS
	template <class T, class Container>
  	bool operator==(const stack<T,Container> & lhs, const stack<T,Container> & rhs)
	{
		return *(lhs.getCntrPtr()) == *(rhs.getCntrPtr());
	}
	template <class T, class Container>
	bool operator!=(const stack<T,Container> & lhs, const stack<T,Container> & rhs)
	{
		return *(lhs.getCntrPtr()) != *(rhs.getCntrPtr());
	}

	template <class T, class Container>
	bool operator<(const stack<T,Container> & lhs, const stack<T,Container> & rhs)
	{
		return *(lhs.getCntrPtr()) < *(rhs.getCntrPtr());
	}

	template <class T, class Container>
	bool operator<=(const stack<T,Container> & lhs, const stack<T,Container> & rhs)
	{
		return *(lhs.getCntrPtr()) <= *(rhs.getCntrPtr());
	}
	template <class T, class Container>
	bool operator>(const stack<T,Container> & lhs, const stack<T,Container> & rhs)
	{
		return *(lhs.getCntrPtr()) > *(rhs.getCntrPtr());
	}
	template <class T, class Container>
	bool operator>=(const stack<T,Container> & lhs, const stack<T,Container> & rhs)
	{
		return *(lhs.getCntrPtr()) >= *(rhs.getCntrPtr());
	}
}

#endif
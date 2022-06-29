#ifndef VECTOR_HPP
# define VECTOR_HPP

/* 
	Internally, vectors use a dynamically allocated array to store their elements. 
	This array may need to be reallocated in order to grow in size when new elements are inserted, 
	which implies allocating a new array and moving all elements to it. 
	This is a relatively expensive task in terms of processing time, and thus, 
	vectors do not reallocate each time an element is added to the container.
*/

#include "random_access_iterator_tag.hpp"
#include <iostream>
#include <memory>
using namespace std;

namespace ft
{

	template <typename T, typename Alloc = allocator<T> >
	class vector
	{
		public :
		// MEMBER TYPES
			typedef T 											value_type;
			typedef unsigned int 								size_type;
			typedef allocator<T> 								allocator_type;
			typedef typename allocator_type::reference 			reference;			// T &
			typedef typename allocator_type::const_reference 	const_reference;	// const T &
			typedef	typename allocator_type::pointer 			pointer;			// T *
			typedef	typename allocator_type::const_pointer 		const_pointer;		// const T *
			typedef int											difference_type;	// symbolise le résultat d'une soustraction de pointeurs

		// ITERATORS
			class iterator : public ft::random_access_iterator_tag<T>
			{	
				public : 
					iterator & operator=(iterator const & src) { this->_p = src.getP(); return *this; }
					iterator(const iterator & src) { this->_p = src.getP(); }
					iterator(T * p) { this->_p = p; }
					iterator() { this->_p = 0; }
					~iterator() {}
			};
			iterator begin() { iterator it(this->_first); return it; };
			iterator end() { iterator ite(++this->_last); return ite; };

		// CONSTRUCTEURS/DESTRUCTEUR
			vector<T>(iterator first, iterator last) 						// CONSTR #3
			{
				if (first != last)
				{
					iterator first_cpy = first;
					size_type n = 0;
					while (++first_cpy != last)
						++n;
					this->_n = n + 1;
					this->_pointer = this->_alloc.allocate(n + 2);
					this->_first = this->_pointer;
					while (first != last)
					{
						this->_alloc.construct(this->_pointer, *first);
						++first;
						this->_pointer++;
					}
					this->_pointer--;
					this->_last = this->_pointer;
				}
				else
				{
					this->_pointer = this->_alloc.allocate(1);
					this->_first = this->_pointer;
					this->_last = --this->_pointer;
					this->_n = 0;
				}
				cout << "(" << this << " - range) vector created" << endl;
			}
			vector<T>(size_type n, const value_type & val) : _n(n) 			// CONSTR #2
			{
				this->_pointer = this->_alloc.allocate(n + 1);					// créer un objet T pour le copier n fois, puis détruit l'objet de base
				this->_first = this->_pointer;
				for (size_type i = 0; i < n; i++)
				{
					this->_alloc.construct(this->_pointer, val+i);				// utilise l'objet créé pour Construire les instances par copie
					this->_pointer++;
				}
				this->_pointer--;
				this->_last = this->_pointer;
				cout << "(" << this << " - size) vector created" << endl;		// l'objet initial créé par allocate() est détruit en sortie de fonction
			}
			vector<T>() : _n(0)												// CONSTR #1
			{
				this->_pointer = this->_alloc.allocate(1);
				this->_first = this->_pointer;
				this->_last = --this->_pointer;
				cout << "(" << this << " - null) vector created" << endl;
			}
			virtual ~vector<T>() 											// DESTR
			{ 
				cout << "(" << this << " - default) vector destroyed" << endl; 
			}

		// ELEMENT ACCESS:
			reference front() { return *this->_first; }
			const_reference front() const { return *this->_first; }
			reference back() { return *this->_last; }
			const_reference back() const { return *this->_last; }

		// SURCHARGES
			reference operator*() const			{ return *this->_first; }
			pointer operator&() const			{ return &this->_first; }
			reference operator[](size_type index)	{ return this->_first[index]; }

		// ALLOCATOR
			allocator_type get_allocator() const { return this->_alloc; }

		private :
			allocator_type	_alloc;		// the default allocator
			size_type		_n;			// number of elements in container
			pointer			_first;		// first element
			pointer			_last;		// last element
			pointer			_pointer;	// random pointer for multi-usage
			// difference_type _difference_type() const { return sizeof(T); }

	}; // end of template ft::vector<T>

	// template <typename T>
	// ostream	& operator<<(ostream & o, vector<T> const & inst) { cout << &inst.front(); return o; }

} // end of namespace ft::

#endif

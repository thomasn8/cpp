#ifndef VECTOR_HPP
# define VECTOR_HPP

/* 
	Internally, vectors use a dynamically allocated array to store their elements. 
	This array may need to be reallocated in order to grow in size when new elements are inserted, 
	which implies allocating a new array and moving all elements to it. 
	This is a relatively expensive task in terms of processing time, and thus, 
	vectors do not reallocate each time an element is added to the container.
*/

#include "random_access_iterator.hpp"
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
			typedef T 											value_type;			// le type de donné inséré dans le container
			typedef unsigned int 								size_type;			// can represent any non-negative value of difference_type

			typedef allocator<T> 								allocator_type;		// l'allocateur par défault
			typedef typename allocator_type::reference 			reference;			// T & -> Reference to element
			typedef typename allocator_type::const_reference 	const_reference;	// const T & -> Reference to constant element
			typedef	typename allocator_type::pointer 			pointer;			// T * Pointer to element
			typedef	typename allocator_type::const_pointer 		const_pointer;		// const T * Pointer to constant element
			
			typedef int											difference_type;	// Type to express the result of subtracting one iterator from another

			// typedef a random access iterator to value_type	iterator;
			// typedef a random access iterator to const value_type const_iterator;
			// typedef reverse_iterator<iterator> 			reverse_iterator;
			// typedef reverse_iterator<const_iterator> 			const_reverse_iterator;

		// ITERATORS
			class iterator : public ft::random_access_iterator<T>
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
			vector<T>(iterator first, iterator last) // constr #3
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
			vector<T>(size_type n, const value_type & val) : _n(n) 	// constr #2
			{
				this->_pointer = this->_alloc.allocate(n + 1);				// créer un objet T pour le copier n fois, puis détruit l'objet de base
				this->_first = this->_pointer;
				for (size_type i = 0; i < n; i++)
				{
					this->_alloc.construct(this->_pointer, val+i);			// utilise l'objet créé pour Construire les instances par copie
					this->_pointer++;
				}
				this->_pointer--;
				this->_last = this->_pointer;
				cout << "(" << this << " - size) vector created" << endl;	// l'objet initial créé par allocate() est détruit en sortie de fonction
			}
			vector<T>() : _n(0)	// constr #1
			{
				this->_pointer = this->_alloc.allocate(1);
				this->_first = this->_pointer;
				this->_last = --this->_pointer;
				cout << "(" << this << " - null) vector created" << endl;
			}
			virtual ~vector<T>() { cout << "(" << this << " - default) vector destroyed" << endl; } // destr

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

/*	
	VECTORS

	Internally, vectors use a dynamically allocated array to store their elements. 
	This array may need to be reallocated in order to grow in size when new elements are inserted, 
	which implies allocating a new array and moving all elements to it. 
	This is a relatively expensive task in terms of processing time, and thus, 
	vectors do not reallocate each time an element is added to the container.
	
*/

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "random_access_iterator_tag.hpp"
#include <iostream>	// cout << 
#include <memory>	// allocator<T>

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
			typedef allocator<value_type> 						allocator_type;
			typedef typename allocator_type::reference 			reference;			// T &
			typedef typename allocator_type::const_reference 	const_reference;	// const T &
			typedef	typename allocator_type::pointer 			pointer;			// T *
			typedef	typename allocator_type::const_pointer 		const_pointer;		// const T *
			typedef int											difference_type;	// symbolise le résultat d'une soustraction de pointeurs

		// CONSTRUCTEURS/DESTRUCTEUR
			explicit vector(const allocator_type & alloc = allocator_type()) 		// CONSTR #1
			: _n(0)
			{
				this->_pointer = this->_alloc.allocate(1);
				this->_first = this->_pointer;
				this->_last = --this->_pointer;
				this->_alloc = alloc;
				cout << "(" << this << " - null) vector created" << endl;
			}

			explicit vector(size_type n, const value_type & val = value_type(), 	// CONSTR #2
				const allocator_type & alloc = allocator_type())
			: _n(n)
			{
				this->_pointer = this->_alloc.allocate(n + 1);
				this->_first = this->_pointer;
				for (size_type i = 0; i < n; i++)
				{
					this->_alloc.construct(this->_pointer, val+i);	// ENLEVER LE +1 (de val+1), car juste pour tester
					this->_pointer++;
				}
				this->_pointer--;
				this->_last = this->_pointer;
				this->_alloc = alloc;
				cout << "(" << this << " - fill) vector created" << endl;
			}
			
			// le typedef SFINAE (dans la classe iterator) force le choix de l'overload
			template <typename InputIterator>										// CONSTR #3
			vector(InputIterator first, InputIterator last, 
				const allocator_type & alloc = allocator_type(), 
				typename InputIterator::SFINAE_condition = 0)
			{
				this->_n = last - first;
				if (this->_n)
				{
					this->_pointer = this->_alloc.allocate(this->_n + 1);
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
				}
				this->_alloc = alloc;
				cout << "(" << this << " - range) vector created" << endl;
			}

			vector(const vector & x)												// CONSTR #4
			{
				vector::const_iterator first = x.begin();
				vector::const_iterator last = x.end();

				this->_n = x.size();
				this->_pointer = x.get_allocator().allocate(this->_n + 1);
				this->_first = this->_pointer;
				while (first != last)
				{
					x.get_allocator().construct(this->_pointer, *first);
					++first;
					cout << &this->_pointer[0] << " = " << *this->_pointer << endl;
					this->_pointer++;
				}
				this->_pointer--;
				this->_last = this->_pointer;
				this->_alloc = x.get_allocator();
				cout << "(" << this << " - copy) vector created" << endl;
			}

			virtual ~vector() 														// DESTR #1
			{
				// This destroys all container elements, and deallocates all the storage capacity allocated 
				// by the vector using its allocator.

				// => CHECKER SI LA MEMOIRE EST BIEN DESALLOUEE AVEC LES LEAKS
				
				cout << "(" << this << " - default) vector destroyed" << endl;
			}

		// ITERATORS
			class iterator : public ft::random_access_iterator_tag<T, char>
			{	
				public : 
					iterator & operator=(iterator const & src) { this->_p = src.getP(); return *this; }
					iterator(const iterator & src) { this->_p = src.getP(); }
					iterator(T * p) { this->_p = p; }
					iterator() { this->_p = 0; }
					virtual ~iterator() {}
			};
			iterator begin() { return iterator(this->_first); };
			iterator end() { return iterator(this->_last + 1); };

			// sécialisation grâce à un int pour utiliser la bonne instanciation du template random_access_iterator_tag
			class const_iterator : public ft::random_access_iterator_tag<T, int>
			{	
				public : 
					const_iterator & operator=(const_iterator const & src) { this->_p = src.getP(); return *this; }
					const_iterator(const const_iterator & src) { this->_p = src.getP(); }
					const_iterator(T * p) { this->_p = p; }
					const_iterator() { this->_p = 0; }
					~const_iterator() {}
			};
			const_iterator begin() const {const_iterator(this->_first); };
			const_iterator end() const { const_iterator(this->_last + 1); };

		// ELEMENT ACCESS:
			reference front() 								{ return *this->_first; }
			const_reference front() const 					{ return *this->_first; }
			reference back() 								{ return *this->_last; }
			const_reference back() const 					{ return *this->_last; }

		// CAPACITY
			size_type size() const 							{ return this->_n; }

		// ALLOCATOR
			allocator_type get_allocator() const { return this->_alloc; }

		// SURCHARGES
			reference operator*() const 					{ return *this->_first; }
			pointer operator&() const 						{ return &this->_first; }
			reference operator[](size_type index) const		{ return this->_first[index]; }

		private :
			Alloc			_alloc;		// the default allocator
			size_type		_n;			// number of elements in container
			pointer			_first;		// first element
			pointer			_last;		// last element
			pointer			_pointer;	// random pointer for multi-usage

	}; // end of template ft::vector<T>

} // end of namespace ft::

#endif

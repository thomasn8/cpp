#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>			// cout << 
#include <memory>			// allocator<T>
#include <stdexcept>		// exceptions
#include "iterators.hpp"
#include "pair.hpp"
#include "utils.hpp"

using namespace std;

#define REALLAOC_FACTOR 2

/* 

Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.
In a map, the key values are generally used to sort and uniquely identify the elements, while the mapped values store the content associated to this key. 
The types of key and mapped value may differ, and are grouped together in member type value_type, which is a pair type combining both:

	typedef pair<const Key, T> value_type;

Internally, the elements in a map are always sorted by its key following a specific strict weak ordering criterion 
indicated by its internal comparison object (of type Compare).

map containers are generally slower than unordered_map containers to access individual elements by their key, 
but they allow the direct iteration on subsets based on their order.

The mapped values in a map can be accessed directly by their corresponding key using the bracket operator ((operator[]).

Maps are typically implemented as binary search trees.

MEMORY MANAGEMENT :
https://stackoverflow.com/questions/11528911/how-is-a-stl-map-allocated-stack-or-heap
https://cs.stackexchange.com/questions/144045/how-c-and-alike-maps-are-actually-stored-in-memory

*/

namespace ft
{
	// template <class Key,										// map::key_type
    //        	class T,										// map::mapped_type
    //        	class Compare = less<Key>,						// map::key_compare
    //        	class Alloc = allocator<pair<const Key,T> >		// map::allocator_type
    //        	> class map;
	
	template < class Key, class T, class Compare = less<Key>, class Alloc = allocator< pair< const Key,T> > >
	class map
	{
		public:
		
	// MEMBER TYPES
		typedef	Key												key_type;
		typedef	T												mapped_type;
		typedef	ft::pair<const key_type, mapped_type>			value_type;
		typedef	Compare											key_compare;
		// typedef Nested function class to compare elements 	value_compare;
		typedef	Alloc											allocator_type;
		typedef	typename allocator_type::reference				reference;
		typedef	typename allocator_type::const_reference		const_reference;
		typedef	typename allocator_type::pointer				pointer;
		typedef	typename allocator_type::const_pointer			const_pointer;
		typedef	ft::bidirectional_iterator<value_type>			iterator;
		typedef	ft::bidirectional_iterator<const value_type>	const_iterator;
		typedef	ft::reverse_iterator<iterator>					reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef	int												difference_type;
		typedef	unsigned int									size_type;

	// CONSTRUCTORS
		explicit map(const key_compare & comp = key_compare(), 
		const allocator_type & alloc = allocator_type()) :
		_alloc(alloc), _comp(comp), _n(0), _first(NULL), _last(NULL) {}

		// template <class InputIterator>
		// map(InputIterator first, InputIterator last, 
		// const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type())
		// {
		// 	size_type n = _distance<InputIterator>(first, last);
		// 	if (n)
		// 	{
		// 		first = _alloc.allocate(n + 1);
		// 		_ptr = _first;
		// 		// while (first != last)
		// 		// 	_alloc.construct(_ptr++, *first++);
		// 		// _last = --_ptr;
		// 		// _n = n;
		// 		// _c = n;
		// 	}
		// }

		// // copy (3)
		// map(const map& x)
		// {

		// }

		~map() {}

		// 1. if k matches the key of an element in the container, the function returns a reference to its mapped value.
		// 2. if k does not match the key of any element in the container, the function inserts a new element 
		//    with that key and returns a reference to its mapped value.

		mapped_type & operator[](const key_type & k)
		{
			// return (*((this->insert(make_pair(k,mapped_type()))).first)).second;

			value_type new_pr = ft::make_pair(k, mapped_type());		// first['a']=10;
			// new_pr.second = ;										// COMMENT CHOPER LA VALEUR APRES LE = 
				
			pair<iterator,bool> check = insert(new_pr);

			iterator same_key = check.first;
			// value_type same = *same_key;
			
			return (*same_key).second;
			
			// if (same_key != NULL)
			// {
			// 	cout << "TEST: " << (*same_key).first << endl;
			// 	cout << "TEST: " << (*same_key).second << endl;
			// 	// cout << "TEST: " << same.first << endl;
			// 	// cout << "TEST: " << same.second << endl;
			// 	return (*same_key).second;
			// }

			// if (check.second == false)
			// 	return (*same_key).second;
			// return new_pr.second;
		}

		pair<iterator,bool> insert(const value_type & val)
		{
			iterator key_check = _check_keys(val.first);
			if (key_check != NULL)
				return pair<iterator,bool>(key_check, false);
			if (_n)
			{
				iterator it = this->begin();
				iterator ite = this->end();
				pointer f = _first;
				_first = _alloc.allocate(_n + 2);
				_ptr = _first;
				while (it != ite)
					_alloc.construct(_ptr++, *it++);
				_alloc.construct(_ptr, val);
				_last = _ptr;
				_alloc.deallocate(f, _n + 1);
			}
			else
			{
				_first = _alloc.allocate(2);
				_ptr = _first;
				_alloc.construct(_ptr, val);
				_last = _first;
			}
			_n++;
			return pair<iterator,bool>(key_check, true);
		}

		// iterator insert (iterator position, const value_type& val)
		// {

		// }

		// template <class InputIterator>
		// void insert (InputIterator first, InputIterator last)
		// {

		// }

		void details()
		{
			cout << endl << "----------------------- DETAILS ------------------------" << endl;
			cout << "Size = " << this->size() << " | Sizeof(value_type) = " << sizeof(value_type) << endl << endl;
			if (_n)
			{
				iterator it = this->begin();
				iterator ite = this->end();
				while (it != ite)
				{
					cout << "It  = " << &*it << " = " << (*it).first << " | " << (*it).second << endl;
					it++;
				}
				cout << "Ite = " << &*ite << endl;
			}
			else
				cout << "container is empty" << endl << endl;
			cout << "--------------------------------------------------------" << endl;
		}

	// ITERATORS
		iterator begin() 				{ return iterator(_first); }
		const_iterator begin() const 	{ return const_iterator(_first); }
		iterator end() 					{ return iterator(_last+1); }
		const_iterator end() const 		{ return const_iterator(_last+1); }

	// ACCESSORS
		size_type size() const 		{ return _n; }

		private:
		allocator_type	_alloc;
		key_compare		_comp;
		size_type		_n;
		pointer			_first;
		pointer			_last;
		pointer			_ptr;

		template <class InputIterator>
		size_type _distance(InputIterator first, InputIterator last) const
		{
			size_type n = 0;
			while (first != last)
			{
				first++;
				n++;
			}
			return n;
		}

		iterator _check_keys(key_type key)
		{
			iterator it = this->begin();
			iterator ite = this->end();
			if (_n)
			{
				while (it != ite)
				{
					if (key == (*it).first)
						return it;
					it++;
				}
			}
			return this->begin();
		}

	};
}

#endif
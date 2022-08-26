#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>			// cout << 
#include <memory>			// allocator<T>
#include <stdexcept>		// exceptions
#include "iterators.hpp"
#include "pair.hpp"
#include "utils.hpp"

using namespace std;

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
		_alloc(alloc), _comp(comp), _n(0), _c(0), _first(NULL), _last(NULL) {}

		// no known conversion from 'int' to
    	// 'const value_type' (aka 'const pair<const int, char>') for 2nd argument

		template <class InputIterator>
		map(InputIterator first, InputIterator last, 
		const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type())
		{
			size_type n = last - first;
			_ptr = _alloc.allocate(n);
		}

		// // copy (3)
		// map(const map& x)
		// {

		// }

		~map() {}

		private:
		allocator_type	_alloc;
		key_compare		_comp;			
		size_type		_n;
		size_type		_c;
		pointer			_first;
		pointer			_last;
		pointer			_ptr;

	};
}

#endif
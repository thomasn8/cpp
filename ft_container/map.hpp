#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>			// cout << 
#include <memory>			// allocator<T>
#include <stdexcept>		// exceptions
#include "iterators.hpp"
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

	};
}

#endif
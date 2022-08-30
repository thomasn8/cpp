#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
using namespace std;
#include <memory>
#include <stdexcept>
#include "iterators.hpp"
#include "pair.hpp"
#include "utils.hpp"

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
	template < class Key, class T, 
	class Compare = less<Key>, class Alloc = allocator< pair< const Key,T> > >
	class map
	{
		public:

		class value_compare;
		
	// MEMBER TYPES
		typedef	Key												key_type;
		typedef	T												mapped_type;
		typedef	ft::pair<const key_type, mapped_type>			value_type;
		typedef	Compare											key_compare;
		typedef map::value_compare								value_compare;
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

	// CONSTRUCTORS / DESTRUCTOR
		explicit map(const key_compare & comp = key_compare(), 
		const allocator_type & alloc = allocator_type()) :
		_alloc(alloc), _comp(comp), _n(0), _first(NULL), _last(NULL) {}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, 
		const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()) :
		_alloc(alloc), _comp(comp), _n(0), _first(NULL), _last(NULL)
		{
			size_type n = _distance<InputIterator>(first, last);
			if (n)
			{
				_first = _alloc.allocate(n + 1);
				_ptr = _first;
				while (first != last)
					_alloc.construct(_ptr++, *first++);
				_last = --_ptr;
				_n = n;
			}
		}

		map(const map & x) :
		_alloc(x.get_allocator()), _comp(x.key_comp()), _n(x.size()), _first(NULL), _last(NULL)
		{
			if (_n)
			{
				const_iterator it = x.begin();
				const_iterator ite = x.end();
				_first = _alloc.allocate(_n + 1);
				_ptr = _first;
				while (it != ite)
					_alloc.construct(_ptr++, *it++);
				_last = --_ptr;
			}
		}

		map & operator=(const map & x)
		{
			if (_n)
			{
				_ptr = _first;
				while (_first != _last)
					_alloc.destroy(_first++);
				_alloc.deallocate(_ptr, _n + 1);
				_n = 0;
				_first = NULL;
				_last = NULL;
			}
			if (x.size())
			{
				_comp = x.key_comp();
				_n = x.size();
				const_iterator it = x.begin();
				const_iterator ite = x.end();
				_first = _alloc.allocate(_n + 1);
				_ptr = _first;
				while (it != ite)
					_alloc.construct(_ptr++, *it++);
				_last = --_ptr;
			}
			return *this;
		}

		~map()
		{
			if (_n)
			{
				_ptr = _first;
				while (_first != _last)
					_alloc.destroy(_first++);
				_alloc.deallocate(_ptr, _n + 1);
			}
		}

		// ITERATORS
		iterator begin() 				{ return iterator(_first); }
		iterator end() 					{ if (_n) return iterator(_last+1); return (_last);}
		const_iterator begin() const 	{ return const_iterator(_first); }
		const_iterator end() const 		{ if (_n) return const_iterator(_last+1); return (_last);}

		// CAPACITY
		size_type size() const { return _n; }

		// ELEMENT ACCESS
		mapped_type & operator[](const key_type & k)
		{
			value_type new_pr = ft::make_pair(k, mapped_type());
			pair<iterator,bool> checked = insert(new_pr);
			return (*checked.first).second;
		}

		// MODIFIERS
		pair<iterator,bool> insert(const value_type & val)
		{
			iterator key_check = _check_keys(val.first);
			if (key_check != NULL)
				return pair<iterator,bool>(key_check, false);
			if (_n)
			{
				iterator it = begin();
				iterator ite = end();
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
			return pair<iterator,bool>(iterator(_ptr), true);
		}

// Hint for the position where the element can be inserted.
// The function optimizes its insertion time if position points to the element that will precede the inserted element.
// Notice that this is just a hint and does not force the new element to be inserted at that position 
// within the map container (the elements in a map always follow a specific order depending on their key).

		// iterator insert (iterator position, const value_type& val)
		// {

		// }

		// template <class InputIterator>
		// void insert (InputIterator first, InputIterator last)
		// {

		// }

	// OBSERVERS
		key_compare key_comp() const { return _comp.comp; }
		value_compare value_comp() const { return _comp; }
		bool empty() const {return bool(!_n); }

	// ALLOCATOR
		allocator_type get_allocator() const { return _alloc; }

		private:

		allocator_type	_alloc;
		value_compare	_comp;
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
			if (_n)
			{
				iterator it = begin();
				iterator ite = end();
				while (it != ite)
				{
					if (key == (*it).first)
						return it;
					it++;
				}
			}
			return NULL;
		}
	};

	// MAP'S NESTED CLASS TO STORE COMPARE OBJECT FUNCTION
	template <class Key, class T, class Compare, class Alloc>
	class map<Key,T,Compare,Alloc>::value_compare
	{
		friend class map;
		
		public:
		typedef bool		result_type;
		typedef value_type	first_argument_type;
		typedef value_type	second_argument_type;
		bool operator()(const value_type & x, const value_type & y) const
		{
			return comp(x.first, y.first);
		}

		protected:
		Compare comp;
		value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
	};
}

#endif
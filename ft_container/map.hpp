#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>
using namespace std;
#include <memory>
#include <stdexcept>
#include <functional>
#include "red_black_tree.hpp"
#include "iterators.hpp"
#include "pair.hpp"
#include "utils.hpp"

namespace ft
{	
	template<class Key, class T, class Compare, class Alloc >
	class map
	{
		class value_compare;
		
		public:
		
	// MEMBER TYPES
		typedef	Key												key_type;
		typedef	T												mapped_type;
		typedef	ft::pair<const key_type, mapped_type>			value_type;
		typedef	Compare											key_compare;
		typedef map::value_compare								val_comp;
		typedef	Alloc											allocator_type;
		typedef	typename allocator_type::reference				reference;
		typedef	typename allocator_type::const_reference		const_reference;
		typedef	typename allocator_type::pointer				pointer;
		typedef	typename allocator_type::const_pointer			const_pointer;
		typedef red_black_tree<Key,T,val_comp,Alloc>			rbt;
		typedef red_black_node<Key,T>							node;
		typedef	int												difference_type;
		typedef	unsigned int									size_type;
		typedef	ft::bidirectional_iterator<Key,T,node *,rbt *>	iterator;
		typedef	ft::bidirectional_iterator<const Key,T,const node *,rbt *>	const_iterator;
		typedef	ft::reverse_iterator<iterator>					reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>			const_reverse_iterator;

		explicit map(const key_compare & comp = key_compare(), 
		const allocator_type & alloc = allocator_type()) :
		_alloc(alloc), _comp(comp), _rbt(_comp)
		{
			value_type tmp = value_type();
			_ptr = _alloc.allocate(1);
			_alloc.construct(_ptr, tmp);
			_rbt._past_end_pair = _ptr;

			_ptr = _alloc.allocate(1);
			_alloc.construct(_ptr, ft::make_pair<char,int>('b',2));
			_rbt.insertion(_ptr);

			_ptr = _alloc.allocate(1);
			_alloc.construct(_ptr, ft::make_pair<char,int>('d',4));
			_rbt.insertion(_ptr);

			_ptr = _alloc.allocate(1);
			_alloc.construct(_ptr, ft::make_pair<char,int>('c',3));
			_rbt.insertion(_ptr);

			_ptr = _alloc.allocate(1);
			_alloc.construct(_ptr, ft::make_pair<char,int>('f',5));
			_rbt.insertion(_ptr);

			_ptr = _alloc.allocate(1);
			_alloc.construct(_ptr, ft::make_pair<char,int>('m',5));
			_rbt.insertion(_ptr);

			_ptr = _alloc.allocate(1);
			_alloc.construct(_ptr, ft::make_pair<char,int>('y',5));
			_rbt.insertion(_ptr);

			_ptr = _alloc.allocate(1);
			_alloc.construct(_ptr, ft::make_pair<char,int>('z',5));
			_rbt.insertion(_ptr);

			_ptr = _alloc.allocate(1);
			_alloc.construct(_ptr, ft::make_pair<char,int>('q',5));
			_rbt.insertion(_ptr);

			_ptr = _alloc.allocate(1);
			_alloc.construct(_ptr, ft::make_pair<char,int>('a',1));
			_rbt.insertion(_ptr);

			_ptr = _alloc.allocate(1);
			_alloc.construct(_ptr, ft::make_pair<char,int>('e',5));
			_rbt.insertion(_ptr);

			_rbt.print_tree();
		}

	// CONSTRUCTORS / DESTRUCTOR
		// explicit map(const key_compare & comp = key_compare(), 
		// const allocator_type & alloc = allocator_type()) :
		// _alloc(alloc), _comp(comp), _rbt(_comp)
		// {
		// 	value_type tmp = value_type();	// past_end pair, en dehors de l'arbre
		// 	_ptr = _alloc.allocate(1);
		// 	_alloc.construct(_ptr, tmp);
		// 	_rbt._past_end_pair = _ptr;
		// 	_rbt.print_tree();
		// }
		
		template <class InputIterator>
		map(InputIterator first, InputIterator last, 
		const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()) :
		_alloc(alloc), _comp(comp), _rbt(_comp)
		{
			size_type n = _distance<InputIterator>(first, last);
			if (n)
			{
				while (first != last)
				{
					_ptr = _alloc.allocate(1);
					_alloc.construct(_ptr, *first++);
					_rbt.insertion(_ptr);
				}
			}
			_rbt.print_tree();
		}

		// map(const map & x) :
		// _alloc(x.get_allocator()), _comp(x.key_comp()), _rbt(), _n(x.size()), _first(NULL), _last(NULL)
		// {
		// 	if (_n)
		// 	{
		// 		const_iterator it = x.begin();
		// 		const_iterator ite = x.end();
		// 		// _first = _alloc.allocate(_n + 1);
		// 		// _ptr = _first;
		// 		while (it != ite)
		// 		{
		// 			_ptr = _alloc.allocate(1);
		// 			_alloc.construct(_ptr, *it++);	// construction des key-value paires
		// 			_rbt.insertion(_ptr);			// attache les paires à des noeuds construits et insérés dans le rbt
		// 			// _rbt.insertion(_ptr++);			// attache les paires à des noeuds construits et insérés dans le rbt
		// 		}
		// 		// _last = --_ptr;
		// 	}
		// }

		// map & operator=(const map & x)
		// {
		// 	if (_n)
		// 	{
		// 		// _ptr = _first;
		// 		// while (_first != _last)
		// 		// 	_alloc.destroy(_first++);
		// 		// _alloc.deallocate(_ptr, _n + 1);
		// 		_rbt.free_tree(_rbt._root);
		// 		// _n = 0;
		// 		// _first = NULL;
		// 		// _last = NULL;
		// 	}
		// 	if (x.size())
		// 	{
		// 		_comp = x.key_comp();
		// 		_n = x.size();
		// 		const_iterator it = x.begin();
		// 		const_iterator ite = x.end();
		// 		_first = _alloc.allocate(_n + 1);
		// 		_ptr = _first;
		// 		while (it != ite)
		// 		{
		// 			_ptr = _alloc.allocate(1);
		// 			_alloc.construct(_ptr, *it++);	// construction des key-value paires
		// 			_rbt.insertion(_ptr);			// attache les paires à des noeuds construits et insérés dans le rbt
		// 			// _rbt.insertion(_ptr++);			// attache les paires à des noeuds construits et insérés dans le rbt
		// 		}
		// 		// _last = --_ptr;
		// 	}
		// 	return *this;
		// }

		~map() { _rbt.free_tree(); }

		// // ITERATORS
		iterator begin()					{ return iterator(_rbt.get_left_most()->key_val(), _rbt.get_left_most(), &_rbt); }
		iterator end()						{ return iterator(_rbt._past_end_ptr->key_val(), _rbt._past_end_ptr, &_rbt); }
		// iterator end() 					{ if (_n) return iterator(_last+1); return (_last);}
		// const_iterator begin() const 	{ return const_iterator(_first); }
		// const_iterator end() const 		{ if (_n) return const_iterator(_last+1); return (_last);}

		// // CAPACITY
		size_type size() const { return _rbt._n; }

		// // ELEMENT ACCESS
		// mapped_type & operator[](const key_type & k)
		// {
		// 	value_type new_pr = ft::make_pair(k, mapped_type());
		// 	pair<iterator,bool> checked = insert(new_pr);
		// 	return (*checked.first).second;
		// }

		// MODIFIERS
		pair<iterator,bool> insert(const value_type & val)
		{
			// rbt cherche dans la liste si la key est déjà utiliser
			node * pos = _rbt.search(val.first);
			if (pos)
			{
				iterator it_pos(pos->key_val(), pos, &_rbt);
				return pair<iterator,bool>(it_pos, false);
			}
			// créer et insérer une nouvelle pair dans l'arbre
			_ptr = _alloc.allocate(1);
			_alloc.construct(_ptr, val);
			pos = _rbt.insertion(_ptr);

			// retourner une pair<iterator,bool> contenant:
			// <l'itérateur de l'élément dans la node liste, true>
			iterator it_pos(pos->key_val(), pos, &_rbt);
			return pair<iterator,bool>(it_pos, true);
		}

		// iterator insert (iterator position, const value_type& val)
		// {

		// }

		// template <class InputIterator>
		// void insert (InputIterator first, InputIterator last)
		// {

		// }

	// OBSERVERS
		key_compare key_comp() const	{ return _comp.comp; }
		val_comp value_comp() const		{ return _comp; }
		bool empty() const 				{ return bool(!_rbt._n); }

	// ALLOCATOR
		allocator_type get_allocator() const { return _alloc; }

		private:
		allocator_type			_alloc;
		val_comp				_comp;
		rbt						_rbt;
		pointer					_ptr;
		pointer					_past_end;

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

		// iterator _check_keys(key_type key)
		// {
		// 	if (_n)
		// 	{
		// 		iterator it = begin();
		// 		iterator ite = end();
		// 		while (it != ite)
		// 		{
		// 			if (key == (*it).first)
		// 				return it;
		// 			it++;
		// 		}
		// 	}
		// 	return NULL;
		// }
	};

	// Class qui génère un objet pour stocker dans 'Compare comp' 
	// la fonction de comparaison binaire de deux pairs
	template <class Key, class T, class Compare, class Alloc>
	class map<Key,T,Compare,Alloc>::value_compare
	{
		friend class map;
		
		public:
		typedef bool		result_type;
		typedef value_type	first_argument_type;
		typedef value_type	second_argument_type;
		Compare comp;
		bool operator()(const value_type & x, const value_type & y) const
		{
			return comp(x.first, y.first);
		}

		protected:
		value_compare (Compare c) : comp(c) {}
	};
}

#endif
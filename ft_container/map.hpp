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
		typedef red_black_tree<Key,T,val_comp>					rbt;
		typedef red_black_node<Key,T>							node;
		typedef	ft::bidirectional_iterator<Key,T,node *,rbt *>			iterator;			// passer <node_list> en argument template la place 
		typedef	ft::bidirectional_iterator<const Key,T,const node *,rbt *>	const_iterator;		// et modifier le comportement de bidirectionl it en fonction
		typedef	ft::reverse_iterator<iterator>					reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		typedef	int												difference_type;
		typedef	unsigned int									size_type;

	// CONSTRUCTORS / DESTRUCTOR
		explicit map(const key_compare & comp = key_compare(), 
		const allocator_type & alloc = allocator_type()) :
		_alloc(alloc), _comp(comp), _rbt(_comp), _first(), _last(), _current(&_first), _prev(NULL) 
		{
			// _rbt.print_tree();
			// create_node_list();
			// print_node_list();
		}
		
		// explicit map(const key_compare & comp = key_compare(), 
		// const allocator_type & alloc = allocator_type()) :
		// _alloc(alloc), _comp(comp), _rbt(_comp), _first(), _last(), _current(&_first), _prev(NULL) 
		// {
		// 	// **********************************
		// 	// ************* TESTS **************
		// 	_ptr = _alloc.allocate(15);

		// 	_alloc.construct(_ptr, ft::make_pair<char,int>('b',2));
		// 	_rbt.insertion(_ptr++);

		// 	_alloc.construct(_ptr, ft::make_pair<char,int>('d',4));
		// 	_rbt.insertion(_ptr++);

		// 	_alloc.construct(_ptr, ft::make_pair<char,int>('c',3));
		// 	_rbt.insertion(_ptr++);

		// 	_alloc.construct(_ptr, ft::make_pair<char,int>('f',5));
		// 	_rbt.insertion(_ptr++);

		// 	_alloc.construct(_ptr, ft::make_pair<char,int>('m',5));
		// 	_rbt.insertion(_ptr++);

		// 	_alloc.construct(_ptr, ft::make_pair<char,int>('y',5));
		// 	_rbt.insertion(_ptr++);

		// 	_alloc.construct(_ptr, ft::make_pair<char,int>('z',5));
		// 	_rbt.insertion(_ptr++);

		// 	_alloc.construct(_ptr, ft::make_pair<char,int>('q',5));
		// 	_rbt.insertion(_ptr++);

		// 	_alloc.construct(_ptr, ft::make_pair<char,int>('a',1));
		// 	_rbt.insertion(_ptr++);

		// 	_alloc.construct(_ptr, ft::make_pair<char,int>('e',5));
		// 	_rbt.insertion(_ptr);

		// 	_rbt.print_tree();
		// 	// create_node_list();
		// 	// print_node_list();
		// }

		// template <class InputIterator>
		// map(InputIterator first, InputIterator last, 
		// const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()) :
		// _alloc(alloc), _comp(comp), _rbt(), _n(0)
		// {
		// 	size_type n = _distance<InputIterator>(first, last);
		// 	if (n)
		// 	{
		// 		while (first != last)
		// 		{
		// 			_ptr = _alloc.allocate(1);
		// 			_alloc.construct(_ptr, *first++);
		// 			_rbt.insertion(_ptr);
		// 		}
		// 		_n = n;
		// 	}
		// }

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


		// A décider + tard si je veux free les pairs dans free_tree ou dans free_node_list
		~map()
		{			
			free_node_list();	// free les pairs plutot dans node_list (a priori)
		}

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
			// 1. rbt cherche dans la liste si la key est déjà utiliser
				// si oui retourne une pair<iterator,bool> contenant:
				// <it(pos.key), false>
			// 2.1 créer et insérer une nouvelle pair dans l'arbre
			// 2.2 update la liste chainée
			// 3. retourner une pair<iterator,bool> contenant:
			//    <l'itérateur de l'élément dans la node liste, true>

			// iterator key_check = _check_keys(val.first);		// faire en sorte que le rbt perform le key_check (sera + rapide)
			// if (key_check != NULL)
			// 	return pair<iterator,bool>(key_check, false);
			// if (_n)
			// {
			// 	iterator it = begin();
			// 	iterator ite = end();
			// 	pointer f = _first;
			// 	_first = _alloc.allocate(_n + 2);				// arrêter d'allouer à chaque nouvel élément inséré
			// 	_ptr = _first;									// augmenter la capacité en *2, un peu comme vector 
			// 	while (it != ite)
			// 	{
			// 		_alloc.construct(_ptr++, *it++);

			// 	}
			// 	_alloc.construct(_ptr, val);
			// 	_last = _ptr;
			// 	_alloc.deallocate(f, _n + 1);
			// }
			// else
			// {
			// 	_first = _alloc.allocate(2);
			// 	_ptr = _first;
			// 	_alloc.construct(_ptr, val);
			// 	_last = _first;
			// }
			// _n++;
			// return pair<iterator,bool>(iterator(_ptr), true);
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
	// PRIVATE FUNCTIONS TO MANAGE METHODS
		allocator_type	_alloc;
		val_comp		_comp;
		rbt				_rbt;
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

	// NODE LIST TO GET ORDERED PAIRS POINTER
		struct node_list
		{
			value_type *	ptr;
			node_list *		next;
			node_list *		prev;
			node_list() : ptr(NULL), next(NULL), prev(NULL) {}
			~node_list() {}
		};
		node_list			_first;
		node_list			_last;
		node_list *			_current;
		node_list *			_prev;

		void create_node_list()
		{
			cout << endl << "[CREATE NODE LIST]" << endl;
			create_node_list_recursiv(_rbt._root);
			cout << &_last <<  "(_last node) contains : " << _last.ptr << endl << endl;
		}
		void create_node_list_recursiv(node * root)
		{
			if (root == NULL)
				return;
			create_node_list_recursiv(root->left());
			if (_first.ptr == NULL)
			{
				_current = &_first;
				
				_current->ptr = root->key_val();
				_current->prev = NULL;
				_current->next = &_last;

				_last.prev = _current;
				cout << _current <<  "(_first node) contains : " << root->key_val()->first << endl;
			}
			else
			{
				_prev = _current;
				_current = new node_list();

				_current->ptr = root->key_val();
				_current->prev = _prev;
				_current->next = &_last;

				_prev->next = _current;
				_last.prev = _current;
				cout << "create node containing " << root->key_val()->first << " : " << _current << endl;
			}
			create_node_list_recursiv(root->right());
		}
		void print_node_list()
		{
			node_list	*current;
			node_list	*next;

			current = &_first;
			if (current->ptr)
			{
				cout << "[PRINT CONTAINER VALUE (from node list)]" << endl;
				cout << "syntax: key - value (pair_ptr)" << endl;
				while (current->ptr)
				{
					next = current->next;
					cout << current->ptr->first << " - " << current->ptr->second;
					cout << " (" << current->ptr << ")" << endl;
					current = next;
				}
				cout << endl;
			}
		}
		void free_node_list()
		{
			cout << endl << "[FREE NODE LIST]" << endl;
			node_list	*current;
			node_list	*next;
			current = &_first;
			while (current->ptr)
			{
				next = current->next;
				// _alloc.destroy(current->ptr);
				// _alloc.deallocate(current->ptr, 1);
				if (current != &_first && current != &_last)
				{
					cout << "free node containing " << current->ptr->first << " : " << current << endl;
					delete current;
				}
				current = next;
			}
			cout << "reset _first to null" << endl;
			cout << "reset _last to null" << endl;
			_first.ptr = NULL;
			_first.prev = NULL;
			_first.next = NULL;
			_last.ptr = NULL;
			_last.prev = NULL;
			_last.next = NULL;
			cout << endl;
		}
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
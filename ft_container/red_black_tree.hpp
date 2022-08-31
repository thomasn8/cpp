#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

#define NOIR 0
#define ROUGE 1
#define FEUILLE 0

#include "pair.hpp"

namespace ft
{
	// *obligé de déclarer la classe avant pour que le friend fonctionne
	// car red_black_tree.hpp est include dans map.hpp
	// donc red_black_tree ne connait pas encore map
	template < class Key, class T, 
	class Compare = less<Key>, 
	class Alloc = allocator< ft::pair< const Key,T> > >
	class map;

	template<class Key, class T>
	class red_black_tree
	{
		friend class map<Key,T>;

		public:
		
		class node_compare;
		class red_black_node;

		typedef	Key											key_type;
		typedef	T											mapped_type;
		typedef	ft::pair<const key_type, mapped_type>		value_type;
		typedef red_black_tree::red_black_node				node;
		typedef	unsigned int								size_type;

		protected:
		size_type		_n;
		node *			_root;
		node *			_first;
		node *			_last;
		red_black_tree() {}
	};

	template<class Key, class T>
	class red_black_tree<Key,T>::red_black_node
	{
		friend class red_black_tree;

		public:
		typedef	red_black_node	node;
		
		protected:

		node *	gauche; // Pointeur vers fils gauche
		node *	droit; 	// Pointeur vers fils droit 
		node *	parent; // Pointeur vers père
		char	color; 	// ROUGE ou NOIR

		pair<const Key, T> *	key_val;	// Pointeur vers les datas du noeud
		red_black_node() {};
	};
}

#endif
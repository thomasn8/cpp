#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

/* 
	Utilisation du friend keyword dans les classes qui suivent :
	-	toutes ces class auraient pu être nested directement dans map 
		mais ça alourdirait beaucoup le code de map
	-	de plus, red_black_tree peut être directement réutilisé (en friend) 
		par d'autres class containers sans devoir être redéfinis
*/

#define NOIR 0
#define ROUGE 1
#define FEUILLE 0

#include "pair.hpp"

namespace ft
{
	/* obligé de déclarer la classe avant pour que le friend dans rbt fonctionne
	car red_black_tree.hpp est include dans map.hpp
	donc rbt ne connait pas encore map */
	template < class Key, class T, 
	class Compare = less<Key>, 
	class Alloc = allocator< ft::pair< const Key,T> > >
	class map;

	template<class Key, class T>
	class red_black_tree
	{
		friend class map<Key,T>;
		class node_compare;
		class red_black_node;

		public:
		typedef	ft::pair<const Key, T>				value_type;
		typedef red_black_tree::red_black_node		node;
		typedef	unsigned int						size_type;

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
		node *	gauche; 				// Pointeur vers fils gauche
		node *	droit; 					// Pointeur vers fils droit 
		node *	parent; 				// Pointeur vers père
		char	color; 					// ROUGE ou NOIR
		pair<const Key, T> * key_val;	// Pointeur vers les datas du noeud
		red_black_node() {};
	};
}

#endif
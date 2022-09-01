#ifndef RED_BLACK_NODE_HPP
# define RED_BLACK_NODE_HPP

#include "pair.hpp"
#define B 0
#define R 1
#define LEAF 0

namespace ft
{	
	template<class Key, class T>
	class red_black_node
	{
		public:
		typedef	red_black_node				node;
		typedef	pair<Key,T> *				pointer;
		
		node *			left; 				// Pointeur vers fils left
		node *			right; 				// Pointeur vers fils right 
		node *			parent; 			// Pointeur vers père
		int				color; 				// RED ou BLACK
		pointer			key_val;			// Pointeur vers les datas du noeud
		
		red_black_node(pointer pair) : 
		key_val(pair), color(B), left(NULL), right(NULL), parent(NULL) {}
	};
}

#endif

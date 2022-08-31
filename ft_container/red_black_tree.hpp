#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

/* 
	Utilisation du friend keyword dans les classes qui suivent :
	-	toutes ces class auraient pu être nested directement dans map 
		mais ça alourdirait beaucoup le code de map
	-	de plus, red_black_tree peut être directement réutilisé (en friend) 
		par d'autres class containers sans devoir être redéfinis
*/

#define B 0
#define R 1
#define LEAF 0

#include <memory>
#include "pair.hpp"

namespace ft
{	
	class red_black_node;
	/* pré-déclaration */
	template < class Key, class T, 
	class Compare = less<Key>, 
	class Alloc = allocator< ft::pair< const Key,T> > >
	class map;
	/* obligé de déclarer la classe avant pour que le friend dans rbt fonctionne
	car red_black_tree.hpp est include dans map.hpp
	donc rbt ne connait pas encore map */

	template<class Key, class T, class Alloc = allocator< red_black_node > >
	class red_black_tree
	{
		friend class map<Key,T>;
		class node_compare;
		class red_black_node;

		public:

		typedef	ft::pair<const Key, T>						value_type;
		typedef red_black_tree::red_black_node				node;
		typedef	Alloc										allocator_type;
		typedef	typename allocator_type::reference			reference;
		typedef	typename allocator_type::const_reference	const_reference;
		typedef	typename allocator_type::pointer			pointer;
		typedef	typename allocator_type::const_pointer		const_pointer;
		typedef	unsigned int								size_type;
		typedef	int											difference_type;

		node * parent(node * n) const 
		{ 
			return n->parent;
		}
		node * grandparent(node * n) const
		{
			node * p = parent(n);
			if (p == NULL)
				return NULL; // Un noeud sans parent n'a pas de grand-parent
			return parent(p);
		}
		node * frere(node * n) const
		{
			node * p = parent(n);
			if (p == NULL)
				return NULL; // Un noeud sans parent n'a pas de frere
			if (n == p->left)
				return p->right;
			else
				return p->left;
		}
		node * uncle(node * enfant) const	//Renvoie le frère du père
		{
			node * p = parent(enfant);
			node * g = grandparent(enfant);
			if (g == NULL)
				return NULL; // Pas de grand parent, donc pas d'uncle
			return frere(p);
		}

		protected:

		size_type		_n;
		node *			_root;
		node *			_ptr;
		red_black_tree(const allocator_type & alloc = allocator_type()) : 
		_alloc(alloc), _n(0), _root(NULL) {}

		node * insertion(value_type * pair)
		{
			_ptr = _alloc.allocate(1);
		// // _alloc.construct(_ptr, *pair)
		// 	// node n(pair);
		// 	// Insertion d'un nouveau nœud dans l'tree
		// 	insertion_recursiv(_root, &n);
		// 	// Réparation de l'tree au cas où les propriétés RED-BLACK seraient violées
		// 	insertion_repare_tree(&n);
		// 	// Recherche de la nouvelle root à renvoyer
		// 	_root = &n;
		// 	while (parent(_root) != NULL)
		// 		_root = parent(_root);
		// 	return _root;
			return _ptr;
		}
		// node * insertion(node * root, node * n) 
		// {
		// 	// Insertion d'un nouveau nœud dans l'tree
		// 	insertion_recursiv(root, n);
		// 	// Réparation de l'tree au cas où les propriétés RED-BLACK seraient violées
		// 	insertion_repare_tree(n);
		// 	// Recherche de la nouvelle root à renvoyer
		// 	root = n;
		// 	while (parent(root) != NULL)
		// 		root = parent(root);
		// 	return root;
		// }

		private:

		Alloc _alloc;

		void insertion_recursiv(node * root, node * n) 
		{
			// Descente récursive dans l'tree jusqu'à atteindre une LEAF
			if (root != NULL && n->clé < root->clé) 
			{
				if (root->left != LEAF) 
				{
					insertion_recursiv(root->left, n);
					return;
				}
				else
				root->left = n;
			} 
			else if (root != NULL) 
			{
				if (root->right != LEAF) 
				{
					insertion_recursiv(root->right, n);
					return;
				}
				else
				root->right = n;
			}
			// Insertion du nouveau noeud n
			n->parent = root;
			n->left = LEAF; // NIL
			n->right = LEAF; // NIL
			n->color = R;
		}
		void insertion_repare_tree(node * n) 
		{
			if (parent(n) == NULL)
				insertion_case1(n);
			else if (parent(n)->color == B)
				insertion_case2(n);
			else if (uncle(n)->color == R)
				insertion_case3(n);
			else
				insertion_case4(n);
		}
		void insertion_case1(node * n)
		{
			if (parent(n) == NULL)
				n->color = B;
		}
		void insertion_case2(node * n) { return; } /* Ne rien faire puisque l'tree est bien un tree RED-BLACK */
		void insertion_case3(node * n)
		{
			parent(n)->color = B;
			uncle(n)->color = B;
			node * g = grandparent(n);
			g->color = R;
			insertion_repare_tree(g);
		}
		void insertion_case4(node * n) 
		{
			node * p = parent(n);
			node * g = grandparent(n);
			if (n == g->left->right) {
				rotation_left(p);
				n = n->left;
			} else if (n == g->right->left) {
				rotation_right(p);
				n = n->right; 
			}
			insertion_case5(n);
		}
		void insertion_case5(node * n)
		{
			node * p = parent(n);
			node * g = grandparent(n);
			if (n == p->left)
				rotation_right(g);
			else
				rotation_left(g);
			p->color = B;
			g->color = R;
		}

		void rotation_left(node * x) 
		{
			node * y = x->right;
			//le fils right de x devient le fils left de y
			x->right = y->left;
			if (y->left != LEAF)
				y->left->parent = x;
			
			y->parent = x->parent;
			//Si x est la root, y devient la root
			if (x->parent == NULL)
				x = y;
			//Sinon, on remplace x par y
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			//On attache x à left de y
			y->left = x;
			x->parent = y;
		}
		void rotation_right(node * x) 
		{
			node * y = x->left;
			//le fils left de x devient le fils right de y
			x->left = y->right;
			if (y->right != LEAF)
				y->right->parent = x;
			y->parent = x->parent;
			//Si x est la root, y devient la root
			if (x->parent == NULL)
				x = y;
			//Sinon, on remplace x par y
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			//On attache x à righte de y
			y->right = x;
			x->parent = y;
		}
	};

	template<class Key, class T, class Alloc>
	class red_black_tree<Key,T,Alloc>::red_black_node
	{
		friend class red_black_tree;

		public:
		typedef	red_black_node			node;
		typedef	ft::pair<const Key,T>	value_type;
		
		protected:
		node *			left; 		// Pointeur vers fils left
		node *			right; 		// Pointeur vers fils right 
		node *			parent; 	// Pointeur vers père
		char			color; 		// RED ou BLACK
		value_type * 	key_val;	// Pointeur vers les datas du noeud
		red_black_node(value_type * pair) : 
		key_val(pair), color(B), left(NULL), right(NULL), parent(NULL) {}
	};
}

#endif

// syntaxe pour bien mettre en place des class friend :
// https://cplusplus.com/forum/beginner/185880/
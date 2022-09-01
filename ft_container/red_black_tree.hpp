#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP
/* 
	Utilisation du friend keyword dans les classes qui suivent :
	-	toutes ces class auraient pu être nested directement dans map 
		mais ça alourdirait beaucoup le code de map
	-	de plus, red_black_tree peut être directement réutilisé (en friend) 
		par d'autres class containers sans devoir être redéfinis
*/

#include <iostream>
using namespace std;
#include <memory>
#include "pair.hpp"
#include "red_black_node.hpp"

#define B 0
#define R 1
#define LEAF 0

namespace ft
{	
	/* pré-déclaration */
	template < class Key, class T, 
	class Compare = less<Key>, 
	class Alloc = allocator< ft::pair< const Key,T> > >
	class map;
	/* obligé de déclarer la classe avant pour que le friend dans rbt fonctionne
	car red_black_tree.hpp est include dans map.hpp
	donc rbt ne connait pas encore map */

	template<class Key, class T, class Alloc = allocator< red_black_node<Key,T> > >
	class red_black_tree
	{
		friend class map<Key,T>;

		public:

		typedef	ft::pair<const Key, T>						value_type;
		typedef red_black_node<Key,T>						node;
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
				return NULL;
			return parent(p);
		}
		node * frere(node * n) const
		{
			node * p = parent(n);
			if (p == NULL)
				return NULL;
			if (n == p->left)
				return p->right;
			else
				return p->left;
		}
		node * uncle(node * enfant) const
		{
			node * p = parent(enfant);
			node * g = grandparent(enfant);
			if (g == NULL)
				return NULL;
			return frere(p);
		}

		protected:

		size_type		_n;
		node *			_root;
		node *			_ptr;

		red_black_tree(const allocator_type & alloc = allocator_type()) : 
		_alloc(alloc), _n(0), _root(NULL) {}
		~red_black_tree() { free_tree(_root); }

		node * insertion(value_type * pair)
		{
			_ptr = _alloc.allocate(1);
			_alloc.construct(_ptr, node(pair));
			insertion_recursiv(_root, _ptr);
			insertion_repare_tree(_ptr);
			_root = _ptr;
			_n++;
			while (parent(_root) != NULL)
				_root = parent(_root);
			return _root;
		}

		private:

		Alloc _alloc;

		void insertion_recursiv(node * root, node * n) 
		{
			// Descente récursive dans l'arbre jusqu'à atteindre une LEAF
			if (root != NULL && n->key_val->first < root->key_val->first) 
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
		void insertion_case2(node * n) { return; } /* Ne rien faire puisque l'arbre est bien un tree RED-BLACK */
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
			if (n == g->left->right) 
			{
				rotation_left(p);
				n = n->left;
			} 
			else if (n == g->right->left) 
			{
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
			x->right = y->left;
			if (y->left != LEAF)
				y->left->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				x = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;
			x->parent = y;
		}
		void rotation_right(node * x) 
		{
			node * y = x->left;
			x->left = y->right;
			if (y->right != LEAF)
				y->right->parent = x;
			y->parent = x->parent;
			if (x->parent == NULL)
				x = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
		}
		void free_tree(node * root)
		{
			cout << "[A IMPLEMENTER] Rbt traversed. All nodes have been freed." << endl; 
			// // Descente récursive dans l'arbre jusqu'à atteindre une LEAF
			// // Destroy + Deallocate les pairs
			// // Destroy + Deallocate les nodes
			// node * tmp;
			pointer tmp;
			if (root != NULL)
			{
				if (root->left != LEAF)
				{
					free_tree(root->left);
					return;
				}
				else if (root->right != LEAF)
				{
					free_tree(root->right);
					return;
				}
				else // on est sur un fils sans descendant
				{
					cout << root->key_val->first << endl;
					// tmp = dynamic_cast<ft::red_black_node *>(root);
					// tmp = dynamic_cast<node *>(root);
					tmp = reinterpret_cast<pointer>(root);
					root = root->parent;
					if (tmp == reinterpret_cast<pointer>(root->left))
						root->left = LEAF;
					else
						root->right = LEAF;
					_alloc.destroy(tmp);
					_alloc.deallocate(tmp, 1);
				}
			}


			// if (root != NULL) ‰
			// {
			// 	if (root->left != LEAF) 
			// 	{
			// 		free_tree(root->left);
			// 		return;
			// 	}
			// 	else
			// 		root->left = n;
			// 	if (root->right != LEAF) 
			// 	{
			// 		free_tree(root->right);
			// 		return;
			// 	}
			// 	else
			// 		root->right = n;
			// }
			_n = 0;
			_root = NULL;
		}
	};

	// template<class Key, class T, class Alloc>
	// class red_black_tree<Key,T,Alloc>::red_black_node
	// {
	// 	friend class red_black_tree;

	// 	public:
	// 	typedef	red_black_node			node;
	// 	typedef	ft::pair<const Key,T>	value_type;
		
	// 	protected:
	// 	node *			left; 		// Pointeur vers fils left
	// 	node *			right; 		// Pointeur vers fils right 
	// 	node *			parent; 	// Pointeur vers père
	// 	char			color; 		// RED ou BLACK
	// 	value_type * 	key_val;	// Pointeur vers les datas du noeud
	// 	red_black_node(value_type * pair) : 
	// 	key_val(pair), color(B), left(NULL), right(NULL), parent(NULL) {}
	// };
}

#endif

// syntaxe pour bien mettre en place des class friend :
// https://cplusplus.com/forum/beginner/185880/
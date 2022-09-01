#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP
/* 
	Utilisation du friend keyword dans les classes qui suivent :
	-	toutes ces class auraient pu être nested directement dans map 
		mais ça alourdirait beaucoup le code de map
	-	de plus, red_black_tree peut être directement réutilisé (en friend) 
		par d'autres class containers sans devoir être redéfini
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

		typedef	ft::pair<const Key,T>						value_type;
		typedef red_black_node<Key,T>						node;
		typedef	Alloc										allocator_type;
		typedef	typename allocator_type::reference			reference;
		typedef	typename allocator_type::const_reference	const_reference;
		typedef	typename allocator_type::pointer			pointer;
		typedef	typename allocator_type::const_pointer		const_pointer;
		typedef	unsigned int								size_type;
		typedef	int											difference_type;

		protected:

		size_type		_n;
		node *			_root;
		node *			_ptr;

		red_black_tree(const allocator_type & alloc = allocator_type()) : 
		_alloc(alloc), _n(0), _root(NULL) {}
		// ~red_black_tree() { free_tree(_root); }

		/* struct noeud *insertion(struct noeud *racine, struct noeud *n) {
			// Insertion d'un nouveau nœud dans l'arbre
			insertion_recursif(racine, n);

			// Réparation de l'arbre au cas où les propriétés rouge-noir seraient violées
			insertion_repare_arbre(n);

			// Recherche de la nouvelle racine à renvoyer
			racine = n;
			
			while (parent(racine) != NULL)
				racine = parent(racine);
				
			return racine;
		} */

		node * insertion(value_type * pair)
		{
			_ptr = _alloc.allocate(1);
			node tmp(pair);
			_alloc.construct(_ptr, tmp);
			insertion_recursiv(_root, _ptr);	// error ?
			insertion_repare_tree(_ptr);		// ERROR
			
			cout << &*_ptr << " " << _ptr->key_val()->first << endl;
	
			_root = _ptr;

			cout << "Root: " << &*_root << " " << _root->key_val()->first << endl;
			while (_root->parent() != NULL)
				_root = _root->parent();
			_n++;
			return _root;
		}

		private:

		Alloc _alloc;

		void insertion_recursiv(node * root, node * n) 
		{
			// Descente récursive dans l'arbre jusqu'à atteindre une LEAF
			// if (root != NULL && n->key_val()->first < root->key_val()->first) 
			if (root != NULL && n->key_val() < root->key_val()) 
			{
				if (root->left() != LEAF) 
				{
					insertion_recursiv(root->left(), n);
					return;
				}
				else
					root->setLeft(n);
			} 
			else if (root != NULL) 
			{
				if (root->right() != LEAF) 
				{
					insertion_recursiv(root->right(), n);
					return;
				}
				else
					root->setRight(n);
			}
			// Insertion du nouveau noeud n
			n->setParent(root);
			n->setLeft(LEAF); // NIL
			n->setRight(LEAF); // NIL
			n->setColor(R);
		}
		void insertion_repare_tree(node * n) 
		{
			if (n->parent() == NULL)
				insertion_case1(n);
			else if (n->parent()->color() == B)
				insertion_case2(n);
			else if (n->uncle()->color() == R)
				insertion_case3(n);
			else
				insertion_case4(n);
		}
		void insertion_case1(node * n)
		{
			if (n->parent() == NULL)
				n->setColor(B);
		}
		void insertion_case2(node * n) { return; } /* Ne rien faire puisque l'arbre est bien un tree RED-BLACK */
		void insertion_case3(node * n)
		{
			n->parent()->setColor(B);
			n->uncle()->setColor(B);
			node * g = n->grandparent();
			g->setColor(R);
			insertion_repare_tree(g);
		}
		void insertion_case4(node * n) 
		{
			node * p = n->parent();
			node * g = n->grandparent();
			if (n == g->left()->right()) 
			{
				rotation_left(p);
				n = n->left();
			} 
			else if (n == g->right()->left()) 
			{
				rotation_right(p);
				n = n->right();
			}
			insertion_case5(n);
		}
		void insertion_case5(node * n)
		{
			node * p = n->parent();
			node * g = n->grandparent();
			if (n == p->left())
				rotation_right(g);
			else
				rotation_left(g);
			p->setColor(B);
			g->setColor(R);
		}
		void rotation_left(node * x) 
		{
			node * y = x->right();
			x->setRight(y->left());
			if (y->left() != LEAF)
				y->left()->setParent(x);
			y->setParent(x->parent());
			if (x->parent() == NULL)
				x = y;
			else if (x == x->parent()->left())
				x->parent()->setLeft(y);
			else
				x->parent()->setRight(y);
			y->setLeft(x);
			x->setParent(y);
		}
		void rotation_right(node * x) 
		{
			node * y = x->left();
			x->setLeft(y->right());
			if (y->right() != LEAF)
				y->right()->setParent(x);
			y->setParent(x->parent());
			if (x->parent() == NULL)
				x = y;
			else if (x == x->parent()->right())
				x->parent()->setRight(y);
			else
				x->parent()->setLeft(y);
			y->setRight(x);
			x->setParent(y);
		}
		// void free_tree(node * root)
		// {
		// 	cout << "[A IMPLEMENTER] Rbt traversed. All nodes have been freed." << endl; 
		// 	// // Descente récursive dans l'arbre jusqu'à atteindre une LEAF
		// 	// // Destroy + Deallocate les pairs
		// 	// // Destroy + Deallocate les nodes
		// 	if (root != NULL)
		// 	{
		// 		if (root->left() != LEAF)
		// 		{
		// 			free_tree(root->left());
		// 			return;
		// 		}
		// 		else if (root->right() != LEAF)
		// 		{
		// 			free_tree(root->right());
		// 			return;
		// 		}
		// 		else // on est sur un fils sans descendant
		// 		{
		// 			cout << root->key_val()->first << endl;
		// 			_ptr = root;
		// 			root = root->parent();
		// 			if (_ptr == root->left())
		// 				root->setLeft(LEAF);
		// 			else
		// 				root->setRight(LEAF);
		// 			_alloc.destroy(_ptr);
		// 			_alloc.deallocate(_ptr, 1);
		// 		}
		// 	}
		// 	_n = 0;
		// 	_root = LEAF;
		// }
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
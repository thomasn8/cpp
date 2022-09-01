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
			static int x = 10;

			_ptr = _alloc.allocate(1);
			node tmp(pair);
			_alloc.construct(_ptr, tmp);
			insertion_recursiv(_root, _ptr);
			insertion_repare_tree(_ptr);		// ERROR
			
			cout << "New node: " << _ptr->color() << " " << &*_ptr << " " << _ptr->key_val()->first << endl;
	
			node * root = _ptr;
			// _root = _ptr;
			while (root->parent() != NULL && x-- > 0)
			// while (root->parent() != NULL)
			{
				// cout << "while loop" << endl;
				cout << x << "." << root << " = " << root->parent() << endl;
				// _root = _root->parent();
				root = root->parent();
			}
			_root = root;
			// cout << "while loop terminée" << endl;
			_n++;
			cout << "Root: " << _root->color() << " " << &*_root << " " << _root->key_val()->first << endl << endl;
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
				cout << "récurs 1" << endl;
					insertion_recursiv(root->left(), n);
					return;
				}
				else
				{
					cout << "récurs 2" << endl;
					root->setLeft(n);
				}
			} 
			else if (root != NULL) 
			{
				if (root->right() != LEAF) 
				{
					cout << "récurs 3" << endl;
					insertion_recursiv(root->right(), n);
					return;
				}
				else
				{
					cout << "récurs 4" << endl;
					root->setRight(n);
				}
			}
			// Insertion du nouveau noeud n
			cout << "récurs 0" << endl;
			n->setParent(root);
			n->setLeft(LEAF); // NIL
			n->setRight(LEAF); // NIL
			n->setColor(R);
		}
		void insertion_repare_tree(node * n) 
		{
			static int x = 0;
			cout << "insertion n° " << ++x << endl;
			// if (x == 3)
			// {
			// 	// cout << "TEST" << endl;
			// }

			if (n->parent() == NULL)
			{
				cout << "cas 1" << endl;
				insertion_case1(n);
			}
			else if (n->parent() && n->parent()->color() == B)
			{
				cout << "cas 2" << endl;
				insertion_case2(n);
			}
			else if (n->uncle() && n->uncle()->color() == R)
			{
				cout << "cas 3" << endl;
				insertion_case3(n);
			}
			else
			{
				cout << "cas 4" << endl;
				insertion_case4(n);
			}
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
			// cout << "cas 4 begin - g = " << &*g << endl;
			if (g->left() && n == g->left()->right()) 
			{
				cout << "cas 4.1" << endl;
				rotation_left(p);
				n = n->left();
			} 
			else if (g->right() && n == g->right()->left()) 
			{
				cout << "cas 4.2" << endl;
				rotation_right(p);
				n = n->right();
			}
			// cout << "cas 4 end" << endl;
			insertion_case5(n);
		}
		void insertion_case5(node * n)
		{
			node * p = n->parent();
			node * g = n->grandparent();
			if (n == p->left())
			{
				cout << "5.1: rotation right" << endl;
				rotation_right(g);
			}
			else
			{
				cout << "5.2: rotation left" << endl;
				rotation_left(g);
			}
			p->setColor(B);
			cout << p->key_val()->first << "(" << p << ")" << " becomes black and has parent: " << p->parent() << endl;
			g->setColor(R);
			cout << g->key_val()->first << "(" << g << ")" << " becomes red and has parent:  " << g->parent() << endl;
			cout << "root is now: " << _root->key_val()->first << endl;
			cout << "cas 5 end" << endl;
		}

		void rotation_gauche(struct noeud* x) {
			struct noeud* y = x->droit;
			//le fils droit de x devient le fils gauche de y

			x->droit = y->gauche;
			if (y->gauche != FEUILLE)
				y->gauche->parent = x;
			
			y->parent = x->parent;
			//Si x est la racine, y devient la racine
			if (x->parent == NULL)
				x = y;

			//Sinon, on remplace x par y
			else if (x == x->parent->gauche)
				x->parent->gauche = y;
			else
				x->parent->droit = y;

			//On attache x à gauche de y
			y->gauche = x;
			x->parent = y;
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
}

#endif

// syntaxe pour bien mettre en place des class friend :
// https://cplusplus.com/forum/beginner/185880/
#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP
/* 	
	Utilisation du friend keyword dans les classes qui suivent :
	-	toutes ces class auraient pu être nested directement dans map 
		mais ça alourdirait beaucoup le code de map
	-	de plus, red_black_tree peut être directement réutilisé (en friend) 
		par d'autres class containers sans devoir être redéfini

	syntaxe pour bien mettre en place des class friend :
	https://cplusplus.com/forum/beginner/185880/
*/

#include <iostream>
using namespace std;
#include <memory>
#include "pair.hpp"
#include "red_black_node.hpp"

# define B 0
# define R 1
# define LEAF 0
# define COUNT 15
# define RED "\033[0;31m"
# define WHI "\033[0m"

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

		void print_tree_2d(node *root)
		{
			cout << endl << endl;
			print_tree(root, 5);
			cout << endl << endl;
		}

		protected:

		size_type		_n;
		node *			_root;
		node *			_ptr;

		red_black_tree(const allocator_type & alloc = allocator_type()) : 
		_alloc(alloc), _n(0), _root(NULL) {}
		~red_black_tree() { print_tree_2d(_root); free_tree(_root); }

		node * insertion(value_type * pair)
		{
			_ptr = _alloc.allocate(1);
			node tmp(pair);
			_alloc.construct(_ptr, tmp);
			insertion_recursiv(_root, _ptr);
			insertion_repare_tree(_ptr);
			_root = _ptr;
			while (_root->parent() != NULL)
				_root = _root->parent();
			_n++;
			return _root;
		}

		private:

		Alloc _alloc;

		void insertion_recursiv(node * root, node * n) 
		{
			if (root != NULL && n->key_val()->first < root->key_val()->first) 
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
			n->setParent(root);
			n->setLeft(LEAF);
			n->setRight(LEAF);
			n->setColor(R);
		}
		void insertion_repare_tree(node * n) 
		{
			static int x = 0;
			if (n->parent() == NULL)
				insertion_case1(n);
			else if (n->parent() && n->parent()->color() == B)
				insertion_case2(n);
			else if (n->uncle() && n->uncle()->color() == R)
				insertion_case3(n);
			else
				insertion_case4(n);
		}
		void insertion_case1(node * n)
		{
			if (n->parent() == NULL)
				n->setColor(B);
		}
		void insertion_case2(node * n) { return; }
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
			if (g->left() && n == g->left()->right()) 
			{
				rotation_left(p);
				n = n->left();
			} 
			else if (g->right() && n == g->right()->left()) 
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
				_root = y;
			else
			{
				if (x->parent()->left() == x)
					x->parent()->setLeft(y);
				else
					x->parent()->setRight(y);
			}
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
				_root = y;
			else
			{
				if (x->parent()->right() == x)
					x->parent()->setRight(y);
				else
					x->parent()->setLeft(y);
			}
			y->setRight(x);
			x->setParent(y);
		}

		void free_tree(node * root)
		{
			if (root == NULL)
				return;
			free_tree(root->left());
			cout << "[FREE]: " << root->key_val()->first << endl;
			_n--;
			_alloc.destroy(root);
			_alloc.deallocate(root, 1);
			free_tree(root->right());
		}
		
		void print_tree(node *root, int space)
		{
			if (root == NULL)
				return;
			space += COUNT;
			print_tree(root->right(), space);
			cout<<endl;
			for (int i = COUNT; i < space; i++)
				cout<<" ";
			if (root->color() == 1)
			cout << RED;
			cout << root->key_val()->first << WHI;
			if (root->parent())
				cout << " ("<< root->parent()->key_val()->first << ")";
			cout << endl;
			print_tree(root->left(), space);
		}
	};
}

#endif

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

# define COUNT 8
# define RED "\033[0;31m"
# define WHI "\033[0m"

namespace ft
{	
	/* pré-déclaration */
	template < class Key, class T, 
	class Compare = less<Key>, 
	class Alloc = allocator< ft::pair< const Key,T> > >
	class map;
	/* obligé de déclarer la class-template avant pour que le friend dans rbt
	reconnaisse map */

	template<class Key, class T, class Comp, class Alloc_p, class Alloc = allocator< red_black_node<Key,T> > >
	class red_black_tree
	{
		friend class map<Key,T>;

		public:

		typedef	ft::pair<const Key,T>						value_type;
		typedef red_black_node<Key,T>						node;
		typedef	Alloc										allocator_type;
		typedef Comp										val_comp;
		typedef	typename allocator_type::reference			reference;
		typedef	typename allocator_type::const_reference	const_reference;
		typedef	typename allocator_type::pointer			pointer;
		typedef	typename allocator_type::const_pointer		const_pointer;
		typedef	unsigned int								size_type;
		typedef	int											difference_type;

		node * get_left_most(node * n) const
		{
			if (!n)
				return _past_end_ptr;
			while (n->left())
				n = n->left();
			return n;
		}
		node * get_right_most(node * n) const
		{
			if (!n)
				return _past_end_ptr;
			while (n->right())
				n = n->right();
			return n;
		}
		node * get_next(node *n) const
		{
			node * parent;
			if (!n)
				return _past_end_ptr;
			if (n->right())
				return get_left_most(n->right());
			else if (n->parent() && n == n->parent()->left())
				return n->parent();
			else if (n->parent())
			{
				parent = n->parent();
				while (parent != NULL && n == parent->right()) 
				{
					n = parent;
					parent = parent->parent();
					if (!parent)
						return _past_end_ptr;
				}
				return parent;
			}
			else
				return _past_end_ptr;	// que 1 val dans l'arbre, pas de next
		}
		node * get_prev(node *n) const
		{
			node * parent;
			if (!n)
				return _past_end_ptr;
			if (n == _past_end_ptr) // on est sur le past-end qui n'est pas dans l'arbre
				return get_right_most(_root);
			if (n->left())
				return get_right_most(n->left());
			else if (n->parent() && n == n->parent()->right())
				return n->parent();
			else if (n->parent())
			{
				parent = n->parent();
				while (parent != NULL && n == parent->left()) 
				{
					n = parent;
					parent = parent->parent();
					if (!parent)
						return _past_end_ptr;	// on est sur le min, pas de prev	!!!! INSTAURER UN PAST PREV
				}
				return parent;
			}
			else
				return _past_end_ptr;	// que 1 val dans l'arbre, pas de next		!!!! INSTAURER UN PAST PREV
		}

		private:

		size_type		_n;
		node *			_root;
		node *			_ptr;
		Alloc			_alloc;
		Alloc_p			_alloc_p;
		Comp			_comp;
		node *			_past_end_ptr;
		value_type *	_past_end_pair;

		red_black_tree(val_comp comp, const allocator_type & alloc = allocator_type()) : 
		_alloc(alloc), _comp(comp), _n(0), _root(NULL) 
		{
			_past_end_ptr = _alloc.allocate(1);
			node tmp(_past_end_pair);
			// _alloc.construct(_past_end_ptr, tmp);
		}
		
		~red_black_tree() {}

		node * search(Key key)
		{
			node * root = _root;
			while (root)
			{
				if (_comp.comp(key, root->key_val()->first))
				{
					if (root->left())
						root = root->left();
					else
						return NULL;
				}
				else if (_comp.comp(root->key_val()->first, key))
				{
					if (root->right())
						root = root->right();
					else
						return NULL;
				}
				else
					return root;
			}
			return NULL;
		}

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
			return _ptr;
		}
		void insertion_recursiv(node * root, node * n) 
		{
			if (root != NULL && _comp.comp(n->key_val()->first, root->key_val()->first)) 
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

		void print_tree()
		{
			cout << endl << "[PRINT RED BLACK TREE]" << endl;
			print_tree_recursiv(_root, 0);
			cout << endl;
		}
		void print_tree_recursiv(node *root, int space)
		{
			if (root == NULL)
				return;
			space += COUNT;
			print_tree_recursiv(root->right(), space);
			cout<<endl;
			for (int i = COUNT; i < space; i++)
				cout<<" ";
			if (root->color() == 1)
			cout << RED;
			cout << root->key_val()->first << WHI;
			if (root->parent())
				cout << " ("<< root->parent()->key_val()->first << ")";
			cout << endl;
			print_tree_recursiv(root->left(), space);
		}

		void free_tree()
		{
			cout << "[FREE RED BLACK TREE]" << endl;
			free_tree_recursiv(_root);
			_root = NULL;
			// _alloc_p.destroy(_past_end_ptr->key_val());
			// _alloc_p.deallocate(_past_end_ptr->key_val(), 1);
			_alloc.destroy(_past_end_ptr);
			_alloc.deallocate(_past_end_ptr, 1);
		}
		void free_tree_recursiv(node * root)
		{
			if (root == NULL)
				return;
			free_tree_recursiv(root->left());
			cout << "free pair containing " << root->key_val()->first << "-" << root->key_val()->second << endl;
			cout << "free red-black-node containing " << root->key_val()->first << " : " << root << endl;
			_n--;
			_alloc_p.destroy(root->key_val());
			_alloc_p.deallocate(root->key_val(), 1);
			_alloc.destroy(root);
			_alloc.deallocate(root, 1);
			free_tree_recursiv(root->right());
		}
	};
}

#endif

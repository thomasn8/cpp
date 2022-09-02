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
	/* obligé de déclarer la classe avant pour que le friend dans rbt fonctionne
	car red_black_tree.hpp est include dans map.hpp
	donc rbt ne connait pas encore map */

	template<class Key, class T, class AllocPair, class Alloc = allocator< red_black_node<Key,T> > >
	class red_black_tree
	{
		friend class map<Key,T>;

		public:

		typedef	ft::pair<const Key,T>						value_type;
		typedef red_black_node<Key,T>						node;
		typedef	Alloc										allocator_type;
		typedef	AllocPair									alloc_pair;
		typedef	typename allocator_type::reference			reference;
		typedef	typename allocator_type::const_reference	const_reference;
		typedef	typename allocator_type::pointer			pointer;
		typedef	typename allocator_type::const_pointer		const_pointer;
		typedef	unsigned int								size_type;
		typedef	int											difference_type;

		private:

		struct node_list2
		{
			value_type* ptr;
			node_list2* next;
			node_list2* prev;
			node_list2() : ptr(NULL), next(NULL), prev(NULL) {}
			~node_list2() {}
		};

		size_type		_n;
		node *			_root;
		node *			_ptr;
		node_list2		_first;
		node_list2		_last;
		node_list2*		_current;
		node_list2*		_prev;
		Alloc			_alloc;
		AllocPair		_allocPair;

		red_black_tree(const allocator_type & alloc = allocator_type()) : 
		_alloc(alloc), _allocPair(), _n(0), _root(NULL), _first(), _last(), _current(&_first), _prev(NULL) {}
		
		~red_black_tree() {}

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
		void print_tree()
		{
			if (_root)
			{
				cout << endl << "[PRINT TREE]" << endl;
				print_tree_recursiv(_root, 0);
				cout << endl << endl;
			}
		}
		void free_tree()
		{
			cout << "[FREE TREE]" << endl;
			free_tree_recursiv(_root);
			_root = NULL;
		}

		void create_node_list()
		{
			cout << endl << "[CREATE NODE LIST]" << endl;
			create_node_list_recursiv(_root);
			cout << &_last <<  "(_last node) contains : " << _last.ptr << endl << endl;
		}
		void print_node_list()
		{
			node_list2	*current;
			node_list2	*next;

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
			node_list2	*current;
			node_list2	*next;
			current = &_first;
			while (current->ptr)
			{
				next = current->next;
				// _allocPair.destroy(current->ptr);
				// _allocPair.deallocate(current->ptr, 1);
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
		void free_tree_recursiv(node * root)
		{
			if (root == NULL)
				return;
			free_tree_recursiv(root->left());
			cout << "free red-black-node containing " << root->key_val()->first << " : " << root << endl;
			_n--;
			// _allocPair.destroy(root->key_val());
			// _allocPair.deallocate(root->key_val(), 1);
			_alloc.destroy(root);
			_alloc.deallocate(root, 1);
			free_tree_recursiv(root->right());
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
				_current = new node_list2();

				_current->ptr = root->key_val();
				_current->prev = _prev;
				_current->next = &_last;

				_prev->next = _current;
				_last.prev = _current;
				cout << "create node containing " << root->key_val()->first << " : " << _current << endl;
			}
			create_node_list_recursiv(root->right());
		}
	};
}

#endif

/* 
	Internally, vectors use a dynamically allocated array to store their elements. This array may need to be reallocated in order to grow in size when new elements are inserted, which implies allocating a new array and moving all elements to it. This is a relatively expensive task in terms of processing time, and thus, vectors do not reallocate each time an element is added to the container.
*/

#include <memory>
#include <iostream>
#include "ft_typedefs.hpp"

using namespace std;

/* 

range (3)	
template <class InputIterator>
         vector (InputIterator first, InputIterator last,
                 const allocator_type& alloc = allocator_type());

copy (4)	
vector (const vector& x);
*/
namespace ft
{
	template <typename T>
	class vector
	{
		public :

			typedef T value_type;

			vector<T>(size_type n, const value_type & val) : _n(n)		// allouer + d'espace que "n" pour gérer dynamiquement la mémoire ???
			{															// et faire les réallocations dès que l'espace est rempli ???
				this->_vector = new T[n];
				for (size_type i = 0; i < n; i++)
					this->_vector[i] = val;
				cout << "(" << this << " - value) Sized vector created" << endl;
			}

			vector<T>()
			{
				this->_vector = NULL;
				cout << "(" << this << " - default) Null vector created" << endl;
			}

			virtual ~vector<T>()
			{
				cout << "(" << this << " - default) vector destroyed" << endl;
			}

		private :

			std::allocator _mem;
	};
}
/* 
	Internally, vectors use a dynamically allocated array to store their elements. This array may need to be reallocated in order to grow in size when new elements are inserted, which implies allocating a new array and moving all elements to it. This is a relatively expensive task in terms of processing time, and thus, vectors do not reallocate each time an element is added to the container.
*/

#include <memory>
#include <iostream>
#include <iterator>

# define RED "\033[0;31m"
# define WHI "\033[0m"

using namespace std;

namespace ft
{
	template <typename T, typename Alloc = allocator<T> >
	class vector
	{
		public :

		// MEMBER TYPES
			typedef T 											value_type;			// le type de donné inséré dans le container
			typedef unsigned int size_type;											// can represent any non-negative value of difference_type

			typedef allocator<T> 								allocator_type;		// l'allocateur par défault
			typedef typename allocator_type::reference 			reference;			// T & -> Reference to element
			typedef typename allocator_type::const_reference 	const_reference;	// const T& -> Reference to constant element
			typedef	typename allocator_type::pointer 			pointer;			// T * Pointer to element
			typedef	typename allocator_type::const_pointer 		const_pointer;		// const T * Pointer to constant element
			
			typedef int											difference_type;	// Difference between two pointers (a signed integral type), identical to: iterator_traits<iterator>::difference_type /

			// typedef a random access iterator to value_type	iterator;
			// typedef a random access iterator to const value_type const_iterator;
			// typedef reverse_iterator<iterator> 			reverse_iterator;
			// typedef reverse_iterator<const_iterator> 			const_reverse_iterator;

		// ITERATORS
			class iterator : public std::iterator<std::random_access_iterator_tag, T>
			{
				private:
					T * _p;
				
				public:
				// CONSTRUCTEURS/DESTRUCTEUR
					iterator() : _p(0) {cout << "Iterator default" << endl;}																// default
					iterator(T * x) : _p(x) {cout << "Iterator pointer" << endl;}															// special
					iterator(const iterator & it) : _p(it._p) {cout << "Iterator copy" << endl;}											// copy
					iterator & operator=(iterator const & src) { this->_p = src.getP(); return *this; cout << "Iterator assign" << endl;} 	// assign 
					~iterator() { cout << "Iterator destruction" << endl;}
				// ACCESSORS
					T * getP() const { return this->_p; }

				// SURCHARGES
					iterator& operator++() { ++this->_p; return *this; }
					iterator operator++(T) { iterator tmp(*this); this->_p++; return tmp; }
					iterator & operator--() { --this->_p; return *this; }
					iterator operator--(T) { iterator tmp(*this); this->_p--; return tmp; }
					bool operator==(const iterator & rhs) const { return this->_p == rhs._p; }
					bool operator!=(const iterator & rhs) const { return this->_p != rhs._p; }
					bool operator<(const iterator & rhs) const { return this->_p < rhs._p; }
					bool operator<=(const iterator & rhs) const { return this->_p <= rhs._p; }
					bool operator>(const iterator & rhs) const { return this->_p > rhs._p; }
					bool operator>=(const iterator & rhs) const { return this->_p >= rhs._p; }
					T & operator[](unsigned int index) { return this->_p[index]; }	
					int & operator*() { return *_p; }
					// *a++ Two iterators that compare equal, keep comparing equal after being both increased.
					// *a-- Can be decremented (if a dereferenceable iterator value precedes it).
					// ARITHMETIC
					// a + n
					// n + a
					// a - n
					// a - b
					// a += n
					// a -= n
			};

		iterator begin() { iterator it(this->_first); return it; };
		iterator end() { iterator ite(++this->_last); return ite; };

		// CONSTRUCTEURS/DESTRUCTEUR

			/*	(3) range constructor :

				Prototype :
				vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()); 
			*/
			// template <typename InputIterator>
			// vector<T>(InputIterator first, InputIterator last)
			vector<T>(iterator first, iterator last)
			{
				// InputIterator first_cpy = first;
				iterator first_cpy = first;
				size_type n = 0;
				while (++first_cpy != last)
					++n;
				this->_pointer = this->get_allocator().allocate(n + 1);
				this->_first = this->_pointer;
				while (first != last)
				{
					this->get_allocator().construct(this->_pointer, *first);
					++first;
					this->_pointer++;
				}
				this->_pointer--;
				this->_last = this->_pointer;
				cout << "(" << this << " - range) vector created" << endl;
			}

			vector<T>(size_type n, const value_type & val) : _n(n)
			{
				this->_pointer = this->_alloc.allocate(n);					// créer un objet T pour le copier n fois, puis détruit l'objet de base
				this->_first = this->_pointer;
				for (size_type i = 0; i < n; i++)
				{
					this->_alloc.construct(this->_pointer, val+i);			// utilise l'objet créé pour Construire les instances par copie
					this->_pointer++;
				}
				this->_pointer--;
				this->_last = this->_pointer;
				cout << "(" << this << " - size) vector created" << endl;	// l'objet initial créé par allocate() est détruit en sortie de fonction
			}
			
			vector<T>() : _n(0)
			{
				this->_first = 0;
				cout << "(" << this << " - null) vector created" << endl;
			}

			virtual ~vector<T>()
			{
				cout << "(" << this << " - default) vector destroyed" << endl;
			}

		// ELEMENT ACCESS:
			reference front() { return *this->_first; }
			const_reference front() const { return *this->_first; }
			reference back() { return *this->_last; }
			const_reference back() const { return *this->_last; }

		// SURCHARGES
			reference operator*() const			{ return *this->_first; }
			T * operator&() const			{ return &this->_first; }
			reference operator[](size_type index)	{ return this->_first[index]; }

		// ALLOCATOR
			allocator_type get_allocator() const { return this->_alloc; }


		private :

			allocator_type	_alloc;
			size_type		_n;
			T *				_first;	
			T *				_last;
			T *				_pointer;
			
			size_type _difference_type() const
			{
				return sizeof(T);
			}
	};

	template <typename T>
	ostream	& operator<<(ostream & o, ft::vector<T> const & inst)
	{
		cout << &inst.front();
		return o;
	}
}
